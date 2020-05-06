#include "cube3d.h"

void    ft_initrcstruct(t_raycast *raycast)
{
    raycast->deltaDistX = 0;
    raycast->deltaDistY = 0; 
    raycast->dirX = 0;
    raycast->dirY = 0; 
    raycast->hit = 0; 
    raycast->mapX = 0; 
    raycast->mapY = 0; 
    raycast->perpWallDist = 0;
    raycast->pix = 0; 
    raycast->ratio = 0; 
    raycast->side = 0; 
    raycast->stepX = 0; 
    raycast->stepY = 0; 
    raycast->sideDistX = 0;
    raycast->sideDistY = 0; 
    raycast->wallcolor = 0; 
}

int     ft_drawwalls(void *mlx_ptr, void *win_ptr, char **mapchari, t_initstyle *style, t_camera *cam)
{
    //t_raycast raycast; 
    //ft_initrcstruct(&raycast); 
   
   double posX = 12, posY = 22;  //x and y start position
   double dirX = -1, dirY = 0; //initial direction vector
   double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane
   int w = 480; 
   int h = 640; 
   int color = 0; 
  double cameraX; 
  double rayDirX; 
  double rayDirY;
  int mapX; 
  int mapY; 
  double sideDistX;
  double sideDistY; 
  double deltaDistX;
  double deltaDistY; 
  double perpWallDist; 
  int stepX; 
  int stepY; 
  int hit; 
  int side;
  int lineHeight; 
  int drawStart; 
  int drawEnd; 
  int x = 0; 

  int mapchar[24][24]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


  //puts ("just here");

    while(x < w)
    {
      //calculate ray position and direction
      cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
      rayDirX = dirX + planeX * cameraX;
      rayDirY = dirY + planeY * cameraX;

            //which box of the map we're in
      mapX = (int)posX;
      mapY = (int)posY;

      //length of ray from current position to next x or y-side

       //length of ray from one x or y-side to next x or y-side
      double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
      double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));

      //what direction to step in x or y-direction (either +1 or -1)

      //puts("into the loop");
      hit = 0; //was there a wall hit?

   
     if (rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if (rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
       while (hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        //puts("into the other loop");
        if (sideDistX < sideDistY)
        {
          //puts("the if pass");
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          //puts("the else passe");
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        //ft_printf("mapx est %d\n mapy est %d et on retrouve %c\n", mapX, mapY, mapchar[mapY][mapX]);
        if (mapchar[mapX][mapY] > 0)
        {
          hit = 1;
        }
      }
      //puts("after the other loop");
      
      if (side == 0)
        perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
      else
        perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY; 
           //Calculate height of line to draw on screen
      lineHeight = (int)(h / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      drawStart = -lineHeight / 2 + h / 2;
      if(drawStart < 0)
      {
        puts("not bad");
        drawStart = 0;
      }
      drawEnd = lineHeight / 2 + h / 2;
      if(drawEnd >= h)drawEnd = h - 1;
      //puts("before the switch\n");
      switch(mapchar[mapX][mapY])
      {
        case '1':  color = RGB_RED;    break; //red
        case '2':  color = RGB_GREEN;  break; //green
        case '3':  color = RGB_BLUE;   break; //blue
        case '4':  color = RGB_WHITE;  break; //white
        default: color = RGB_YELLOW; break; //yellow
      }
      //give x and y sides different brightness
      if(side == 1) {color = color / 2;}

      //draw the pixels of the stripe as a vertical line
      drawline(x, drawStart, x, drawEnd, mlx_ptr, win_ptr, color);
      drawline(x, 0, x, drawStart, mlx_ptr, win_ptr, 255); 

      x++;
      ft_printf("x est %d\n et drawstart %d \ndrawend est %d\n", x,drawStart,  drawEnd);    
    }
   
   return (0);
}