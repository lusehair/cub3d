#include "cube3d.h"

int		selecpathno(struct s_initstyle *confstyle, char *buff)
{
	int i;
	char *temp;

	i = 0;
	while(buff[i] != 'N'  && buff[i] != '\0')
		i++;
	if(buff[i] == 'N' && buff[i+1] == 'O')
	{
		i = i +2;
		while(buff[i] == ' ')
			i++;
		temp = ft_strdup(&buff[i]);
		i = 0;
		while(temp[i] != ' ')
			i++;
		confstyle->t_pathnord = (char*)malloc((sizeof(char)* i +1));
		ft_strlcpy(confstyle->t_pathnord, temp, i+1);
		free(temp);
		return (1);
	}
	return (0);
}

int    selecpathso(struct s_initstyle *confstyle, char *buff)
{
	int i;
	char *temp;

	i = 0;
	while(buff[i] != 'S' && buff[i] != '\0')
		i++;
		if(buff[i] == 'S' && buff[i+1] == 'O')
		{
			i = i +2 ;
			while(buff[i] == ' ' && buff[i] != '\0')
				i++;
			temp = ft_strdup(&buff[i]);
			i = 0;
			while(temp[i] != ' ' && temp[i] != '\0')
				i++;
			confstyle->t_pathsouth = (char*)malloc((sizeof(char)* i +1));
			ft_strlcpy(confstyle->t_pathsouth, temp, i+1);
			free(temp);
			return (1);
		}
	return (0);
}

int		selecpathea(struct s_initstyle *confstyle, char *buff)
{

	int i;
	char *temp;

	i = 0;
	while(buff[i] != 'E' && buff[i] != '\0')
		i++;
	if(buff[i] == 'E' && buff[i+1] == 'A')
	{
		i = i + 2 ;
		while(buff[i] == ' ' )
			i++;
		temp = ft_strdup(&buff[i]);
		i = 0;
		while(temp[i] != ' ' && temp[i] != '\0')
			i++;
		confstyle->t_patheast = (char*)malloc((sizeof(char)* i +1));
		ft_strlcpy(confstyle->t_patheast, temp, i+1);
		free(temp);
		return (1);
	}
	return (0);
}

int		selecpathwe(struct s_initstyle *confstyle, char *buff)
{
	int i;
	char *temp;

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
			temp = ft_strdup(&buff[i]);
			ft_printf("The fan : %s\n", temp);
			i = 0;
			while(temp[i] != ' ' && temp[i] != '\0')
				i++;
			confstyle->t_pathwest = (char*)malloc((sizeof(char)* i +1));
			ft_strlcpy(confstyle->t_pathwest, temp, i+1);
			free(temp);
			return (1);
		}
		i++;
	}
	return (0);
}

int		selecpathsp(t_initstyle *confstyle, char *buff)
{
	int i;
	char *temp;

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
				temp = ft_strdup(&buff[i]);
				i = 0;
				while(temp[i] != ' ' && temp[i] != '\0')
					i++;
				confstyle->t_pathsprite = (char*)malloc((sizeof(char)* i +1));
				ft_strlcpy(confstyle->t_pathsprite, temp, i+1);
				free(temp);
				return (1);
			}
		i++;
	}
	return (0);
}
