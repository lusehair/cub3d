#include <stdio.h> 
#include "cube3d.h"
#include <unistd.h> 
#include <fcntl.h>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480
#define RGB_Red 16711680
#define RGB_Green 65280
#define RGB_Blue 255
#define RGB_White 16777215
#define RGB_Yellow 16776960


int     main(int argc, char **argv)
{

    t_mlx print; 
    int fd; 

    // if(!((confstyle = malloc(sizeof(t_initstyle)))))
    //    return (-1);
    if (argc != 2)
	    return (-1);
    fd = open(argv[1], O_RDONLY);
    initstyle(fd, &print.confstyle);
    //ft_printf("RES : %d for X and %d for Y\n", print.confstyle.r_res[0], print.confstyle.r_res[1]);
    //ft_printf("COLOR FLOOR : R = %d, G = %d, B = %d\n", print.confstyle.c_floor[0], print.confstyle.c_floor[1], print.confstyle.c_floor[2]);
    //ft_printf("COLOR SKY : R = %d, G = %d, B = %d\n", print.confstyle.c_sky[0], print.confstyle.c_sky[1], print.confstyle.c_sky[2]);
    ft_printf("Path for nord wall : %s\n", print.confstyle.t_pathnord);
    ft_printf("Path for south wall : %s\n", print.confstyle.t_pathsouth);
    ft_printf("Path for east wall : %s\n", print.confstyle.t_patheast);
    ft_printf("Path for west wall : %s\n", print.confstyle.t_pathwest);
    print.mapchar = get_map(fd, &print.confstyle); 
    print.pos = getCampos(print.mapchar); 
    
    
    //ft_printf("the posX is : %d\n the posY is : %d\n", print.pos.posX,  print.pos.posY);
    //ft_printf("the dirX is : %d\n the dirY is : %d\n", print.pos.dirX, print.pos.dirY); 
    print.mlx_ptr = mlx_init();
    print.win = mlx_new_window(print.mlx_ptr, print.confstyle.r_res[0], print.confstyle.r_res[1], "screen test"); 
    
    //if(print.raycast.w)
    ft_initrcstruct(&print.raycast,&print.confstyle, print.pos); 
    ft_opentexture(&print); 
    print.img.img_ptr = mlx_new_image(print.mlx_ptr, print.raycast.w, print.raycast.h);
    print.img.data = (unsigned int *)mlx_get_data_addr(print.img.img_ptr, &print.img.bpp, &print.img.size_l, &print.img.endian);
    ft_drawwalls(&print);
    mlx_hook(print.win,2,0 ,keycode,&print); 
    mlx_hook(print.win, 17, 0, ft_close, &print); 
    //mlx_put_image_to_window(print.mlx_ptr, print.win, print.img.img_ptr, 0, 0);
    mlx_loop(print.mlx_ptr);

    
    return (0);


    
}

