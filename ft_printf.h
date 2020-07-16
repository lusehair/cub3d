/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:40:13 by lusehair          #+#    #+#             */
/*   Updated: 2020/03/11 12:41:54 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct		s_printf
{
	char			with;
	int				nb;
	int				pres;
	char			dot;
	char			zero;
	char			dash;
	int				res;
	int				integer;
	int				string;
	int				adr;
	int				unsign;
	int				character;
	int				hexa;
	int				hexxa;
	int				perc;
	long long int	aadr;
	size_t			size;
	unsigned int	vunsign;
}					t_printf;

int					ft_dectoocta(unsigned int value);
void				ft_t_printfreset(t_printf *reseter);
int					ft_optionselector(const char *format, t_printf *o,
		va_list arglist);
int					ft_flagcheck(char c);
int					ft_parser(const char *format, t_printf *o,
		va_list arglist);
void				ft_conv(const char *format, t_printf *o, int *i);
int					ft_ifint(t_printf *o, int argum);
int					ft_dashint_wdot(char *a_argum, int size, t_printf *o,
		int value);
int					ft_dashint_onlyw(char *a_argum, int size, t_printf *o);
int					ft_intlarg(t_printf *o, int size, int value);
int					ft_int_prec(t_printf *o, int size, int value);
int					ft_intlargecase(t_printf *o, char *a_argum, int value,
		int larg);
int					ft_intpreccase(t_printf *o, char *a_argum, int value,
		int size);
int					ft_intothercase(t_printf *o, char *a_argum, int value,
		int prec);
int					ft_int_dashlarge(t_printf *o, char *a_argum, int value,
		int larg);
int					ft_int_dashcasucase(t_printf *o, char *a_argum, int value,
		int size);
int					ft_ifchar(t_printf *o, char *argum);
int					ft_strlarg(t_printf *o, size_t size);
int					ft_strprec(t_printf *o, size_t size);
int					ft_strdashlarg(t_printf *o, size_t size, char *string);
int					ft_strdashlarpre(t_printf *o, size_t size, char *string);
int					ft_standstrprec(t_printf *o, size_t size, char *string);
int					ft_standstrlarg(t_printf *o, size_t size, char *string);
int					ft_standstrlargprec(t_printf *o, size_t size, char *string);
int					ft_unsign_prec(t_printf *o, int size, unsigned int val);
int					ft_unsignlarg(t_printf *o, int size, unsigned int val);
int					ft_unsign(t_printf *o, unsigned int argum);
int					ft_unsign_dashcasucase(t_printf *o, char *a_argum,
		int larg, int prec);
int					ft_unsign_dashlarge(t_printf *o, char *a_arg,
		unsigned int val, int lar);
int					ft_unsignlargecase(t_printf *o, char *a_arg,
		unsigned int val, int lar);
int					ft_unsignpreccase(t_printf *o, char *a_argum,
		unsigned int value, int size);
int					ft_unsignothercase(t_printf *o, char *a_arg,
		unsigned int val, int pre);
char				*ft_uitoa(unsigned int n);
int					ft_adress(t_printf *o, unsigned long long int argum);
int					ft_hexa(t_printf *o, unsigned int argum, char c);
void				ft_letter(t_printf *o, int argum);
void				ft_standcharlarg(t_printf *o, size_t size, char c);
void				ft_dashdashlarg(t_printf *o, size_t size, char c);
void				ft_putchar(char c);
void				ft_putstr(char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
char				*ft_aitoabase(long long int value, int base, char set);
void				*ft_calloc(size_t nb, size_t size);
void				*ft_memalloc(size_t size);
char				*ft_itoa(int n);
char				*ft_uitoa(unsigned int n);
void				ft_putnbr(int n);
void				ft_uputnbr(unsigned int n);
size_t				ft_strlen(const char *str);
char				*ft_itoabase(unsigned int value, int base, char set);
char				*ft_strrev(char *str);
char				*ft_strdup(const char *s1);
int					ft_convcheck(char c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_intlargecase2(t_printf *o, char *a_argum, int value,
		int larg);
int					ft_intpreccase2(t_printf *o, int value, int larg, int prec);
int					ft_ifchar2(t_printf *o, char *string, size_t size);
int					ft_ifchar3(t_printf *o, char *string, size_t size);
int					ft_int_dashcasucase2(int value, int larg, int prec);
int					ft_init2(t_printf *o, char *a_argum, int value, int larg);
size_t				ft_adrelse(t_printf *o, char *a_argum, const char *addr_str,
		long long int argum);
int					ft_conv2(const char *format, t_printf *o, int *i);
int					ft_conv3(const char *format, t_printf *o, int *i);
int					ft_parser2(const char *format, t_printf *o, va_list arglist,
		int *i);
void				ft_parser3(t_printf *o);
int					ft_hexa2(t_printf *o, char *a_argum, int size,
		unsigned int value);
int					ft_unsign2(t_printf *o, char *a_argum, int value, int larg);
int					ft_unsignlargecase2(t_printf *o, char *a_argum, int larg);
char				*ft_adress2(t_printf *o, const char *addr_str);
void				ft_adress3(t_printf *o, char *a_argum,
		const char *addr_str);
void				ft_domagic(t_printf *o, va_list arglist);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_printf(const char *format, ...);
void				*ft_memset(void *str, int c, size_t size);
int					ft_hexpreccase(t_printf *o, char *a_argum,
		unsigned int value, int size);
#endif
