#include "cube3d.h"


void	ft_opentexturebis(t_mlx *print)
{
	print->textsouth.data = (int *)mlx_get_data_addr(print->textsouth.img, 
	&print->img.bpp, &print->textsouth.t_size, &print->img.endian);
	if ((print->textwest.img = mlx_xpm_file_to_image(print->mlx_ptr, 
	print->confstyle.t_pathwest, &print->textwest.img_width, 
	&print->textwest.img_weight)) == NULL)
		ft_close(print, BADPATH);
	print->textwest.data = (int *)mlx_get_data_addr(print->textwest.img, 
	&print->img.bpp, &print->textwest.t_size, &print->img.endian);
	if ((print->textsprite.img = mlx_xpm_file_to_image(print->mlx_ptr, 
	print->confstyle.t_pathsprite, &print->textsprite.img_width, 
	&print->textsprite.img_weight)) == NULL)
		ft_close(print, BADPATH);
	print->textsprite.data = (int *)mlx_get_data_addr(print->textsprite.img, 
	&print->img.bpp, &print->textsprite.t_size, &print->img.endian);
}

void	ft_opentexture(t_mlx *print)
{
	if ((print->texteast.img = mlx_xpm_file_to_image(print->mlx_ptr, 
	print->confstyle.t_patheast, &print->texteast.img_width, 
	&print->texteast.img_weight)) == NULL)
		ft_close(print, BADPATH);
	print->texteast.data = (int *)mlx_get_data_addr(print->texteast.img, 
	&print->img.bpp, &print->texteast.t_size, &print->img.endian);
	if ((print->textnorth.img = mlx_xpm_file_to_image(print->mlx_ptr, 
	print->confstyle.t_pathnord, &print->textnorth.img_width, 
	&print->textnorth.img_weight)) == NULL)
		ft_close(print, BADPATH);
	if ((print->textnorth.data = (int *)mlx_get_data_addr(print->textnorth.img,
	&print->img.bpp, &print->textnorth.t_size, &print->img.endian)) == NULL)
		ft_close(print, BADPATH);
	if ((print->textsouth.img = mlx_xpm_file_to_image(print->mlx_ptr, 
	print->confstyle.t_pathsouth, &print->textsouth.img_width, 
	&print->textsouth.img_weight)) == NULL)
		ft_close(print, BADPATH);
	ft_opentexturebis(print);
}
