all : cub3D 

cub3D : 
		$(MAKE) -C ./libft
		gcc -I  includes -I minilibx-linux -I ./libft -c ./*.c 
		gcc -g3 -fsanitize=address  -I includes -I minilibx-linux *.o ./minilibx-linux/libmlx_Linux.a ./libft/libft.a  -O1 -lm -lbsd -lXext -lX11

clean : 
		rm -rf *.o 

fclean : 
		make clean 
		rm -f *.bmp 
		rm -f cub3D 

re : 
		make fclean
		make