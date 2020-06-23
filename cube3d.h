#ifndef CUBE3D_H
# define CUBE3D_H

#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
#include <math.h> 
#include "mlx.h"



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
    unsigned int colorSky; 
    unsigned int colorFloor;   
    int nbsprite; 
}					t_initstyle;


#define RGB_WHITE 16777215; 
#define RGB_BLACK 0;
#define RGB_RED 16711680; 
#define RGB_BLUE 255; 
#define RGB_GREEN 65280; 
#define RGB_YELLOW 16776960; 
#define UP 126
#define RIGHT 123
#define LEFT 124
#define DOWN 125
#define SPEED 0.10
#define TURN 0.05
#define ESC 53

typedef struct s_sprite
{
    double x; 
    double y; 
    double dist; 
} t_sprite; 


typedef struct s_raycast
{
    double posX;  //x and y start position
   double posY; 
   double dirX; //initial direction vector
   double dirY; 
   double planeX ; //the 2d raycaster version of camera plane
   double planeY; 
   int w ; 
   int h; 
   int color ; 
  double cameraX; 
  double rayDirX; 
  double rayDirY;
  int mapX; 
  int mapY; 
  double sideDistX;
  double sideDistY; 
  double deltaDistX;
  double deltaDistY; 
  double perpWallDist; 
  int stepX; 
  int stepY; 
  int hit; 
  int side;
  int lineHeight; 
  int drawStart; 
  int drawEnd; 
  int x;
  double			texx;
  double			texy;
  double			wall_x;
  int hline;
  t_sprite *sprites;
  int *spriteOrder;
  int *spriteDistance;  
  double *ZBuffer; 

}       t_raycast; 



typedef struct  s_texture
{ 
    void *img; 
    int img_weight; 
    int img_width;
    int t_size;
    int bpp; 
    int endian;
    int *data;
} t_texture; 



typedef struct s_pos
{
    float posX; 
    float posY; 
    float dirX; 
    float dirY; 
}              t_pos; 

typedef struct	s_img
{
	void		*img_ptr;
	unsigned int			*data; 
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
    char        **mapchar;
    t_raycast   raycast;
    t_pos       pos; 
    t_initstyle confstyle; 
    t_texture   texteast; 
    t_texture   textwest; 
    t_texture   textsouth; 
    t_texture   textnorth; 
    t_texture   textsprite; 
}				t_mlx;



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
t_pos    getCampos(char **mapchar);
int     drawline(int x1, int y1, int y2, t_mlx *print, int color);
int     ft_drawwalls(t_mlx *print);
int    ft_initrcstruct(t_raycast *raycast,  t_initstyle *style, t_pos pos);
void     ft_RBGtoINT(t_initstyle *confstyle);
int    keycode(int key, void *bidule); 
int ft_close(t_mlx *print);
int     ft_checkone(char *line, int i); 
void     ft_opentexture(t_mlx *print);
int     drawall(int x, int y1, int y2, t_mlx *print); 
int  insertex(t_mlx *print);
int     ft_initsprites(t_mlx *data);
int     ft_drawsprite(t_mlx *data);






int     initstyle(int fd, t_initstyle *confstyle); 
struct	s_buildmap      *initmap(int fd);
#endif
