#include "cube3d.h"
#include "mlx.h"



int     drawline(int x, int y1, int y2, t_mlx *print , int color)
{
    while(y1 < y2)
    {
    //    if(x % 2)
            // print->raycast.hline = fabs((int)(print->raycast.h / print->raycast.perpWallDist));
            // print->raycast.texy = (y1 * 2 - print->raycast.h + print->raycast.hline) * (print->texteast.img_weight / 2) / print->raycast.hline;
            // color = print->texteast.data[print->texteast.t_size / 4 * (int)print->raycast.texy + (int)print->raycast.texx];
            print->img.data[y1 * print->raycast.w + x] = color; 
    //    else 
    //        print->img.data[y1 * print->raycast.w + x] = 0; 
        y1++;
    }
    return (0);
}


int     drawall(int x, int y1, int y2, t_mlx *print)
{
    int color;
    int i = 0;

    while(y1 <= y2)
    {
    //    if(x % 2)
            print->raycast.hline = abs((int)(print->raycast.h / print->raycast.perpWallDist));
            print->raycast.texy = (y1 * 2 - print->raycast.h + print->raycast.hline) * (print->texteast.img_weight / 2) / print->raycast.hline;
            //print->raycast.texy = 64 * floor(64 * y1) + 64 * (print->raycast.hline - floor(print->raycast.h)) ;
            //color = print->texteast.data[print->texteast.img_weight * (int)print->raycast.texy + (int)print->raycast.texx]; 
            color = print->texteast.data[print->texteast.t_size / 4 * (int)print->raycast.texy + (int)print->raycast.texx];
            //print->img.data[y1 * print->raycast.w + x] = color; 
            print->img.data[y1 * print->confstyle.r_res[0]+ x] = color;
    //    else 
    //        print->img.data[y1 * print->raycast.w + x] = 0; 
        y1++;
        i++;
    }
    return (0);
}


// int     drawall(int x, int y1, int y2, t_mlx *print)
// {
//     int color;
//     int i = 0;
//     int textnum = print->mapchar[(int)print->raycast.posY][(int)print->raycast.posX] - 48; 
//     double wallX; 
//     int texX;
//     int y = print->raycast.drawStart;  

//     if(print->raycast.side == 0)
//         wallX = print->raycast.posY + print->raycast.perpWallDist * print->raycast.rayDirY; 
//     else
//         wallX = print->raycast.posX + print->raycast.perpWallDist * print->raycast.rayDirY; 
//     if(print->raycast.side == 0 && print->raycast.rayDirX > 0)
//         texX = print->texteast.img_width - texX *1 ; 
//     if(print->raycast.side == 1 && print->raycast.rayDirX < 0)
//         texX = print->texteast.img_width - texX *1 ; 
//     double step = 1.0 * print->texteast.img_weight / print->raycast.lineHeight; 
//     double texPos = (print->raycast.drawStart - print->raycast.h / 2 + print->raycast.lineHeight / 2) * step;
//     ft_printf("this is and texx %d\n",  texX);

//     while (y < y2)
//     {
//         int texY = texX & (print->texteast.img_weight); 
//         texPos += step; 
//         color = print->texteast.data[print->texteast.img_weight * texY + texX]; 
//            // ft_printf("text num is %d\n", color);


        

//         // if (print->raycast.side == 1)
//         //color = (color >> 1) & 8355711;
//         print->img.data[y * print->raycast.w + x] = color; 
//         y++; 
//     }
//     return (0);
// }