#include "cube3d.h"



// int ft_close(t_mlx *print)
// {
//     int i; 

//     while(print->mapchar[i])
//     {
//         free(print->mapchar[i]);
//         i++; 
//     }
//     mlx_destroy_window(print->mlx_ptr, print->win); 
//     mlx_destroy_image(print->mlx_ptr, print->img.img_ptr); 
//     free(print->mlx_ptr);
//     free(print->confstyle.t_patheast); 
//     free(print->confstyle.t_pathnord);
//     free(print->confstyle.t_pathsouth); 
//     free(print->confstyle.t_pathwest); 
//     free(print->confstyle.t_pathsprite); 
//     exit(0);  
//     return (0); 
// }

int   ft_onward(t_mlx *print)
{
    if(print->mapchar[(int)(print->raycast.posY + print->raycast.dirY * 0.10)][(int)print->raycast.posX] != '1')
        print->raycast.posY += print->raycast.dirY * 0.20; 
    if(print->mapchar[(int)print->raycast.posY][(int)(print->raycast.posX + print->raycast.dirX * 0.10)] != '1')
        print->raycast.posX += print->raycast.dirX * 0.20; 
    ft_bzero(print->img.data, print->raycast.w * print->raycast.h * 4);
    ft_drawwalls(print);  
    return (1);

}

int  ft_onright(t_mlx *print)
{
    double temp; 
    double tempPlaneX; 

    temp= print->raycast.dirX; 
    tempPlaneX = print->raycast.planeX;
    print->raycast.dirX = print->raycast.dirX * cos(-0.10) - print->raycast.dirY * sin(-0.10); 
    print->raycast.dirY = temp * sin(-0.10) + print->raycast.dirY * cos(-0.10); 
    temp = print->raycast.planeX; 
    print->raycast.planeX = print->raycast.planeX * cos(-0.10) - print->raycast.planeY * sin(-0.10); 
    print->raycast.planeY = temp * sin(-0.10) + print->raycast.planeY * cos(-0.10); 
    ft_bzero(print->img.data, print->raycast.w * print->raycast.h * 4); 
    ft_drawwalls(print); 
    return (1);
}

int ft_onleft(t_mlx *print)
{
    double temp; 
    double tempPlaneX; 

    temp= print->raycast.dirX; 
    tempPlaneX = print->raycast.planeX;
    print->raycast.dirX = print->raycast.dirX * cos(0.10) - print->raycast.dirY * sin(0.10); 
    print->raycast.dirY = temp * sin(0.10) + print->raycast.dirY * cos(-0.10); 
    temp = print->raycast.planeX; 
    print->raycast.planeX = print->raycast.planeX * cos(0.10) - print->raycast.planeY * sin(0.10); 
    print->raycast.planeY = temp * sin(0.10) + print->raycast.planeY * cos(0.10); 
    ft_bzero(print->img.data, print->raycast.w * print->raycast.h * 4);
    ft_drawwalls(print);  
    return (1);
}

int ft_forward(t_mlx *print)
{
    if(print->mapchar[(int)(print->raycast.posY + print->raycast.dirY * 0.20)][(int)print->raycast.posX] != '1')
        print->raycast.posY -= print->raycast.dirY * 0.20; 
    if(print->mapchar[(int)print->raycast.posY][(int)(print->raycast.posX + print->raycast.dirX * 0.20)] != '1')
        print->raycast.posX -= print->raycast.dirX * 0.20; 
    ft_bzero(print->img.data, print->raycast.w * print->raycast.h * 4);
    ft_drawwalls(print);  
    return (1);
}

int g_is_up_pressed = 0;

int    keycode(int key, void *bidule)
{
    int put;
   
    if(key == ESC)
        ft_close(bidule, ALL); 
    if(key == UP) // g_is_up_pressed = 1;
        ft_onward(bidule); 
    if(key == DOWN)
        ft_forward(bidule); 
    if(key == LEFT)
        ft_onleft(bidule);
    if(key == RIGHT)
        ft_onright(bidule);
    //ft_drawwalls(bidule); 
    return(1);
}