#include "cube3d.h"

int   ft_onward(t_mlx *print)
{
    if(print->mapchar[(int)(print->raycast.posY + print->raycast.dirY * 0.10)][(int)print->raycast.posX] != '1')
        print->raycast.posY += print->raycast.dirY * 0.10; 
    if(print->mapchar[(int)print->raycast.posY][(int)(print->raycast.posX + print->raycast.dirX * 0.10)] != '1')
        print->raycast.posX += print->raycast.dirX * 0.10; 
    ft_bzero(print->img.data, print->raycast.w * print->raycast.h * 4);
    ft_drawwalls(print);  
    return (1);

}

int ft_checkray(int x, int y, t_mlx *print)
{
    if(print->mapchar[x][y] == '1')
        return (-1);
    else
        return (0);

}

void    ft_left(t_mlx *print)
{
    if(print->mapchar[(int)print->raycast.posY][(int)(print->raycast.posX - print->raycast.planeX * 0.07)] != '1')
        print->raycast.posX = print->raycast.posX - print->raycast.planeX * 0.07;
    if(print->mapchar[(int)(print->raycast.posY - print->raycast.planeY * 0.07)][(int)print->raycast.posX ] != '1')
        print->raycast.posY = print->raycast.posY - print->raycast.planeY * 0.07;
    ft_bzero(print->img.data, print->raycast.w * print->raycast.h * 4); 
    ft_drawwalls(print); 

}

void    ft_right(t_mlx *print)
{
if(print->mapchar[(int)print->raycast.posY][(int)(print->raycast.posX + print->raycast.planeX * 0.07)] != '1')
        print->raycast.posX = print->raycast.posX + print->raycast.planeX * 0.07;
    if(print->mapchar[(int)(print->raycast.posY + print->raycast.planeY * 0.07)][(int)print->raycast.posX] != '1')
        print->raycast.posY = print->raycast.posY + print->raycast.planeY * 0.07;
    ft_bzero(print->img.data, print->raycast.w * print->raycast.h * 4); 
    ft_drawwalls(print); 
}

int  ft_onright(t_mlx *print)
{
    double temp; 
    double tempPlaneX;
    double dist; 
    temp= print->raycast.dirX; 
    tempPlaneX = print->raycast.planeX;
    print->raycast.dirX = print->raycast.dirX * cos(-0.06) - print->raycast.dirY * sin(-0.06); 
    print->raycast.dirY = temp * sin(-0.06) + print->raycast.dirY * cos(-0.06); 
    temp = print->raycast.planeX;
    print->raycast.planeX = print->raycast.planeX * cos(-0.06) - print->raycast.planeY * sin(-0.06); 
    print->raycast.planeY = temp * sin(-0.06) + print->raycast.planeY * cos(-0.06); 
 

    ft_bzero(print->img.data, print->raycast.w * print->raycast.h * 4); 
    ft_drawwalls(print); 
    return (1);
}

int ft_onleft(t_mlx *print)
{
    double temp; 
    double tempPlaneX; 
    double dist;

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
    if(print->mapchar[(int)(print->raycast.posY + print->raycast.dirY * 0.10)][(int)print->raycast.posX] != '1')
        print->raycast.posY -= print->raycast.dirY * 0.10; 
    if(print->mapchar[(int)print->raycast.posY][(int)(print->raycast.posX + print->raycast.dirX * 0.10)] != '1')
        print->raycast.posX -= print->raycast.dirX * 0.10; 
    ft_bzero(print->img.data, print->raycast.w * print->raycast.h * 4);
    ft_drawwalls(print);  
    return (1);
}

int g_is_up_pressed = 0;

int    keycode(int key, void *bidule)
{
    int put;
    ft_printf("The key : %d\n", key);
   
    if(key == ESC)
        ft_close(bidule, GOODBYE); 
    if(key == UP) // g_is_up_pressed = 1;
        ft_onward(bidule); 
    if(key == DOWN)
        ft_forward(bidule); 
    if(key == LEFT)
        ft_onleft(bidule);
    if(key == RIGHT)
        ft_onright(bidule);
    if(key == TURNRIGHT)
        ft_right(bidule);
    if(key == TURNLEFT)
        ft_left(bidule);
    //ft_drawwalls(bidule); 
    return(1);
}