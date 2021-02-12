#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "../lib/libft.h"

typedef enum	e_flag
{
	minus,
	zero,
	hash,
	space,
	plus,
	count
}				t_flag;

typedef struct	s_info
{
	int		flag[count];
	int		width;
	int		precision;
	int		has_prec;
	int		type;
	int		neg_num;
	int		hashflag;
}				t_info;

int				ft_printf(const char *fmt, ...);
int				ft_isflag(int c);
int				ft_istype(int c);
int				set_flag(int i, const char *fmt, t_info *info);
int				set_width(int i, const char *fmt, t_info *info, va_list args);
int				set_prec(int i, const char *fmt, t_info *info, va_list args);
int				set_type(int i, const char *fmt, t_info *info);
int				ft_notype(int ret, t_info *info, char *pad);
int				set_conv(int ret, t_info *info, va_list args);
int				write_c(int ret, t_info *info, char c);
int				write_s(int ret, t_info *info, char *s, char *pad);
int				write_symbol(t_info *info);
int				write_num_left(int ret, t_info *info, char *s, char *pad);
int				write_num_right(int ret, t_info *info, char *s, char *pad);
int				write_special_zero(int ret, t_info *info);
char			*ft_uitoax(unsigned int n, t_info *info);
char			*ft_ulltox(unsigned long long n);

#endif
