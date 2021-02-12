#include "../includes/ft_printf.h"

int	write_c(int ret, t_info *info, char c)
{
	int		wid_len;
	char	*pad;

	if (info->type == '%' && info->flag[zero])
		pad = "0";
	else
		pad = " ";
	wid_len = info->width > 1 ? info->width : 0;
	if (info->flag[minus] == 0)
	{
		while (wid_len-- > 1)
			ret += write(1, pad, 1);
		ret += write(1, &c, 1);
	}
	else if (info->flag[minus] == 1)
	{
		ret += write(1, &c, 1);
		while (wid_len-- > 1)
			ret += write(1, " ", 1);
	}
	return (ret);
}

int	write_s(int ret, t_info *info, char *s, char *pad)
{
	int len;
	int	tmp;

	if (info->precision >= 0 && info->precision < (int)(ft_strlen(s)))
		info->has_prec = 1;
	len = info->has_prec ? info->precision : (int)(ft_strlen(s));
	tmp = len;
	if (!(info->flag[minus]))
	{
		while (info->width-- > len)
			ret += write(1, pad, 1);
		ret += write(1, s, len);
	}
	else
	{
		info->width = info->width > len ? info->width : len;
		while (len-- > 0)
			ret += write(1, s++, 1);
		while (info->width-- > tmp)
			ret += write(1, pad, 1);
	}
	return (ret);
}
