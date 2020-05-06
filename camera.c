#include "cube3d.h"
#include "mlx.h"


void    cam_setdata(t_camera *camdata, t_initstyle *styledata)
{
    camdata->x = styledata->r_res[0];
    camdata->y = styledata->r_res[1];
}

// int     drawline(int x1, int y1, int x2, int y2, void *mlx_ptr,
//         void *win_ptr, int color)
// {
//     int dx; 
//     int dy; 
//     float pk; 

//     if(x1 == 285)
//         puts("oof");
//     dx = x2 - x1; 
//     dy = y2 - y1; 
//     pk = 2 * dy -dx;

//     while(x1<=x2)
//     {
//         mlx_pixel_put(mlx_ptr, win_ptr, x1,y1, color);
//         if(pk < 0)
//             pk += 2 * dy; 
//         else 
//         {
//             ++y1; 
//             pk += 2 * (dy-dx); 
//         }
//         ++x1; 
//     } 
//     return (0); 
// }

int     drawline(int x1, int y1, int x2, int y2, void *mlx_ptr,
        void *win_ptr, int color)
{

    while(y1 < y2)
    {
        mlx_pixel_put(mlx_ptr,win_ptr,x1,y1,color);
        y1++;
    }
    return (0);

}

// void      drawwalls(t_cameras *camdata, t_initstyle *styledata)
// {
//     int pix; 

//     pix = 0;
//     while()
// }