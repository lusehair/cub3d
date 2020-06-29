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