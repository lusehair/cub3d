#include "cube3d.h"
#include "libft/get_next_line.h"

char *line_checker(char *line, t_initstyle *confstyle, int nb)
{
    int i; 
    char *temp; 
    
    i = 0;
    temp = malloc(sizeof(char) * (ft_strlen(line)) +1); 
    while(line[i] && nb > 0)
    {
        if (line[i] && ((line[i] >= '0' && line[i] <= '3') || line[i] == 'W' || line[i] =='E'
        || line[i] == 'S' || line[i] == 'N'))
            temp[i] = line[i]; 
        else if(line[i] == ' ' && line[i])
            temp[i] = '1'; 
        else
            return (NULL); 
        i++;
    }
    while(line[i]  && nb == 0)
    {
        if((line[i] == '1' || line[i] == ' '))
            temp[i] = '1';
        else 
            return (NULL);
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
    while(y < confstyle.longmap) 
    {
        //ft_printf("%s\n", mapchar[y]); 
        while(mapchar[y][x])
        {
            //ft_printf("%c\n", mapchar[y][x]);
            if(mapchar[y][x] == 'N' || mapchar[y][x] == 'W' || mapchar[y][x] == 'E' 
            || mapchar[y][x] == 'S')
            {

                pos.posX = x;
                pos.posY = y; 

                if(mapchar[y][x] == 'N')
                {
                    pos.dirX = 1;
                    pos.dirY = -1;
                }
                if(mapchar[y][x] == 'S')
                {
                    pos.dirX = 1;
                    pos.dirY = 0;
                }
                if(mapchar[y][x] == 'W')
                {
                    pos.dirX = -1;
                    pos.dirY = 0;
                }
                if(mapchar[y][x] == 'E')
                {
                    pos.dirX = 1;
                    pos.dirY = -1;
                }
                mapchar[y][x] = '0';
            }   
        x++;
        }
        x = 0;
        y++;
    }
    //ft_printf("c'est le posX %d et le dirY %d\n", pos.posX, pos.dirY); 
    return (pos); 

}

int     ft_checkone(char *line,  int i)
{
    int a; 

    a = 0;
    if (i == 0 || i == -1)
    {
        while(line[a])
        {
            if(line[a] != '1')
                return (-1);
                //ft_printf("this is char %c at the %d\n", line[a], a);
        a++;
        }
    }
    else if (i > 0)
    {
        if(line[0] != '1' || line[ft_strlen(line)-1] != '1')    
            return (-1); 
    }
    return (0);
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


int     checkwhitespaces(char *currentline, char *neigbourhline, int nbline)
{
    int i; 

    i = 0; 
    while(currentline[i])
    {
        if(currentline[i] == ' ' && nbline == 0 && neigbourhline[i] == '1')
            i++;
        else if(currentline[i] == ' ' && nbline == 0 && neigbourhline[i] != '1')
        {
            ft_printf("Bad Map wall1\n");
            return (-1);
        }
        if(currentline[i] == ' ' && nbline > 0 && neigbourhline[i] == '1')
            i++;
        else if(currentline[i] == ' ' && nbline > 0 && neigbourhline[i] != '1')
        {
            ft_printf("Bad Map wall2\n");
            return (-1);
        }
        i++;
    }
    return (0);

}

char     **get_map(int fd, t_initstyle *confstyle)
{
    char **mapchar;
    int i; 
    char *line; 

    i = 0;
    while (get_next_line(fd, &line) > 0)
    {
        if (ft_strlen(line) > 0)
        {
            if(i == 0)
                mapchar = malloc(sizeof(char*) * (ft_strlen(line) + 1)); 
            
            if(!(mapchar[i] = line_checker(line, confstyle, i)))
            {
                ft_printf("Not a valid Map");
                return (NULL);
            }
            ft_printf("this is the line %s\n", mapchar[i]);
            if (ft_checkone(mapchar[i], i) == -1)
            {
                ft_printf("Not a Valid Map\n");
                return (NULL);
            } 
            confstyle->nbsprite += ft_countsprite(line);
            free(line);
            i++; 
        }
        // if (checkwhitespaces(mapchar[1], mapchar[2], 1) == -1)
        // {
        //     ft_printf("Not a valid Map");
        //     return (NULL);
        // }
        // if (checkwhitespaces(mapchar[i], mapchar[i-1], i) == -1)
        // {
        //     ft_printf("Not a valid Map");
        //     return (NULL);
        // }
        confstyle->longmap = i;
    }

    return (mapchar); 
}

