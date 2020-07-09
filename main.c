#include <stdio.h> 
#include "cube3d.h"
#include <unistd.h> 
#include <fcntl.h>

// int myloop(void *ptr)
// {
//     // if (g_is_up_pressed) {}
// }

int     main(int argc, char **argv)
{

    t_mlx print; 
    int fd; 
    int i;
    char *line;

    i = 0;
    if (argc < 2)
	    return (-1);
    if(argc > 3)
        return (-1);
    fd = open(argv[1], O_RDONLY);
    initstyle(fd, &print);
    print.confstyle.largmap = ft_mapsizer(fd, argv, &print);
    //ft_printf("RES : %d for X and %d for Y\n", print.confstyle.r_res[0], print.confstyle.r_res[1]);
    //ft_printf("COLOR FLOOR : R = %d, G = %d, B = %d\n", print.confstyle.c_floor[0], print.confstyle.c_floor[1], print.confstyle.c_floor[2]);
    //ft_printf("COLOR SKY : R = %d, G = %d, B = %d\n", print.confstyle.c_sky[0], print.confstyle.c_sky[1], print.confstyle.c_sky[2]);
    // ft_printf("Path for nord wall : %s\n", print.confstyle.t_pathnord);
    // ft_printf("Path for south wall : %s\n", print.confstyle.t_pathsouth);
    // ft_printf("Path for east wall : %s\n", print.confstyle.t_patheast);
    // ft_printf("Path for west wall : %s\n", print.confstyle.t_pathwest);
    // fd = open(argv[1], O_RDONLY); 
    // while(get_next_line(fd, &line) && i < print.confstyle.posmap)
    //         i++;       
    print.mapchar = get_map(fd, &print.confstyle, argv[1]);
    print.pos = getCampos(print.mapchar, print.confstyle); 
    if(print.pos.posX == 0)
        ft_close(&print, BADARGUM);
    ft_checkone(&print);
    //spacewalker(&print,0,0);
    spacefounder(&print);
    print.mlx_ptr = mlx_init();
        ft_checkres(&print);    

    print.win = mlx_new_window(print.mlx_ptr, print.confstyle.r_res[0], print.confstyle.r_res[1], "screen test"); 
    
    ft_initrcstruct(&print.raycast,&print.confstyle, print.pos); 
    ft_initsprites(&print); 
    print.img.img_ptr = mlx_new_image(print.mlx_ptr, print.raycast.w, print.raycast.h);
    print.img.data = (unsigned int *)mlx_get_data_addr(print.img.img_ptr, &print.img.bpp, &print.img.size_l, &print.img.endian);
    ft_printf("the path of  %d\n", print.confstyle.nbsprite);
    ft_opentexture(&print);
    ft_drawwalls(&print);
    if (argc == 3)
    {
        if(ft_strncmp(argv[2], "--save", 6) == 0)
        {
        ft_savepic(&print);
        }
        else
            return (-1);
    }
    //ft_drawsprite(&print);
    mlx_hook(print.win,2, 1L << 0 ,keycode,&print); 
    mlx_hook(print.win, 17, 0, ft_closehook, &print);
    //mlx_put_image_to_window(print.mlx_ptr, print.win, print.img.img_ptr, 0, 0);
    //mlx_loop_hook(print.mlx_ptr, myloop, &print);
    mlx_loop(print.mlx_ptr); 
    return (0);
}

