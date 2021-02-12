#include "../includes/ft_printf.h"

static int	set_c_s(int ret, t_info *info, va_list args, char *pad)
{
	char	c;
	char	*s;

	c = 0;
	if (info->type == 'c' || info->type == '%')
	{
		c = info->type == 'c' ? va_arg(args, int) : '%';
		ret = write_c(ret, info, c);
	}
	else
	{
		if (!(s = va_arg(args, char *)))
			s = "(null)";
		ret = write_s(ret, info, s, pad);
	}
	return (ret);
}

static int	set_di(int ret, t_info *info, va_list args, char *pad)
{
	int	i;
	char	*num;

	i = va_arg(args, int);
	if (i == 0 && info->precision == 0 && info->width == 1)
		return (write_special_zero(ret, info));
	if (i < 0)
	{
		info->neg_num = '-';
		if (i != -2147483648)
			i = i * -1;
	}
	if (!(num = ft_uitoax(i, info)))
		return (-1);
	if (!(info->flag[minus]))
		ret = write_num_right(ret, info, num, pad);
	else
		ret = write_num_left(ret, info, num, pad);
	free(num);
	return (ret);
}

static int	set_ux(int ret, t_info *info, va_list args, char *pad)
{
	int	i;
	char	*num;

	i = va_arg(args, int);
	if (i == 0)
		info->hashflag = 0;
	if (i == 0 && info->precision == 0 && info->width == 1)
		return (write_special_zero(ret, info));
	if (!(num = ft_uitoax(i, info)))
		return (-1);
	if (!(info->flag[minus]))
		ret = write_num_right(ret, info, num, pad);
	else
		ret = write_num_left(ret, info, num, pad);
	free(num);
	return (ret);
}

static int	set_p(int ret, t_info *info, va_list args, char *pad)
{
	unsigned long long	i;
	char			*num;

	info->flag[plus] = 0;
	info->flag[space] = 0;
	i = (unsigned long long)(va_arg(args, void *));
	if (i == '\0' && info->precision == 0)
		num = ft_strdup("0x");
	else if (i == '\0')
		num = ft_strdup("0x0");
	else if (!(num = ft_ulltox(i)))
		return (-1);
	num[0] = '0';
	num[1] = 'x';
	if (info->flag[minus] == 0)
		ret = write_num_right(ret, info, num, pad);
	else
		ret = write_num_left(ret, info, num, pad);
	free(num);
	return (ret);
}

int		set_conv(int ret, t_info *info, va_list args)
{
	char	*pad;

	if (info->flag[zero] && info->precision < 0)
		pad = "0";
	else
		pad = " ";
	if (info->type == 'n')
		;
	else if (info->type == 'c' || info->type == 's' || info->type == '%')
		ret = set_c_s(ret, info, args, pad);
	else if (info->type == 'd' || info->type == 'i')
		ret = set_di(ret, info, args, pad);
	else if (info->type == 'u' || info->type == 'x' || info->type == 'X')
		ret = set_ux(ret, info, args, pad);
	else if (info->type == 'p')
		ret = set_p(ret, info, args, pad);
	else
		ret = ft_notype(ret, info, pad);
	return (ret);
}
