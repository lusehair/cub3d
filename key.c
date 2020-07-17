#include "cube3d.h"

// int   ft_onward(t_mlx *print)
// {
//     if(print->mapchar[(int)(print->raycast.posY + print->raycast.dirY * 0.10)][(int)print->raycast.posX] != '1')
//         print->raycast.posY += print->raycast.dirY * 0.10; 
//     if(print->mapchar[(int)print->raycast.posY][(int)(print->raycast.posX + print->raycast.dirX * 0.10)] != '1')
//         print->raycast.posX += print->raycast.dirX * 0.10; 
//     ft_bzero(print->img.data, print->raycast.w * print->raycast.h * 4);
//     ft_drawwalls(print);  
//     return (1);

// }

int ft_onward(t_mlx *print)
{
    if (print->mapchar[(int)print->raycast.posY]
		[(int)(print->raycast.posX + print->raycast.dirX
		* 0.03)] != '1')
		print->raycast.posX += print->raycast.dirX
		* 0.03;
	if (print->mapchar[(int)(print->raycast.posY
		+ print->raycast.dirY * 0.03)]
		[(int)print->raycast.posX] != '1')
		print->raycast.posY += print->raycast.dirY * 0.03;
    //ft_bzero(print->img.data, print->raycast.w * print->raycast.h * 4);
    //ft_drawwalls(print);  
    return (0);
}

void    ft_left(t_mlx *print)
{
    if(print->mapchar[(int)print->raycast.posY][(int)(print->raycast.posX - print->raycast.planeX * 0.03)] != '1')
        print->raycast.posX = print->raycast.posX - print->raycast.planeX * 0.03;
    if(print->mapchar[(int)(print->raycast.posY - print->raycast.planeY * 0.03)][(int)print->raycast.posX ] != '1')
        print->raycast.posY = print->raycast.posY - print->raycast.planeY * 0.03;
    //ft_bzero(print->img.data, print->raycast.w * print->raycast.h * 4); 
    //ft_drawwalls(print); 

}

void    ft_right(t_mlx *print)
{
if(print->mapchar[(int)print->raycast.posY][(int)(print->raycast.posX + print->raycast.planeX * 0.03)] != '1')
        print->raycast.posX = print->raycast.posX + print->raycast.planeX * 0.03;
    if(print->mapchar[(int)(print->raycast.posY + print->raycast.planeY * 0.03)][(int)print->raycast.posX] != '1')
        print->raycast.posY = print->raycast.posY + print->raycast.planeY * 0.03;
    //ft_bzero(print->img.data, print->raycast.w * print->raycast.h * 4); 
    //ft_drawwalls(print); 
}

int  ft_onright(t_mlx *print)
{
    double temp; 
    double tempPlaneX;
   
    temp= print->raycast.dirX; 
    tempPlaneX = print->raycast.planeX;
    print->raycast.dirX = print->raycast.dirX * cos(-0.03) - print->raycast.dirY * sin(-0.03); 
    print->raycast.dirY = temp * sin(-0.03) + print->raycast.dirY * cos(-0.03); 
    temp = print->raycast.planeX;
    print->raycast.planeX = print->raycast.planeX * cos(-0.03) - print->raycast.planeY * sin(-0.03); 
    print->raycast.planeY = temp * sin(-0.03) + print->raycast.planeY * cos(-0.03); 
    return (1);
}

int ft_onleft(t_mlx *print)
{
    double temp; 
    double tempPlaneX; 

    temp= print->raycast.dirX; 
    tempPlaneX = print->raycast.planeX;
    print->raycast.dirX = print->raycast.dirX * cos(0.03) - print->raycast.dirY * sin(0.03); 
    print->raycast.dirY = temp * sin(0.03) + print->raycast.dirY * cos(-0.03); 
    temp = print->raycast.planeX; 
    print->raycast.planeX = print->raycast.planeX * cos(0.03) - print->raycast.planeY * sin(0.03); 
    print->raycast.planeY = temp * sin(0.03) + print->raycast.planeY * cos(0.03); 
    //ft_bzero(print->img.data, print->raycast.w * print->raycast.h * 4);
    //ft_drawwalls(print);  
    return (1);
}


int   ft_forward(t_mlx *print)
{
    if (print->mapchar[(int)print->raycast.posY]
		[(int)(print->raycast.posX - print->raycast.dirX
		* 0.03)] != '1')
		print->raycast.posX -= print->raycast.dirX
		* 0.03;
	if (print->mapchar[(int)(print->raycast.posY
		- print->raycast.dirY * 0.03)]
		[(int)print->raycast.posX] != '1')
		print->raycast.posY -= print->raycast.dirY
		* 0.03;
    //ft_bzero(print->img.data, print->raycast.w * print->raycast.h * 4);
    //ft_drawwalls(print);  
    return (1);
}


// int ft_forward(t_mlx *print)
// {
//     if(print->mapchar[(int)(print->raycast.posY + print->raycast.dirY * 0.10)][(int)print->raycast.posX] != '1')
//         print->raycast.posY -= print->raycast.dirY * 0.10; 
//     if(print->mapchar[(int)print->raycast.posY][(int)(print->raycast.posX + print->raycast.dirX * 0.10)] != '1')
//         print->raycast.posX -= print->raycast.dirX * 0.10; 
//     ft_bzero(print->img.data, print->raycast.w * print->raycast.h * 4);
//     ft_drawwalls(print);  
//     return (1);
// }

int g_is_up_pressed = 0;

int    keycodepress(int key, void *bidule)
{
    ft_printf("The key : %d\n", key);
    t_mlx *data;

    data = bidule; 
   
    if(key == ESC)
        data->keyroad.close = 1;
    if(key == UP) // g_is_up_pressed = 1;
       data->keyroad.front = 1;  
    if(key == DOWN)
        data->keyroad.back = 1; 
    if(key == TURNLEFT)
        data->keyroad.turnleft = 1;
    if(key == TURNRIGHT)
        data->keyroad.turnright = 1; 
    if(key == RIGHT)
        data->keyroad.right = 1; 
    if(key == LEFT)
        data->keyroad.left = 1; 
    //ft_drawwalls(bidule); 
    return(1);
}





int    keycoderelease(int key, void *bidule)
{
    ft_printf("The key : %d\n", key);
    t_mlx *data;

    data = bidule; 
   
    if(key == ESC)
        ft_close(bidule, GOODBYE); 
    if(key == UP) // g_is_up_pressed = 1;
       data->keyroad.front = 0;  
    if(key == DOWN)
        data->keyroad.back = 0; 
    if(key == TURNLEFT)
        data->keyroad.turnleft = 0;
    if(key == TURNRIGHT)
        data->keyroad.turnright = 0; 
    if(key == RIGHT)
        data->keyroad.right = 0; 
    if(key == LEFT)
        data->keyroad.left = 0; 
    //ft_drawwalls(bidule); 
    return(1);
}


int    keycode(void *bidule)
{
    t_mlx *data; 

    data = bidule; 

    if(data->keyroad.close == 1)
        ft_close(bidule, GOODBYE); 
    if( data->keyroad.front == 1) // g_is_up_pressed = 1;
        ft_onward(bidule); 
    if(data->keyroad.back == 1)
        ft_forward(bidule); 
    if(data->keyroad.turnleft == 1)
        ft_onleft(bidule);
    if(data->keyroad.turnright == 1)
        ft_onright(bidule);
    if(data->keyroad.right == 1)
        ft_right(bidule);
    if(data->keyroad.left == 1)
        ft_left(bidule);
    //ft_drawwalls(bidule); 
    return(1);
}