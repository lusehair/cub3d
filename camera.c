#include "cube3d.h"
#include "mlx.h"



int     drawline(int x, int y1, int y2, t_mlx *print , int color)
{
    while(y1 < y2) 
    {
   
            //if (print->img.data[y1 * print->raycast.w + x])
                print->img.data[y1 * print->raycast.w + x] = color; 
            y1++;
    }
    return (0);
}

t_texture   selecwall(t_mlx *print)
{

    t_texture   texture; 

    if(print->raycast.side == 0 && print->raycast.rayDirX > 0)
        texture = print->texteast; 
    else if(print->raycast.side == 0 && print->raycast.rayDirX  < 0)
        texture = print->textwest; 
    else if(print->raycast.side == 1 && print->raycast.rayDirY > 0)
        texture = print->textnorth; 
    else
        texture = print->textsouth;
    return(texture); 
}

int     drawall(int x, int y1, int y2, t_mlx *print)
{
    unsigned int color;
    int i;
    t_texture text; 

    i = y1;
    text = selecwall(print); 
    print->raycast.wall_x -= floor((print->raycast.wall_x));
    print->raycast.texx = print->raycast.wall_x * text.img_width;
    while(y1 < y2)
    {
        print->raycast.hline = abs((int)(print->raycast.h / print->raycast.perpWallDist));
        print->raycast.texy = (y1 * 2 - print->raycast.h + print->raycast.hline) * (64 / 2) / print->raycast.hline;
        color = text.data[text.t_size / 4 * (int)print->raycast.texy + (int)print->raycast.texx];
        print->img.data[y1 * print->confstyle.r_res[0]+ x] = color; 
        y1++;
    }
    return (0);
}
