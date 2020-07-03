#include "cube3d.h"



void ft_close_path(t_mlx *data)
{
    if(data->confstyle.t_patheast != NULL)
        free(data->confstyle.t_patheast);
    if(data->confstyle.t_pathwest != NULL)
        free(data->confstyle.t_pathwest);
    if(data->confstyle.t_pathnord != NULL)
        free(data->confstyle.t_pathnord);
    if(data->confstyle.t_pathsouth != NULL)
        free(data->confstyle.t_pathsouth);
    if(data->confstyle.t_pathsprite != NULL)
        free(data->confstyle.t_pathsprite);
}
// POSSIBLE LEAKS (FREE PAS PROPRE)
void    ft_close_inside_map(char **mapinside, t_initstyle *style)
{
     int y; 

    y = 0;
    if(mapinside[y] != NULL)
        free(mapinside);
    if(style->t_patheast != NULL)
        free(style->t_patheast);
    if(style->t_pathwest != NULL)
        free(style->t_pathwest);
    if(style->t_pathnord != NULL)
        free(style->t_pathnord);
    if(style->t_pathsouth != NULL)
        free(style->t_pathsouth);
    if(style->t_pathsprite != NULL)
        free(style->t_pathsprite);
    ft_printf("BAD MAPPING\n");
    exit(-1);

}

void    ft_close_map(t_mlx *data)
{
    int y; 

    y = 0;
    while(ft_strlen(data->mapchar[y]) != 0)
    {
        free(data->mapchar[y]);
        y++;
    }
}

void    ft_close_other(t_mlx *data)
{
    if(data->confstyle.nbsprite > 0)
        free(data->raycast.ZBuffer);
    
}

int ft_close(t_mlx *data, int bad)
{
 
    if(bad == BADMAP)
    {
        ft_close_path(data); 
        ft_close_map(data);
        mlx_destroy_window(data->mlx_ptr, data->win); 

    }
    if(bad == BADPATH)
    {
        ft_close_path(data);
        ft_close_map(data);
        mlx_destroy_window(data->mlx_ptr, data->win); 
        ft_printf("ERROR OPENNING TEXTURE\n");
        exit(-1);

    }
    if(bad == BADARGUM)
    {
        ft_close_path(data);
        ft_printf("BAD ARGUMENTS\n");
        exit(-1);
  
    }
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







