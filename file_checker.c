#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "cube3d.h"
#include <stdio.h>

void       conf_reseter(t_mlx *data)
{
    data->confstyle.t_pathnord = NULL; 
    data->confstyle.t_pathsouth = NULL; 
    data->confstyle.t_patheast = NULL; 
    data->confstyle.t_pathwest = NULL;
    data->confstyle.t_pathsprite = NULL;  
    data->confstyle.nbsprite = 0;
    data->pos.dirX = 0;
}

int     checkfullopt(int *checkfull)
{
    int i; 

    i = 0;
    while(i < 8)
    {
        if (checkfull[i] == 0)
            return(1);
        i++;
    }
    return (0);
}

int    optselector(t_initstyle *confstyle, char *buff, int *checkfull)
{
    
    if (checkfull[0] == 0)
        if((checkfull[0] = selecres(confstyle,buff)) == 1)
            return (0); 
    if (checkfull[1] == 0)
        if ((checkfull[1] =  selecpathwe(confstyle,buff)) == 1)
            return (0);  
    if (checkfull[2] == 0)
        if((checkfull[2] =  selecpathso(confstyle,buff)) == 1)
            return (0);
    if (checkfull[3] == 0)
        if((checkfull[3] =  selecpathea(confstyle,buff)) == 1)
                 return(0);
    if(checkfull[4] == 0)    
            if((checkfull[4] =  selecpathno(confstyle,buff)) == 1)
            return (0);
    if (checkfull[5] == 0)
        if((checkfull[5] =  selecfloor(confstyle,buff)) == 1)
            return (0); 
    if (checkfull[6] == 0)
        if((checkfull[6] =  selecsky(confstyle,buff)) == 1)
            return (0);   
    if(checkfull[7] == 0)
        if((checkfull[7] =  selecpathsp(confstyle,buff)) == 1)
            return (0);

    return (1);
}

int     ft_checkbadconf(char *buff)
{
    int i; 

    i = 0;    
    ft_printf("NO WAY |%s|\n", buff);
    while(buff[i] !='\0')
    {
        ft_printf("|%c|", buff[i]);
        while(buff[i] == ' ' && buff[i] != '\0')
            i++; 
        if(buff[i] == '1' || buff[i] == '0')
        {
            puts("no here !");
            return (1);
        }
        else
            return (0);
        
    i++;
    }
    ft_putchar('\n');
    return (0);
}

int    initstyle(int fd, t_mlx *data)
{   
    char *buff;
    int checkfull[8]; 
	int i; 

    data->confstyle.posmap++;
    i = 0; 
	while(i < 8)
	{	
        checkfull[i] = 0;
        i++; 
    }
    conf_reseter(data);
    while (checkfullopt(checkfull) == 1)
    {
        get_next_line(fd, &buff);
        optselector(&data->confstyle,buff,checkfull);
        if(ft_checkbadconf(buff) == 1)
            ft_close(data, BADARGUM);
        free(buff);
        data->confstyle.posmap++;
    }
    data->confstyle.posmap--;
    ft_RBGtoINT(&data->confstyle); 
    return (0);
}

void     ft_RBGtoINT(t_initstyle *confstyle)
{
    unsigned int red; 
    unsigned int green; 
    unsigned int blue;

    red = confstyle->c_floor[0]; 
    green = confstyle->c_floor[1]; 
    blue = confstyle->c_floor[2];
    confstyle->colorFloor = red * 256 * 256 + green * 256 + blue; 
    red = confstyle->c_sky[0]; 
    green = confstyle->c_sky[1]; 
    blue = confstyle->c_sky[2];
    confstyle->colorSky = red * 256 * 256 + green * 256 + blue; 
}