#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "cube3d.h"
#include <stdio.h>

void       conf_reseter(struct s_initstyle *confstyle)
{
    confstyle->t_pathnord = NULL; 
    confstyle->t_pathsouth = NULL; 
    confstyle->t_patheast = NULL; 
    confstyle->t_pathwest = NULL;

    confstyle->t_pathsprite = NULL;  

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
        if ((checkfull[1] =  selecpathno(confstyle,buff)) == 1)
            return (0);  
    checkfull[1] = 1;
    if (checkfull[2] == 0)
        if((checkfull[2] =  selecpathso(confstyle,buff)) == 1)
            return (0);
    if (checkfull[3] == 0)
        if((checkfull[3] =  selecpathea(confstyle,buff)) == 1)
                 return(0);
    if(checkfull[4] == 0)    
            if((checkfull[4] =  selecpathwe(confstyle,buff)) == 1)
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

int    mappush(struct s_buildmap **prec, char *line)
{
    struct s_buildmap *newline; 
    static int nb;


    if (!(newline = malloc(sizeof(struct s_buildmap))))
        return (-1);
    newline->m_line = ft_strdup(line); 
    newline->m_nbline = nb + 1; 
    newline->precline = *prec; 
    *prec = newline; 
    return (ft_strlen(newline->m_line));
}

int SizeLineMap(struct s_buildmap *mapbuilder)
{
        int n;

        n = 0;
        while(mapbuilder)
          {
              n++;
              mapbuilder = mapbuilder->precline;
          }
        return n;
}


int    initstyle(int fd, t_initstyle *confstyle)
{   
    char *buff;
    int checkfull[8]; 
	int i; 

    i = 0; 
	while(i < 8)
	{	
        checkfull[i] = 0;
        i++; 
    }
    conf_reseter(confstyle);
    
        while (checkfullopt(checkfull) == 1)
        {
            get_next_line(fd, &buff);
            ft_printf("c'est le buff %s\n", buff); 
            optselector(confstyle,buff,checkfull);
        }
        free(buff);
        ft_RBGtoINT(confstyle); 
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


struct s_buildmap      *initmap(int fd)
{
    int ret; 
    struct s_buildmap *mapbuilder; 
	char *buff; 
    int a; 
    int b; 

    b = 0;
    mapbuilder = NULL;
    while((ret = get_next_line(fd, &buff)) > 0)
    {
        if(buff != NULL)
            mappush(&mapbuilder, buff); 
        
    }

    return (mapbuilder);
} 


