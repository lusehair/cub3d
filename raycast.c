#include "cube3d.h"

int   ft_initrcstruct(t_raycast *raycast,  t_initstyle *style, t_pos pos)
{
    
    //  if (!((raycast = malloc(sizeof(t_raycast)))))
    //  { 
    //     return (-1); 
    //  }
    raycast->posX = pos.posX; 
    raycast->posY = pos.posY; 
    raycast->dirX = pos.dirX; 
    raycast->dirY = pos.dirY; 
    raycast->w = style->r_res[0]; 
    raycast->h = style->r_res[1]; 
    raycast->hit = 0; 
    raycast->planeX = 0; 
    raycast->planeY = 0.77;
    return (0);
}

int     ft_drawwalls(t_mlx *print)
{

  int x = 0; 

    while(x < print->raycast.w)
    {
      //calculate ray position and direction
      print->raycast.cameraX = 2 * x / (double)print->raycast.w - 1; //x-coordinate in camera space
      print->raycast.rayDirX = print->raycast.dirX + print->raycast.planeX * print->raycast.cameraX;
      print->raycast.rayDirY = print->raycast.dirY + print->raycast.planeY * print->raycast.cameraX;

            //which box of the map we're in
      print->raycast.mapX = (int)print->raycast.posX;
      print->raycast.mapY = (int)print->raycast.posY;

      //length of ray from current position to next x or y-side

       //length of ray from one x or y-side to next x or y-side
      print->raycast.deltaDistX = (print->raycast.rayDirY == 0) ? 0 : ((print->raycast.rayDirX == 0) ? 1 : fabs(1 / print->raycast.rayDirX));
      print->raycast.deltaDistY = (print->raycast.rayDirX == 0) ? 0 : ((print->raycast.rayDirY == 0) ? 1 : fabs(1 / print->raycast.rayDirY));

      //what direction to step in x or y-direction (either +1 or -1)

      //puts("into the loop");
      print->raycast.hit = 0; //was there a wall hit?

   
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
       while (print->raycast.hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        //puts("into the other loop");
        if (print->raycast.sideDistX < print->raycast.sideDistY)
        {
          //puts("the if pass");
          print->raycast.sideDistX += print->raycast.deltaDistX;
          print->raycast.mapX += print->raycast.stepX;
          print->raycast.side = 0;
        }
        else
        {
          //puts("the else passe");
          print->raycast.sideDistY += print->raycast.deltaDistY;
          print->raycast.mapY += print->raycast.stepY;
          print->raycast.side = 1;
        }
        //Check if ray has hit a wall
        //ft_printf("mapx est %d\n mapy est %d et on retrouve %c\n", mapX, mapY, mapchar[mapY][mapX]);
        if (print->mapchar[print->raycast.mapY][print->raycast.mapX] == '1')
        {
          print->raycast.hit = 1;
        }
      }
      //puts("after the other loop");
      
      if (print->raycast.side == 0)
        print->raycast.perpWallDist = (print->raycast.mapX - print->raycast.posX + (1 - print->raycast.stepX) / 2) / print->raycast.rayDirX;
      else
        print->raycast.perpWallDist = (print->raycast.mapY - print->raycast.posY + (1 - print->raycast.stepY) / 2) / print->raycast.rayDirY; 
           //Calculate height of line to draw on screen
      print->raycast.lineHeight = abs((int)(print->raycast.h / print->raycast.perpWallDist));
      //calculate lowest and highest pixel to fill in current stripe
      print->raycast.drawStart = -print->raycast.lineHeight / 2 + print->raycast.h / 2;
      if(print->raycast.drawStart < 0)
      {
        //puts("not bad");
        print->raycast.drawStart = 0;
      }
      print->raycast.drawEnd = print->raycast.lineHeight / 2 + print->raycast.h / 2;
      if(print->raycast.drawEnd >= print->raycast.h)print->raycast.drawEnd = print->raycast.h - 1;
      //puts("before the switch\n");
      switch(print->mapchar[print->raycast.mapY][print->raycast.mapX])
      {
        case '1':  print->raycast.color = RGB_RED;    break; //red
       
      }
      //give x and y sides different brightness
      if(print->raycast.side == 1) {print->raycast.color = print->raycast.color / 2;}

      //draw the pixels of the stripe as a vertical line
      //puts("before the damage0");
      //printf("ceci est la couleur %d\n", print->confstyle.colorFloor);
      if (print->raycast.side == 1)
		      print->raycast.wall_x = print->raycast.posX + ((print->raycast.mapY - print->raycast.posY + (1 - print->raycast.stepY)
					/ 2) / print->raycast.rayDirY) * print->raycast.rayDirX;
	    else
	    	print->raycast.wall_x = print->raycast.posY + ((print->raycast.mapX - print->raycast.posX + (1 - print->raycast.stepX)
					/ 2) / print->raycast.rayDirX) * print->raycast.rayDirY;
        //print->raycast.texx = print->texteast.img_width - (print->raycast.wall_x * print->texteast.img_width) - 1;
       
      drawline(x,print->confstyle.r_res[1]/4,print->confstyle.r_res[1], print, print->confstyle.colorFloor); 
      drawline(x, 0,print->raycast.drawStart, print, print->confstyle.colorSky); 
      drawall(x, print->raycast.drawStart, print->raycast.drawEnd, print);
    

            //puts("just before");

      x++;
    }
    
    //puts("before the damage");
    mlx_put_image_to_window(print->mlx_ptr, print->win, print->img.img_ptr, 0, 0);
    //free(print->img.img_ptr);
    //free(print->img.data);

   
    

   return (0);
}