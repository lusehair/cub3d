#include "cube3d.h"


int    selecpathno(struct s_initstyle *confstyle, char *buff)
{
    int i; 

    i = 0; 
    while(buff[i])
    {
        
        while(buff[i] != 'N' && buff[i+1] != 'O' && buff[i])
            i++; 
        if(buff[i] == 'N' && buff[i+1] == 'O')
        {
            i = i +2 ; 
            while(buff[i] == ' ')
                i++; 
            confstyle->t_pathnord = ft_strdup(&buff[i]);
            return (1); 
        }
        i++;
    }
	return (0);
}

int    selecpathso(struct s_initstyle *confstyle, char *buff)
{
    int i; 

    i = 0; 
    while(buff[i])
    {
        while(buff[i] != 'S' && buff[i+1] != 'O' && buff[i])
            i++; 
        if(buff[i] == 'S' && buff[i+1] == 'O')
        {
            i = i +2 ; 
            while(buff[i] == ' ')
                i++; 
            confstyle->t_pathsouth = ft_strdup(&buff[i]);
            return (1); 
        }
    i++;
    }

	return (0);
}
int    selecpathea(struct s_initstyle *confstyle, char *buff)
{
    int i; 

    i = 0; 
    while(buff[i])
    {
        while(buff[i] != 'E' && buff[i+1] != 'A' && buff[i])
            i++; 
        if(buff[i] == 'E' && buff[i+1] == 'A')
        {
            i = i + 2 ; 
            while(buff[i] == ' ')
                i++; 
            confstyle->t_patheast = ft_strdup(&buff[i]);
            return (1); 
        }
        i++;
    }
	return (0);
}

int    selecpathwe(struct s_initstyle *confstyle, char *buff)
{
    int i; 

    i = 0; 
    while(buff[i])
    {
        while(buff[i] != 'W' && buff[i+1] != 'E' && buff[i])
            i++; 
        if(buff[i] == 'W' && buff[i+1] == 'E')
        {
            i = i +2 ; 
            while(buff[i] == ' ')
                i++; 
            confstyle->t_pathwest = ft_strdup(&buff[i]);
            return (1); 
        }
    i++;
    }
	return (0);
}



int    selecpathsp(t_initstyle *confstyle, char *buff)
{
    int i; 

    i = 0; 
    while(buff[i])
    {
        while(buff[i] != 'S' && buff[i])
            i++; 
        if(buff[i] == 'S')
        {
            i++; 
            while(buff[i] == ' ')
                i++; 
            confstyle->t_pathsprite = ft_strdup(&buff[i]);
            return (1); 
        }
        i++;
    }
	return (0);
}