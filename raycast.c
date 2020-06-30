#include "cube3d.h"

int   ft_initrcstruct(t_raycast *raycast,  t_initstyle *style, t_pos pos)
{
    raycast->posX = pos.posX; 
    raycast->posY = pos.posY; 
    raycast->dirX = pos.dirX; 
    raycast->dirY = pos.dirY; 
    raycast->w = style->r_res[0]; 
    raycast->h = style->r_res[1]; 
    raycast->hit = 0; 
    raycast->planeX = 0; 
    raycast->planeY = 0.66;
        //ft_printf("This or is posX %d\n",pos.posX);

    return (0);
}

void    sidechecker(t_mlx *print)
{
   if (print->raycast.rayDirX < 0)
      {
        print->raycast.stepX = -1;
        print->raycast.sideDistX = (print->raycast.posX - print->raycast.mapX) * print->raycast.deltaDistX;
      }
      else
      {
        print->raycast.stepX = 1;
        print->raycast.sideDistX = (print->raycast.mapX + 1.0 - print->raycast.posX) * print->raycast.deltaDistX;
      }
      if (print->raycast.rayDirY < 0)
      {
        print->raycast.stepY = -1;
        print->raycast.sideDistY = (print->raycast.posY - print->raycast.mapY) * print->raycast.deltaDistY;
      }
      else
      {
        print->raycast.stepY = 1;
        print->raycast.sideDistY = (print->raycast.mapY + 1.0 - print->raycast.posY) * print->raycast.deltaDistY;
      }

}

void    hit_collison(t_mlx *print)
{
  while (print->raycast.hit == 0)
      {
         //ft_printf("this is mapY %d and mapX %d\n", print->raycast.mapY, print->raycast.mapX); 
        if (print->raycast.sideDistX < print->raycast.sideDistY)
        {
          print->raycast.sideDistX += print->raycast.deltaDistX;
          print->raycast.mapX += print->raycast.stepX;
          print->raycast.side = 0;
        }
        else
        {
          print->raycast.sideDistY += print->raycast.deltaDistY;
          print->raycast.mapY += print->raycast.stepY;
          print->raycast.side = 1;
        }
        if (print->mapchar[print->raycast.mapY][print->raycast.mapX] == '1')
          print->raycast.hit = 1;
      }

      if (print->raycast.side == 0)
        print->raycast.perpWallDist = (print->raycast.mapX - print->raycast.posX + (1 - print->raycast.stepX) / 2) / print->raycast.rayDirX;
      else
        print->raycast.perpWallDist = (print->raycast.mapY - print->raycast.posY + (1 - print->raycast.stepY) / 2) / print->raycast.rayDirY; 
}

void   cut_the_wall(t_mlx *print)
{
        print->raycast.lineHeight = abs((int)(print->raycast.h / print->raycast.perpWallDist));
      print->raycast.drawStart = -print->raycast.lineHeight / 2 + print->raycast.h / 2;
      if(print->raycast.drawStart < 0)
      {
        print->raycast.drawStart = 0;
      }
      print->raycast.drawEnd = print->raycast.lineHeight / 2 + print->raycast.h / 2;
      if(print->raycast.drawEnd >= print->raycast.h)
        print->raycast.drawEnd = print->raycast.h - 1;
      if(print->raycast.side == 1) 
        print->raycast.color = print->raycast.color / 2;
      if (print->raycast.side == 1)
		      print->raycast.wall_x = print->raycast.posX + ((print->raycast.mapY - print->raycast.posY + (1 - print->raycast.stepY)
					/ 2) / print->raycast.rayDirY) * print->raycast.rayDirX;
	    else
	    	print->raycast.wall_x = print->raycast.posY + ((print->raycast.mapX - print->raycast.posX + (1 - print->raycast.stepX)
					/ 2) / print->raycast.rayDirX) * print->raycast.rayDirY;
}

int     ft_drawwalls(t_mlx *print)
{

    //ft_printf("here X %d\n, here y %d\n", print->pos.posX, print->pos.posY);
    print->raycast.x = 0; 
    while(print->raycast.x < print->raycast.w)
    {
       print->raycast.cameraX = 2 * print->raycast.x / (double)print->raycast.w - 1;
      print->raycast.rayDirX = print->raycast.dirX + print->raycast.planeX * print->raycast.cameraX;
      print->raycast.rayDirY = print->raycast.dirY + print->raycast.planeY * print->raycast.cameraX;
      print->raycast.mapX = (int)print->raycast.posX;
      print->raycast.mapY = (int)print->raycast.posY;
      print->raycast.deltaDistX = (print->raycast.rayDirY == 0) ? 0 : ((print->raycast.rayDirX == 0) ? 1 : fabs(1 / print->raycast.rayDirX));
      print->raycast.deltaDistY = (print->raycast.rayDirX == 0) ? 0 : ((print->raycast.rayDirY == 0) ? 1 : fabs(1 / print->raycast.rayDirY));
      print->raycast.hit = 0; 
      sidechecker(print);
      hit_collison(print);
      cut_the_wall(print);
      drawline(print->raycast.x,print->confstyle.r_res[1]/4,print->confstyle.r_res[1], print, print->confstyle.colorFloor); 
      drawline(print->raycast.x, 0,print->raycast.drawStart, print, print->confstyle.colorSky); 
      drawall(print->raycast.x, print->raycast.drawStart, print->raycast.drawEnd, print);
      print->raycast.ZBuffer[print->raycast.x] = print->raycast.perpWallDist; 
      print->raycast.x++;
    }
    if(print->confstyle.nbsprite > 0)
      ft_drawsprite(print);
    //puts("before the damage");
    mlx_put_image_to_window(print->mlx_ptr, print->win, print->img.img_ptr, 0, 0);
   return (0);
}

//1297437786