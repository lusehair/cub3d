#include <stdio.h> 
#include "cube3d.h"
#include <unistd.h> 
#include <fcntl.h>

// int myloop(void *ptr)
// {
//     // if (g_is_up_pressed) {}
// }

int theloop(void *data)
{

    keycode(data);
    ft_drawwalls(data);
    return (0); 
}


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
    print.mapchar = get_map(fd, &print.confstyle, argv[1]);
    spacefounder(&print);
    print.pos = getCampos(print.mapchar, print.confstyle); 
    if(print.pos.posX == 0)
        ft_close(&print, BADARGUM);
    
    // if (ft_checkone(&print) == 1)
    // {
    //     puts("ohoh !");
    //     ft_close(&print, BADMAP);
    // }
    print.mlx_ptr = mlx_init();
        ft_checkres(&print);    
    print.win = mlx_new_window(print.mlx_ptr, print.confstyle.r_res[0], print.confstyle.r_res[1], "screen test"); 
    ft_initrcstruct(&print.raycast,&print.confstyle, print.pos); 
    ft_initsprites(&print); 
    print.img.img_ptr = mlx_new_image(print.mlx_ptr, print.raycast.w, print.raycast.h);
    print.img.data = (unsigned int *)mlx_get_data_addr(print.img.img_ptr, &print.img.bpp, &print.img.size_l, &print.img.endian);
    ft_printf("the path of  %d\n", print.confstyle.nbsprite);
    ft_opentexture(&print);
    if (argc == 3)
    {
        if(ft_strncmp(argv[2], "--save", 6) == 0)
        {
        ft_savepic(&print);
        }
        else
            return (-1);
    }
    mlx_hook(print.win,2, 1L << 0 ,keycodepress,&print); 
    mlx_hook(print.win,3, 1L <<  1,keycoderelease,&print); 
    mlx_hook(print.win, 17, 0, ft_closehook, &print);
    mlx_loop_hook(print.mlx_ptr, theloop,&print);
    mlx_loop(print.mlx_ptr); 
    return (0);
}

