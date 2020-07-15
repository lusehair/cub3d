#ifndef CUBE3D_H
# define CUBE3D_H

#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
#include "libft/get_next_line.h"
#include <math.h> 
#include "minilibx-linux/mlx.h"
#include <stdio.h> 
#include "cube3d.h"
#include <unistd.h> 
#include <fcntl.h>



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
    int posmap;
}					t_initstyle;



#define UP 119
#define RIGHT 100
#define LEFT 97
#define DOWN 115
#define TURNRIGHT 65363
#define TURNLEFT 65361
#define SPEED 0.3
#define TURN 0.05
#define ESC 65307
#define BADMAP 16
#define BADPATH 32
#define BADMALLOC 64
#define BADARGUM 128 
#define BADPOS 256
#define GOODBYE 512
#define ALL 512 




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

typedef struct s_raysprite
{
    double spriteX;
    double spriteY; 
    double invDet;
    double transformX; 
    double transformY;
    int spriteScreenX;
    int vMoveScreen;
    int spriteHeight;
    int drawStartY;
    int drawEndY;
    int spriteWidth;
    int drawStartX;
    int drawEndX;
    int stripe;
    int texX;
    int y; 
    int d;
    int texY; 
    long int color; 
}   t_raysprite; 





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
    int posX; 
    int posY; 
    int dirX; 
    int dirY; 
    char dir;
}              t_pos; 

typedef struct	s_img
{
	void		*img_ptr;
	unsigned int			*data; 
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_pic
{
    char    size[54]; // header 
    unsigned int     pixel; //pixcount
    unsigned int     buff; //buffsize
    unsigned int     tsize; //total_pixel 
    unsigned int     offset; // pix_data_offset
    unsigned int     sizer; // header_size; 
    int     picw; // imagewidth
    int     pich; // imageheight
    short     color; // color_planes
    short     bpp; 
    int     resize; // compression 
    int     allcolor; // total_color 

}   t_pic;


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
    t_raysprite raysprite;
    t_pic       pic; 
}				t_mlx;



typedef struct s_buildmap 
{
    int m_nbline; 
    
    char p_pos; 
    char o_pos; 

    char *m_line; 
    struct s_buildmap *precline; 
} t_buildmap; 

void   conf_reseter(t_mlx *data); 
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
char     **get_map(int fd, t_initstyle *confstyle, char *path); 
int   mini_drawmap(char **mapchar, void *mlx_ptr, void *win_ptr);
t_pos    getCampos(char **mapchar, t_initstyle confstyle);
int     drawline(int x1, int y1, int y2, t_mlx *print, int color);
int     ft_drawwalls(t_mlx *print);
int    ft_initrcstruct(t_raycast *raycast,  t_initstyle *style, t_pos pos);
void     ft_RBGtoINT(t_initstyle *confstyle);
int    keycode(int key, void *bidule); 
int ft_close(t_mlx *data, int bad);
int     ft_checkone(t_mlx *data); 
void     ft_opentexture(t_mlx *print);
int     drawall(int x, int y1, int y2, t_mlx *print); 
int  insertex(t_mlx *print);
int     ft_initsprites(t_mlx *data);
int     ft_drawsprite(t_mlx *data);
int     ft_mapsizer(int fd, char **argv, t_mlx *data);
void    ft_close_inside_map(char **mapinside, t_initstyle *style);
int     spacerline(t_mlx *data);
int spacewalker(t_mlx *data, int x, int y);
int spacefounder(t_mlx *data);
int zerowalker(t_mlx *data, int x, int y);
int    ft_closehook(int key, void *data); 
int    ft_savepic(t_mlx *data);
void      ft_checkres(t_mlx *data);    






int     initstyle(int fd, t_mlx *data); 
struct	s_buildmap      *initmap(int fd);
#endif
