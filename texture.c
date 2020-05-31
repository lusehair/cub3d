#include "cube3d.h"


int     ft_opentexture(t_mlx *print)
{
    if ((print->texteast.img = mlx_xpm_file_to_image(print->mlx_ptr, print->confstyle.t_patheast, &print->texteast.img_width, &print->texteast.img_weight)) == NULL)
        return(-1);
        
    print->texteast.data = (int *)mlx_get_data_addr(print->texteast.img, &print->img.bpp,
		&print->texteast.t_size, &print->img.endian);
    // if (print->textwest.img = mlx_xpm_file_to_image(print->mlx_ptr, print->confstyle.t_pathwest, print->textwest.img_width, print->textwest.img_weight) == NULL)
    //     return (-1); 
    // if (print->textnorth.img = mlx_xpm_file_to_image(print->mlx_ptr, print->confstyle.t_pathnord, print->textnorth.img_width, print->textnorth.img_weight) == NULL)
    //     return (-1);
    // if (print->textsouth.img = mlx_xpm_file_to_image(print->mlx_ptr, print->confstyle.t_pathsouth, print->textsouth.img_width, print->textsouth.img_weight) == NULL)
    //     return (-1);
    return (0);
}