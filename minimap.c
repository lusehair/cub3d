
   #include "mlx.h"
   #include "cube3d.h"
   
   
    int     mini_drawblock(int x, int y, int color, void *mlx_ptr, void *win_ptr)
    {
        int xpix; 
        int ypix; 

        xpix = x; 
        ypix = y; 
        while(ypix <= y +10)
        {
            while(xpix <= x+10)
            {
                mlx_pixel_put(mlx_ptr, win_ptr, xpix, ypix , color);
                xpix++;
            }
            xpix = x; 
            ypix++;
        }
        return (0);
    }

    int mini_drawcam(char **mapchar, void *mlx_ptr, void *win_ptr, t_camera cam) 
    {
        mini_drawblock(cam.x*10, cam.y*10, 16711680, mlx_ptr, win_ptr);
        initcam(&cam);
        return (0);
    }

    void    initcam(t_camera *cam)
    {
        cam->speed = 0.1; 
        cam->angle = 0;
        cam->rotate_speed = 0.02; 
    }

    int   mini_drawmap(char **mapchar, void *mlx_ptr, void *win_ptr)
    {
        int x; 
        int y; 
        int xpix; 
        int ypix; 

        x = 0;
        y = 0;
        xpix = 0;
        ypix = 0; 
        while(mapchar[y])
        {
            while(mapchar[y][x] != '\0')
            {
                if(mapchar[y][x] == '0')
                    mini_drawblock(xpix, ypix, 16777215, mlx_ptr, win_ptr); 
                if(mapchar[y][x] == '1')
                    mini_drawblock(xpix, ypix , 6579300, mlx_ptr, win_ptr);
                xpix += 10; 
                x++;
            }
            ypix += 10;
            x = 0;
            xpix = 0; 
            y++;
        }
        
        return (0);
    }


