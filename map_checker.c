#include "cube3d.h"
#include "libft/get_next_line.h"

/* 

Return Value : 
-1 --> Wall problem 
-2 --> Bad argument in line 
0 --> Everything it's okay 
1 --> Sprite on this line 
87 --> West direction on this line 
88 -- > West and sprite on this line (87+1) 
83 --> South direction on this line 
84 --> South and sprite on this line (84+1)
78 --> North direction on this line 
79 --> North and sprite on this line 
69 --> East direction on this line 
70 --> East and Sprite on this line 

*/   


char *line_checker(char *line, t_initstyle *confstyle, int nb)
{
    int i; 
    char *temp; 
    
    i = 0;
    temp = malloc(sizeof(char) * (ft_strlen(line)) +1); 
   //printf("input char %s \n",line);
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
    //ft_printf("convert line %s and size %zu\n", temp, ft_strlen(temp));
    return (temp); 
}

int     **convint(char **chartab)
{
    int x; 
    int y; 
    int **intret = 0; 
    x = 0; 
    y = 0; 
    intret = malloc(sizeof(int*)* (ft_strlen(chartab[0]) + 1)); 
    while(chartab[y])
    {
        intret[y] = malloc(sizeof(int) * (ft_strlen(chartab[y] + 1))); 
        y++; 
    }
    y = 0; 
    while(chartab[y])
    {
        while(chartab[y][x] != '\0')
        {
            intret[y][x] = chartab[y][x] - 48;
            x++;  
        }
        x = 0; 
        y++; 
    }
    return(intret);
}

t_pos    getCampos(char **mapchar)
{
    int x; 
    int y; 
    t_pos pos; 

    x = 0;
    y = 0;
    while(mapchar[y])
    {
        //ft_printf("%s\n", mapchar[y]); 
        while(mapchar[y][x])
        {
            //ft_printf("%c\n", mapchar[y][x]);
            if(mapchar[y][x] == 'N' || mapchar[y][x] == 'W' || mapchar[y][x] == 'E' 
            || mapchar[y][x] == 'S')
            {
                puts("ohoho");
                pos.posX = x;
                pos.posY = y; 
                if(mapchar[y][x] == 'N')
                {
                    pos.dirX = 0;
                    pos.dirY = 1;
                }
                if(mapchar[y][x] == 'S')
                {
                    pos.dirX = 0;
                    pos.dirY = -1;
                }
                if(mapchar[y][x] == 'W')
                {
                    pos.dirX = -1;
                    pos.dirY = 0;
                }
                if(mapchar[y][x] == 'E')
                {
                    pos.dirX = 1;
                    //puts("c'est E");
                    pos.dirY = 0;
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
            if(!(mapchar[i] = line_checker(line, confstyle, i))) ft_printf("ERRORMAP\n") ;
            
            free(line);

            i++; 
        }
    }
   
    return (mapchar); 
}