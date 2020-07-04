#include "cube3d.h"
#include "libft/get_next_line.h"

char *line_checker(char *line, t_initstyle *confstyle, int nb)
{
    int i; 
    char *temp; 
    
    i = 0;
    temp = malloc(sizeof(char) * (ft_strlen(line)) +1); 
    while(line[i] != '\0')
    {
        if (line[i] && ((line[i] >= '0' && line[i] <= '3') || line[i] == 'W' || line[i] =='E'
        || line[i] == 'S' || line[i] == 'N' || line[i] == ' ' || line[i] == '1'))
            temp[i] = line[i]; 
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
    pos.posX = 0;
    while(y < confstyle.longmap) 
    {
        while(mapchar[y][x] != '\0')
        {
            if(mapchar[y][x] == 'N' || mapchar[y][x] == 'W' || mapchar[y][x] == 'E' 
            || mapchar[y][x] == 'S')
            {
                pos.dir = mapchar[y][x];
                puts("no no");
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

int     ft_checkone(char *line,  int i)
{
    int a; 

    a = 1;
    if (i > 0 && ft_strlen(line) > 0)
    {
        if(line[0] != '1' || line[ft_strlen(line)-1] != '1')    
            return (-1); 
        while(line[a])
        {
            if (line[a] == ' ')
                line[a] = '0';
        a++;
        }
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
    while(currentline[i] != '\0')
    {
        if((currentline[i] == ' ' || currentline[i] == '0') && nbline == 0 && neigbourhline[i] == '1')
            currentline[i] = '1'; 
        else if((currentline[i] == ' ' || currentline[i] == '0') && nbline == 0 && neigbourhline[i] != '1')
            return (-1);
        if((currentline[i] == ' ' || currentline[i] == '0') && nbline > 0 && neigbourhline[i] == '1')
            currentline[i] = '1';
        else if((currentline[i] == ' ' || currentline[i] == '0')&& nbline > 0 && neigbourhline[i] != '1')
            return (-1);
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
    while (get_next_line(fd, &line))
    {
        if (ft_strlen(line) > 0)
        {
            if(i == 0)
                mapchar = malloc(sizeof(char*) * confstyle->largmap); 
            if(!(mapchar[i] = line_checker(line, confstyle, i)))
                ft_close_inside_map(mapchar, confstyle);
            if (ft_checkone(mapchar[i], i) == -1)
                ft_close_inside_map(mapchar, confstyle);
            confstyle->nbsprite += ft_countsprite(line);
            ft_printf("THE LINE %d : |%s|\n", i, line);
            //free(line);
            i++; 
        }
    }
    if(!(mapchar[i] = line_checker(line, confstyle, i)))
        ft_close_inside_map(mapchar, confstyle);
    if (ft_checkone(mapchar[i], i) == -1)
        ft_close_inside_map(mapchar, confstyle);
    confstyle->longmap = i;
    if (ft_strlen(line) == 0)
        i--;
    if (checkwhitespaces(mapchar[0], mapchar[1], 1) == -1)
        ft_close_inside_map(mapchar, confstyle);
    if (checkwhitespaces(mapchar[i], mapchar[i-1], i) == -1)
        ft_close_inside_map(mapchar, confstyle);
    free(line);
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
            free(line);
        }
        nbline++;
    }
    close(fd);
    fd = open(argv[1], O_RDONLY); 
    while(get_next_line(fd, &line) && i < data->confstyle.posmap)
            i++;       
    return (nbline);
}