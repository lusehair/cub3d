#ifndef CUBE3D_H
# define CUBE3D_H

#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
#include <math.h> 


typedef struct		s_initstyle
{
    int r_res[2];
    int c_floor[3];
    int c_sky[3];
    int p_pos[5];
    
    char *t_pathnord; 
    char *t_pathsouth; 
    char *t_patheast; 
    char *t_pathwest; 
	char *t_pathsprite;  
    int  largmap; 
    int  longmap;   
}					t_initstyle;


#define RGB_WHITE 16777215; 
#define RGB_BLACK 0;
#define RGB_RED 16711680; 
#define RGB_BLUE 255; 
#define RGB_GREEN 65280; 
#define RGB_YELLOW 16776960; 


typedef struct s_raycast
{
    float pix; 
    float ratio; 
    float dirX; 
    float dirY; 
    int mapX; 
    int mapY; 
    float deltaDistY; 
    float deltaDistX; 
    float stepX; 
    float stepY; 
    float sideDistX; 
    float sideDistY; 
    int hit; 
    int side; 
    float perpWallDist; 
    int wallcolor; 


}       t_raycast; 

typedef struct s_camera
{
    int x; 
    int y; 
    float speed; 
    float angle; 
    float rotate_speed;  
    float hCamera; 
    float fov; 

    int Xscreen;
    int Yscreen; 



    char direction;
}   t_camera; 



typedef struct s_buildmap 
{
    int m_nbline; 
    
    char p_pos; 
    char o_pos; 

    char *m_line; 
    struct s_buildmap *precline; 
} t_buildmap; 

void       conf_reseter(t_initstyle *confstyle); 
int    selecres(struct s_initstyle *confstyle, char *buff); 
int    selecpathno(struct s_initstyle *confstyle, char *buff); 
int    selecpathso(struct s_initstyle *confstyle, char *buff); 
int    selecpathea(struct s_initstyle *confstyle, char *buff); 
int    selecpathwe(struct s_initstyle *confstyle, char *buff); 
int    selecfloor(struct s_initstyle *confstyle, char *buff); 
int    selecsky(struct s_initstyle *confstyle, char *buff); 
int    selecpathsp(struct s_initstyle *confstyle, char *buff); 
int     checkfullopt(int *checkfull); 
int    optselector(struct s_initstyle *confstyle, char *buff, int *checkfull); 
int    mappush(struct s_buildmap **prec, char *line); 
int SizeLineMap(struct s_buildmap *mapbuilder); 
int printmap(t_buildmap *mapbuilder);
char     **get_map(int fd, t_initstyle *confstyle); 
int   mini_drawmap(char **mapchar, void *mlx_ptr, void *win_ptr);
t_camera    getCampos(char **mapchar);
int mini_drawcam(char **mapchar, void *mlx_ptr, void *win_ptr, t_camera cam);
void    initcam(t_camera *cam); 
int     drawline(int x1, int y1, int x2, int y2, void *mlx_ptr,void *win_ptr, int color);
int     ft_drawwalls(void *mlx_ptr, void *win_ptr, char **mapchar, t_initstyle *style, t_camera *cam); 


int     initstyle(int fd, t_initstyle *confstyle); 
struct	s_buildmap      *initmap(int fd);
#endif
