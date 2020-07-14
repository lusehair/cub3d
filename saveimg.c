#include "cube3d.h"

void    ft_pic_init(t_mlx *data)
{
    data->pic.color = 1; 
    data->pic.bpp = 32;
    data->pic.allcolor = 2835; 
    data->pic.offset = 54;
    data->pic.sizer = 40;
    data->pic.pixel = (unsigned)(data->confstyle.r_res[0] * data->confstyle.r_res[1]); 
    data->pic.buff = (unsigned)(data->pic.pixel * 4); 
    data->pic.tsize = data->pic.buff + 54;
    data->pic.pich = (int)data->confstyle.r_res[1];
    data->pic.picw = (int)data->confstyle.r_res[0]; 
}

void    ft_gotothepic(t_mlx *data)
{
    ft_memset(&data->pic.size, 0, 54); 
    data->pic.size[0] = 'B';
    data->pic.size[1] = 'M';
    ft_memcpy(&data->pic.size[2], &data->pic.tsize, sizeof(unsigned int));
    ft_memcpy(&data->pic.size[10], &data->pic.offset, sizeof(unsigned int));
    ft_memcpy(&data->pic.size[14], &data->pic.sizer, sizeof(unsigned int));
    ft_memcpy(&data->pic.size[18], &data->pic.picw, sizeof(int));
    ft_memcpy(&data->pic.size[22], &data->pic.pich, sizeof(int));
    ft_memcpy(&data->pic.size[26], &data->pic.color, sizeof(short));
    ft_memcpy(&data->pic.size[28], &data->pic.bpp, sizeof(short));
    ft_memcpy(&data->pic.size[34], &data->pic.buff, sizeof(short));
    ft_memcpy(&data->pic.size[38], &data->pic.allcolor, sizeof(int));
    ft_memcpy(&data->pic.size[42], &data->pic.allcolor, sizeof(int));
}

int    ft_savepic(t_mlx *data)
{
    int fd;
    char *mem;
    int y;
    int x;
    int i; 

    if(!(fd = open("lusehair_Cube3D.bmp", O_RDWR | O_CREAT, 77777)))
        return (-1);
    ft_pic_init(data);
    ft_gotothepic(data);
    write(fd, data->pic.size, 54); 
    y = 0;

    ft_printf("This is the : y %d\n", y);
    i = 0;
    if ((mem = (char*)(data->img.data)) != NULL)
    {
        while(y <  data->confstyle.r_res[1])
        {
            x = 0;
            i = data->confstyle.r_res[0] * (data->confstyle.r_res[1] - y);
            while(x < data->confstyle.r_res[0])
            {
                write(fd, &mem[i* 4], 4);
                i++;
                x++;
            }
            y++;
        }
        //write(fd, mem, (int)(data->confstyle.r_res[0] * data->confstyle.r_res[1] * 4));
    }
    return (0);
}

// int    ft_savepic(t_mlx *data)
// {
//     int fd;
//     char *mem;
//     int y;

//     if(!(fd = open("lusehair_Cube3D.bmp", O_RDWR | O_CREAT, 77777)))
//         return (-1);
//     ft_pic_init(data);
//     ft_gotothepic(data);
//     write(fd, data->pic.size, 54); 
//     y = data->raycast.h -1;
//     if ((mem = (char*)(data->img.data)) != NULL)
//     {
//         write(fd, mem, (int)(data->confstyle.r_res[0] * data->confstyle.r_res[1] * 4));
//     }
//     return (0);
// }