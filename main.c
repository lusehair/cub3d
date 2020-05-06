#include "mlx.h"
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



// int     main()
// {
//     void *mlx_ptr; 
//     void *win_ptr; 
//     char key; 


//     int x; 
//     int y; 
//     x = 250; 
//     y = 250; 
//     key = 0; 
//     mlx_ptr = mlx_init();
//     win_ptr = mlx_new_window(mlx_ptr, 500, 500, "screen test"); 
//     mlx_pixel_put(mlx_ptr, win_ptr, x, y , 0xFFFFFF);
//     mlx_key_hook(win_ptr, what_key, (void *)key); 
//     mlx_loop(mlx_ptr); 
// }






int     main(int argc, char **argv)
{
    t_initstyle     *confstyle;
    int fd; 
    char **mapchar; 
    int x = 0;
    int y = 0; 
    void *mlx_ptr; 
    void *win_ptr; 
    t_camera    Pos;
    void *key; 

    if(!((confstyle = malloc(sizeof(t_initstyle)))))
       return (-1);
    if (argc != 2)
	    return (-1);
   fd = open(argv[1], O_RDONLY);
    initstyle(fd, confstyle);
    ft_printf("RES : %d for X and %d for Y\n", confstyle->r_res[0], confstyle->r_res[1]);
    ft_printf("COLOR FLOOR : R = %d, G = %d, B = %d\n", confstyle->c_floor[0], confstyle->c_floor[1], confstyle->c_floor[2]);
    ft_printf("COLOR SKY : R = %d, G = %d, B = %d\n", confstyle->c_sky[0], confstyle->c_sky[1], confstyle->c_sky[2]);
    ft_printf("Path for nord wall : %s\n", confstyle->t_pathnord);
    ft_printf("Path for south wall : %s\n", confstyle->t_pathsouth);
    ft_printf("Path for east wall : %s\n", confstyle->t_patheast);
    ft_printf("Path for west wall : %s\n", confstyle->t_pathwest);
    mapchar = get_map(fd, confstyle); 
    //close(fd); 
    Pos = getCampos(mapchar); 
   
    Pos.angle = 0.125; 
    mlx_ptr = mlx_init();
    
    win_ptr = mlx_new_window(mlx_ptr, 480, 640, "screen test"); 
    ft_drawwalls(mlx_ptr,win_ptr,mapchar,confstyle,&Pos);
    //drawline(23,46,400,280,mlx_ptr, win_ptr);
    //mini_drawmap(mapchar,mlx_ptr, win_ptr);
    // mini_drawcam(mapchar, mlx_ptr, win_ptr, Pos);
    mlx_loop(mlx_ptr);
    
    return (0);
    
 
    //         if(minimap[x][y] == 1) 
    //             mlx_pixel_put(mlx_ptr, win_ptr, x+250, y+250 , 0xFF0000);
    //         else
    //              mlx_pixel_put(mlx_ptr, win_ptr, x+250, y+250 , 0xFFFEBF);
    //     }
    //     x = 0;
    // //ft_printf("on line\n");
    // }
    // //mlx_key_hook(win_ptr, what_key, (void *)key); 
    // mlx_loop(mlx_ptr); 
    
}

