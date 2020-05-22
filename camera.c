#include "cube3d.h"
#include "mlx.h"

int     drawline(int x, int y1, int y2, t_mlx *print , unsigned int color)
{

    while(y1 < y2)
    {
       // if(x % 2)
            print->img.data[y1 * print->raycast.w + x] = color; 
    //    else 
    //        print->img.data[y1 * print->raycast.w + x] = 0; 
        y1++;
    }
    return (0);
}

