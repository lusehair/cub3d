NAME = Cub3D
CC = 
FLAG = -Wall -Werror -Wextra

LIBC = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c\
	   libft/ft_isdigit.c libft/ft_isprint.c libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c \
	   libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_strchr.c libft/ft_strdup.c \
	   libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strnstr.c \
	   libft/ft_strrchr.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
	   libft/ft_putnbr_fd.c libft/ft_putendl_fd.c libft/ft_strrev.c libft/ft_split.c \
	   libft/ft_strtrim.c libft/ft_strmapi.c libft/ft_strjoin.c libft/ft_strncat.c  libft/ft_substr.c\
	   libft/get_next_line.c libft/get_next_line_utils.c libft/ft_putchar.c libft/ft_putstr.c \
	   libft/ft_putnbr.c \

LIBCPRINTF = libft/ft_printf/ft_adress.c libft/ft_printf/ft_char_init.c libft/ft_printf/ft_hexa.c\
			 libft/ft_printf/ft_int.c libft/ft_printf/ft_int_dashcase.c \
			 libft/ft_printf/ft_int_standcase.c libft/ft_printf/ft_itoa.c \
			 libft/ft_printf/ft_itoabase.c libft/ft_printf/ft_letter.c \
			 libft/ft_printf/ft_printf.c libft/ft_printf/ft_printf_init.c \
			 libft/ft_printf/ft_str_dashcase.c libft/ft_printf/ft_str_standcase.c \
			 libft/ft_printf/ft_unsign.c libft/ft_printf/ft_unsign_dashcase.c \
			 libft/ft_printf/ft_unsign_standcase.c \

CUB3D =	camera.c close.c file_checker.c key.c main.c map_checker.c raycast.c saveimg.c selecpath.c selecrgb.c \
		sprite.c texture.c \

INCLIBC =  libft/libft.h libft/get_next_line.h libft/ft_printf/ft_printf.h cube3d.h 

OBJ = $(patsubst %.c,%.o, $(LIBC) $(LIBCPRINTF))
.PHONY : clean fclean re all
.SILENT : clean fclean re all $(NAME)

all : $(NAME) 

$(NAME) : $(LIBC) $(LIBCPRINTF) $(CUB3D) $(INCLIB) $(OBJ)
		echo "\033[1;33mCUB3D compiling...\033[0m"
		echo "\033[32mCUB3D is ready ! !\033[0m"

%.o : %.c
	@gcc -I. -o $@ -c $<

clean :
	echo "\033[1;33mCleaning Cub3D ...\033[0m"
	rm -f $(OBJ)
	echo "\033[0;35m.o removed.\033[0m"

fclean: clean
	    rm -f $(NAME)
		echo "\033[0;35m$(NAME) removed.\033[0m"
re: fclean all

