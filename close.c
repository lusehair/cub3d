#include "cube3d.h"





int ft_close(t_mlx *print)
{
    int i; 

    while(print->mapchar[i])
    {
        free(print->mapchar[i]);
        i++; 
    }
    mlx_destroy_window(print->mlx_ptr, print->win); 
    //free(print->mlx_ptr);
    free(print->confstyle.t_patheast); 
    free(print->confstyle.t_pathnord);
    free(print->confstyle.t_pathsouth); 
    free(print->confstyle.t_pathwest); 
    free(print->confstyle.t_pathsprite);
    // free(print->img.data);
    // free(print->img.img_ptr); 
    // free(print->textsprite.data); 
    // free(print->texteast.data);
    // free(print->textnorth.data);
    // free(print->textsouth.data);
    // free(print->textsprite.data);
    // free(print->textwest.data);
    // free(print->raycast.spriteDistance);
    // free(print->raycast.spriteOrder);
    // free(print->raycast.ZBuffer);
    // exit(0);  
    return (0); 
}

// 111111111110111111
// 100011000001001111
// 100001110000000001
// 100001111110000001
// 100000000000000001
// 100001110000000001
// 1000011000000000W1
// 1000000   00000001
// 10000000000000000011111111
// 10000001100000000000000001
// 10000001100000000001110001
// 10000000000000011000000001
// 10000 00000000000000000001
// 11111111111111111111111111







