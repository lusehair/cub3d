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
    int i = y1;
    t_texture text; 

    text = selecwall(print); 


        print->raycast.wall_x -= floor((print->raycast.wall_x));

        print->raycast.texx = print->raycast.wall_x * text.img_width;
        // if (print->raycast.side == 0 && print->raycast.rayDirX > 0)
        //     print->raycast.texx =  text.img_width - print->raycast.texx - 1;
        // if (print->raycast.side == 1 && print->raycast.rayDirX < 0)
        //   print->raycast.texx =  text.img_width - print->raycast.texx - 1;
        


	// if (side == 0 && raydirX > 0)
	// 	texx = img_width - texx - 1;
	// if (side == 1 && raydirY < 0)
	// 	texx = img_width - texx - 1;

    while(y1 < y2)
    {
    //    if(x % 2)]
            print->raycast.hline = abs((int)(print->raycast.h / print->raycast.perpWallDist));
            print->raycast.texy = (y1 * 2 - print->raycast.h + print->raycast.hline) * (64 / 2) / print->raycast.hline;
     
            //color = print->texteast.data[print->texteast.img_weight * (int)print->raycast.texy + (int)print->raycast.texx]; 
            color = text.data[text.t_size / 4 * (int)print->raycast.texy + (int)print->raycast.texx];
            print->img.data[y1 * print->confstyle.r_res[0]+ x] = color; 


    //    else 
    //        print->img.data[y1 * print->raycast.w + x] = 0; 
        y1++;
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