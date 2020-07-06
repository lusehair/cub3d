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

void    ft_close_sprite(t_mlx *data)
{
    if(data->confstyle.nbsprite > 0)
    {
        free(data->raycast.sprites); 
        free(data->raycast.spriteOrder);
        free(data->raycast.ZBuffer);
    }
}

void    ft_close_map(t_mlx *data)
{
    int y; 

    y = 0;
    while(y <= data->confstyle.longmap)
    {
        free(data->mapchar[y]);
        y++;
    }
}

int    ft_closehook(int key, void *data)
{
    ft_close(data, GOODBYE);
    return (0);
}

int ft_close(t_mlx *data, int bad)
{
 
    if(bad == GOODBYE)
    {
        ft_putstr("Goodbye, See you soon !\n");
        ft_close_map(data);
        ft_close_path(data);
        ft_close_sprite(data);
        mlx_destroy_image(data->mlx_ptr, data->img.img_ptr); 
        mlx_destroy_window(data->mlx_ptr, data->win); 
        exit(0);
    }
    if(bad == BADMAP)
    {
        ft_putstr("Bad Mapping. Sorry ...\n");
        ft_close_path(data); 
        ft_close_map(data);
        //mlx_destroy_window(data->mlx_ptr, data->win); 
        exit(-1);

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


// 111111111111111111
// 111111000000001111
// 100001110000000W11
// 100001111110000001
// 100000000000020001
// 100001110000000001
// 10000110000000001
// 100000000000000001
// 10000000000000000011111111
// 10000001100002000000000001
// 10000101100000000001110001
// 10001010000000011000000001
// 10001010000000000000000001
// 111111 11111111111111111111

// 111111111111111111111
// 100000000000000000001
// 100000000000000000001
// 100000000000000000001
// 10000000000000000000111111111
// 10000000000000000000000000001
// 1000000000000000000000000001
// 1000000000000000S000000000001
// 11111111111111111111100000001
// 11111111111111111111100000001
// 11111111111111111111100000001
// 11111111111111111111100000001
// 11111111111111111111100000001
// 11111111111111111111100000001
// 11111111111110111111111111111



//         1111111111111111111111111
//         1000000000110000000000001
//         1011000001110000002000001
//         1001000000000000000000001
// 111111111011000001110000000000001
// 100000000011000001110111111111111
// 11110111111111011100000010001
// 11110111111111011101010010001
// 11000000110101011100000010001
// 10002000000000001100000010001
// 10000000000000001111010010001
// 1100000111010101111011110N0111
// 11110111 1110101 101111010001
// 11111111 1111111 11111111111

//     1111111111111111111111111111111
//     1000000000000000000000000000001
//     1000000000000000000000000000001
// 11111000000000000000000000000001111
// 10000000000000N0000000000000001
// 1000000000100000000000000000001
// 1000000001 10000000000000000001
// 1000000001 10000000000000000001
// 1111111111 11111111111111111111


// distance de securite pour la rotation pres dun mur 
// checker 





