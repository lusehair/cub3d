#include "cube3d.h"
#include "libft/get_next_line.h"

char *line_checker(char *line)
{
    int i; 
    char *temp; 
    
    temp = NULL;
    i = 0;
    printf("LINE CHECKER %s\n", line);
    if(!(temp = malloc(sizeof(char) * (ft_strlen(line)))))
        return (NULL); 
    while(line[i])
    {
        if (line[i] && ((line[i] >= '0' && line[i] < '3') || line[i] == 'W' || line[i] =='E'
        || line[i] == 'S' || line[i] == 'N' || line[i] == ' ' || line[i] == '1'))
            temp[i] = line[i]; 
        else
        {   free(line);
            return (NULL); 
        }
        i++;
    }
    temp[i] = '\0';
    return (temp); 
}

t_pos    getCampos(char **mapchar, t_initstyle confstyle)
{
    int x; 
    int y; 
    t_pos pos; 

    x = 0;
    y = 0;
    pos.posX = 0;
    while(y < confstyle.longmap) 
    {
        while(mapchar[y][x] != '\0')
        {
            if(mapchar[y][x] == 'N' || mapchar[y][x] == 'W' || mapchar[y][x] == 'E' 
            || mapchar[y][x] == 'S')
            {
                pos.dir = mapchar[y][x];
                pos.posX = x;
                pos.posY = y; 
                if(mapchar[y][x] == 'N')
                {
                    pos.dirX = 0;
                    pos.dirY = -1;
                }
                if(mapchar[y][x] == 'S')
                {
                    pos.dirX = 0;
                    pos.dirY = 1;
                }
                if(mapchar[y][x] == 'W')
                {
                    pos.dirX = -1;
                    pos.dirY = 0;
                }
                if(mapchar[y][x] == 'E')
                {
                    pos.dirX = 1;
                    pos.dirY = 0;
                }
                mapchar[y][x] = '0';
            }   
        x++;
    }
        x = 0;
        y++;
    }
    return (pos); 

}

int     ft_checkone(t_mlx *data)
{
  int y; 
  int x; 

  y = 0;
  x = 0;
  while(x < (int)ft_strlen(data->mapchar[y]))
  {
      if(data->mapchar[y][x] == '1')
        x++;
      if(data->mapchar[y][x] == ' ')
        spacewalker(data, x, y);
      if(data->mapchar[y][x] == '0')
        ft_close(data, BADMAP);
      x++;
  }
  x = 0;
  y = data->confstyle.longmap - 1;
while(x < (int)ft_strlen(data->mapchar[y]))
  {
      if(data->mapchar[y][x] == 1)
        x++;
      if(data->mapchar[y][x] == '0')  
        ft_close(data, BADMAP);  
    x++;
  }
return(0);
}

int     ft_countsprite(char *line)
{
    int i; 
    int sprite;  

    sprite = 0; 
    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == '2')
            sprite++; 
        i++;
    }
    return (sprite);
}

int     ft_checkborder(char *line)
{
    int i; 

    i = 0; 
    while(line[i] != '\0')
    {
        if(line[i] == ' ')
            i++;
        else if(line[i] != '1')
            return (-1);
        else if (line[i] == '1')
            break;
    }
    i = ft_strlen(line) -1; 
    while(i > 0)
    {
        if(line[i] == ' ')
            i--;
        else if(line[i] != '1')
            return (-1);
        else if(line[i] == '1')
            break;
    }
    return (0);
}


int spacefounder(t_mlx *data)
{
    int x;
    int y; 

    x = 0;
    y = 0; 
    while(y < data->confstyle.largmap)
    {
        ft_printf("this is --> %s <--\n", data->mapchar[y]);
        if(ft_checkborder(data->mapchar[y]) == -1)
            ft_close(data, BADMAP);
        while(x < (int)ft_strlen(data->mapchar[y]))
        {
                if(data->mapchar[y][x] == '0')
                    if(zerowalker(data,x,y) == -1)
                        ft_close(data, BADMAP);
                if(data->mapchar[y][x] == ' ')
                    spacewalker(data,x,y);
                x++;
        }
        x = 0;
        y++;
        ft_printf("this is the y in zero %d instead of the %d\n", y, data->confstyle.longmap);        
         
    }
    return (0);
}

int spacewalker(t_mlx *data, int x, int y)
{
    if (y < data->confstyle.longmap)
    {
        if(x < (int)ft_strlen(data->mapchar[y]-1))
        {
            if(data->mapchar[y][x+1] == ' ')
                spacewalker(data,x+1,y);
            if(data->mapchar[y+1][x] == ' ')
                spacewalker(data, x, y+1);
            if(data->mapchar[y][x+1] == '0' || data->mapchar[y+1][x] == '0')
                ft_close(data, BADMAP);
        x++;
        }
        y++;
    }
    return(0);
}

int zerowalker(t_mlx *data, int x, int y)
{
    int ret; 
    
    ret = 0;
    if(data->mapchar[y][x+1] == ' ')
        return (-1);
    if(data->mapchar[y][x+1] == '0')
        ret = 0;
    if(data->mapchar[y+1][x] == ' ')
        return (-1);
    if(data->mapchar[y+1][x] == '0')
        ret = 0;
    if(!data->mapchar[y+1][x])
        return (-1);
    if(data->mapchar[y][x+1] == '1')
        ret = 0;
    if(data->mapchar[y+1][x] == '1')
        ret = 0;
    //if(ft_strlen(data->mapchar[y-1]) < x)
      //  return (-1);
    //if(ft_strlen(data->mapchar[y+1]) < x)
      //  return (-1);
    return (ret);
}

char     **get_map(int fd, t_initstyle *confstyle)
{
    char **mapchar;
    int i; 
    char *line; 

    i = 0;
    ft_printf("this is --> %d <--\n", confstyle->largmap);
    while (i <= confstyle->largmap)
    {
        get_next_line(fd, &line);
        if (ft_strlen(line) > 0)
        {
            if(i == 0)
                mapchar = malloc(sizeof(char*) * confstyle->largmap);
            if(!(mapchar[i] = line_checker(line)))
                ft_close_inside_map(mapchar, confstyle);
            confstyle->nbsprite += ft_countsprite(line);
            i++; 
            free(line);
        }
        else  
            free(line);       
    }
    // if(line)
    //     free(line);
    confstyle->longmap = i;
    //free(line);
    return (mapchar); 
}

int     ft_mapsizer(int fd, char **argv, t_mlx *data)
{
    char *line;
    int i;
    int nbline;

    i = 0;
    nbline = 0;
    while(get_next_line(fd, &line))
    {
        if(ft_strlen(line) > 0)   
        {
            nbline++;
            printf("THE LINE IN ORIGIN --> %s\n", line);
        }
       free(line);
    }
    if(line)
    {
        if(ft_strlen(line) == 0)
            nbline--;
        free(line);
    }
    close(fd);
    fd = open(argv[1], O_RDONLY); 
    while(get_next_line(fd, &line) && i < data->confstyle.posmap)
    {
            i++;      
            free(line);
    } 
    free(line);
    printf("---> THE ORIGIN %d<----", nbline);
    return (nbline);
}