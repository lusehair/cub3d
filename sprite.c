#include "cube3d.h"
      #define uDiv 1
      #define vDiv 1
      #define vMove 0.0

int     ft_initsprites(t_mlx *data)
{
    int x; 
    int y; 
    int s;

    x = 0;
    y = 0;
    s = 0; 
    if (!(data->raycast.sprites = (t_sprite*)malloc(data->confstyle.nbsprite *sizeof(t_sprite))))
        return (-1);
    if(!(data->raycast.spriteOrder = (int*)malloc(data->confstyle.nbsprite *sizeof(int))))
        return (-1);
     if(!(data->raycast.spriteDistance = (int*)malloc(data->confstyle.nbsprite *sizeof(int))))
        return (-1);
    if(!(data->raycast.ZBuffer = (double*)malloc(data->raycast.w * sizeof(double))))
        return (-1);
    while (data->mapchar[y])
    {
        while (data->mapchar[y][x])
        {
            if (data->mapchar[y][x] == '2')
            {
                data->raycast.sprites[s].x = x;
                data->raycast.sprites[s].y = y; 
                s++;
            }
            x++;
        }
    x = 0;
    y++;
    }
    return (0);
}

void    sortS(t_mlx *data)
{
  int i;
  t_sprite stemp; 

  i = 0;

  while(i < data->confstyle.nbsprite) 
  {
    data->raycast.sprites[i].dist = ((data->raycast.posX - data->raycast.sprites[i].x) * (data->raycast.posX - data->raycast.sprites[i].x)
     + (data->raycast.posY - data->raycast.sprites[i].y) * (data->raycast.posY - data->raycast.sprites[i].y));
     i++;
  }
  i = 0; 
  //puts("GoodPassing");
  while(i <= data->confstyle.nbsprite)
  {
    if(data->raycast.sprites[i].dist > data->raycast.sprites[i+1].dist)
    {
      stemp = data->raycast.sprites[i];
      data->raycast.sprites[i] = data->raycast.sprites[i + 1]; 
      data->raycast.sprites[i + 1] = stemp; 
      i = 0;
    }  
  i++;
  //ft_printf("this is dist of sprite %d\n", (int)data->raycast.sprites[i].dist);
  }
}

int     ft_drawsprite(t_mlx *data)
{

  int i; 
  double spriteX;
  double spriteY; 
  double invDet;
  double transformX; 
  double transformY;
  int spriteScreenX;
  int vMoveScreen;
  int spriteHeight;
  int drawStartY;
  int drawEndY;
  int spriteWidth;
  int drawStartX;
  int drawEndX;
  int stripe;
  int texX;
  int y; 
  int d;
  int texY; 
  long int color; 

  i = 0; 

 //SPRITE CASTING
    //sort sprites from far to close
    while(i < data->confstyle.nbsprite)
    {
      data->raycast.spriteOrder[i] = i;
      data->raycast.spriteDistance[i] = ((data->raycast.posX - data->raycast.sprites[i].x) * (data->raycast.posX - data->raycast.sprites[i].x) + (data->raycast.posY - data->raycast.sprites[i].y) * (data->raycast.posY - data->raycast.sprites[i].y)); //sqrt not taken, unneeded
      i++; 
    }
    //puts("before sort");
    sortS(data);
    //puts("after sort");

    
    //after sorting the sprites, do the projection and draw them
    i = 0;
    while(i < data->confstyle.nbsprite)
    {
      //translate sprite position to relative to camera
      spriteX = data->raycast.sprites[data->raycast.spriteOrder[i]].x - data->raycast.posX;
      spriteY = data->raycast.sprites[data->raycast.spriteOrder[i]].y - data->raycast.posY;
      invDet = 1.0 / (data->raycast.planeX * data->raycast.dirY - data->raycast.dirX * data->raycast.planeY); //required for correct matrix multiplication
      transformX = invDet * (data->raycast.dirY * spriteX - data->raycast.dirX * spriteY);
      transformY = invDet * (-data->raycast.planeY * spriteX + data->raycast.planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])
      spriteScreenX = (int)((data->raycast.w / 2) * (1 + transformX / transformY));

      //parameters for scaling and moving the sprites

      vMoveScreen = (int)(vMove / transformY);

      //calculate height of the sprite on screen
      spriteHeight = abs((int)(data->raycast.h / (transformY))); //using "transformY" instead of the real distance prevents fisheye
      //calculate lowest and highest pixel to fill in current stripe
      drawStartY = -spriteHeight / 2 + data->raycast.h / 2;
      if(drawStartY < 0)
        drawStartY = 0;
      drawEndY = spriteHeight / 2 + data->raycast.h / 2 ;
      if(drawEndY >= data->raycast.h)
        drawEndY = data->raycast.h - 1;

      //calculate width of the sprite
      spriteWidth = abs( (int)(data->raycast.h / (transformY)));
      drawStartX = -spriteWidth / 2 + spriteScreenX;
      if(drawStartX < 0)
        drawStartX = 0;
      drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= data->raycast.w)
        drawEndX = data->raycast.w - 1;

      //loop through every vertical stripe of the sprite on screen
      stripe = drawStartX; 
      while(stripe < drawEndX)
      {
        //puts("into the sprite big while");
        texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * data->textsprite.img_width / spriteWidth) / 256;
                  y = drawStartY;

        //the conditions in the if are:
        //1) it's in front of camera plane so you don't see things behind you
        //2) it's on the screen (left)
        //3) it's on the screen (right)
        //4) ZBuffer, with perpendicular distance
       // ft_printf("this is stripe : %d\n", stripe);
        if(transformY > 0 && stripe > 0 && stripe < data->raycast.w && transformY < data->raycast.ZBuffer[stripe])
        {
          //ft_printf("this is color %d\n", color);
          
          while(y < drawEndY) //for every pixel of the current stripe
          {
            d = (y) * 256 - data->raycast.h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
            texY = ((d * data->textsprite.img_weight) / spriteHeight) /256 ;
            color = data->textsprite.data[data->textsprite.img_width  * texY + texX]; //get current color from the texture
            if((color & 0x00FFFFFF) != 0) 
              data->img.data[y * data->raycast.w - 1 + stripe] = color; //paint pixel if it isn't black, black is the invisible color
            //ft_printf("%d\n", data->img.data[y * data->textsprite.t_size + stripe]);
            y++;
          }
        }
        stripe++;
      }
    i++;
    }
    return (0);
}