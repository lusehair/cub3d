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
    while (y < data->confstyle.longmap)
    {
        ft_printf("|%s|\n", data->mapchar[y]);
        while (data->mapchar[y][x])
        {
            if (data->mapchar[y][x] == '2')
            {
                data->raycast.sprites[s].x = x + 0.5;
                data->raycast.sprites[s].y = y + 0.5; 
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
  while(i < data->confstyle.nbsprite - 1)
  {
    if(data->raycast.sprites[i].dist > data->raycast.sprites[i+1].dist)
    {
      stemp = data->raycast.sprites[i];
      data->raycast.sprites[i] = data->raycast.sprites[i + 1]; 
      data->raycast.sprites[i + 1] = stemp; 
      i = 0;
    }  
  i++;
  }
}

int     ft_drawsprite(t_mlx *data)
{
  int i; 

  i = 0; 
  while(i < data->confstyle.nbsprite)
  {
    data->raycast.spriteOrder[i] = i;
    data->raycast.spriteDistance[i] = ((data->raycast.posX - data->raycast.sprites[i].x) * (data->raycast.posX - data->raycast.sprites[i].x) + (data->raycast.posY - data->raycast.sprites[i].y) * (data->raycast.posY - data->raycast.sprites[i].y)); 
    i++; 
  }
  sortS(data);
  i = 0;
  while(i < data->confstyle.nbsprite)
  {
    data->raysprite.spriteX = data->raycast.sprites[data->raycast.spriteOrder[i]].x - data->raycast.posX;
    data->raysprite.spriteY = data->raycast.sprites[data->raycast.spriteOrder[i]].y - data->raycast.posY;
    data->raysprite.invDet = 1.0 / (data->raycast.planeX * data->raycast.dirY - data->raycast.dirX * data->raycast.planeY); 
    data->raysprite.transformX = data->raysprite.invDet * (data->raycast.dirY * data->raysprite.spriteX - data->raycast.dirX * data->raysprite.spriteY);
      data->raysprite.transformY = data->raysprite.invDet * (-data->raycast.planeY * data->raysprite.spriteX + data->raycast.planeX * data->raysprite.spriteY); 
      data->raysprite.spriteScreenX = (int)((data->raycast.w / 2) * (1 + data->raysprite.transformX / data->raysprite.transformY));
      data->raysprite.vMoveScreen = (int)(vMove / data->raysprite.transformY);
      data->raysprite.spriteHeight = abs((int)(data->raycast.h / (data->raysprite.transformY))); 
      data->raysprite.drawStartY = -data->raysprite.spriteHeight / 2 + data->raycast.h / 2;
      if(data->raysprite.drawStartY < 0)
        data->raysprite.drawStartY = 0;
      data->raysprite.drawEndY = data->raysprite.spriteHeight / 2 + data->raycast.h / 2 ;
      if(data->raysprite.drawEndY >= data->raycast.h)
        data->raysprite.drawEndY = data->raycast.h - 1;
      data->raysprite.spriteWidth = abs( (int)(data->raycast.h / (data->raysprite.transformY)));
      data->raysprite.drawStartX = -data->raysprite.spriteWidth / 2 + data->raysprite.spriteScreenX;
      if(data->raysprite.drawStartX < 0)
        data->raysprite.drawStartX = 0;
      data->raysprite.drawEndX = data->raysprite.spriteWidth / 2 + data->raysprite.spriteScreenX;
      if(data->raysprite.drawEndX >= data->raycast.w)
        data->raysprite.drawEndX = data->raycast.w - 1;
      data->raysprite.stripe = data->raysprite.drawStartX; 
      while(data->raysprite.stripe < data->raysprite.drawEndX)
      {
        data->raysprite.texX = (int)(256 * (data->raysprite.stripe - (-data->raysprite.spriteWidth / 2 + data->raysprite.spriteScreenX)) * data->textsprite.img_width / data->raysprite.spriteWidth) / 256;
                  data->raysprite.y = data->raysprite.drawStartY;
        //printf("transy : %f and stripeZ %f \n", data->raysprite.transformY, data->raycast.ZBuffer[data->raysprite.stripe]);
        if(data->raysprite.transformY > 0 && data->raysprite.stripe > 0 && data->raysprite.stripe < data->raycast.w && data->raysprite.transformY < data->raycast.ZBuffer[data->raysprite.stripe])
        {

          while(data->raysprite.y < data->raysprite.drawEndY) 
          {
            data->raysprite.d = (data->raysprite.y) * 256 - data->raycast.h * 128 + data->raysprite.spriteHeight * 128; 
            data->raysprite.texY = ((data->raysprite.d * data->textsprite.img_weight) / data->raysprite.spriteHeight) /256 ;
            data->raysprite.color = data->textsprite.data[data->textsprite.img_width  * data->raysprite.texY + data->raysprite.texX]; 
            if((data->raysprite.color & 0x00FFFFFF) != 0) 
            {
              data->img.data[data->raysprite.y * data->raycast.w - 1 + data->raysprite.stripe] = data->raysprite.color; 
            }
            data->raysprite.y++;
          }
        }
        data->raysprite.stripe++;
      }
    i++;
    }
    return (0);
  }
