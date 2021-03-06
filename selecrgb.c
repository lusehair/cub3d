#include "cube3d.h"

int		selecres(struct s_initstyle *confstyle, char *buff)
{
	int i;

	i = 0;
	while(buff[i] != '\0' && buff[i] != 'R')
		i++;
	if(buff[i] == 'R' && buff[i])
	{
		i++;
		while(buff[i] == ' ' && buff[i] != '\0')
			i++;
		confstyle->r_res[0] = ft_atoi(&buff[i]);
		while(ft_isdigit(buff[i]) == 1 && buff[i] != '\0')
			i++;
		while(buff[i] == ' ' && buff[i] != '\0')
			i++;
		confstyle->r_res[1] = ft_atoi(&buff[i]);
		return (1);
	}
	return (0);
}

int		selecfloor(struct s_initstyle *confstyle, char *buff)
{
	int i;
	
	i = 0;
	while(buff[i] != 'F' && buff[i])
		i++;
	if(buff[i] == 'F')
	{
		i++;
		while(buff[i] == ' ')
			i++;
		confstyle->c_floor[0] = ft_atoi(&buff[i]);
		while(ft_isdigit(buff[i]) == 1)
			i++;
		confstyle->c_floor[1] = ft_atoi(&buff[i+1]);
		while(ft_isdigit(buff[i]) == 1)
			i++;
		confstyle->c_floor[2] = ft_atoi(&buff[i+1]);
		return (1);
	}
	return (0);
}

int		selecsky(struct s_initstyle *confstyle, char *buff)
{
	int i;

	i = 0;
	while(buff[i])
	{
		while(buff[i] != 'C' && buff[i])
		i++;
		if(buff[i] == 'C')
		{
			i++;
			while(buff[i] == ' ')
				i++;
			confstyle->c_sky[0] = ft_atoi(&buff[i]);
			while(ft_isdigit(buff[i]) == 1)
				i++;
			confstyle->c_sky[1] = ft_atoi(&buff[i+1]);
			while(ft_isdigit(buff[i]) == 1)
				i++;
			confstyle->c_sky[2] = ft_atoi(&buff[i+1]);
			return (1);
		}
		i++;
	}
	return (0);
}
