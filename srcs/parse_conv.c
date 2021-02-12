#include "../includes/ft_printf.h"

int	set_flag(int i, const char *fmt, t_info *info)
{
	while (ft_isflag(fmt[i]))
	{
		if (fmt[i] == '-')
			info->flag[minus] = 1;
		else if (fmt[i] == '0')
			info->flag[zero] = 1;
		else if (fmt[i] == ' ')
			info->flag[space] = 1;
		else if (fmt[i] == '+')
			info->flag[plus] = 1;
		i++;
	}
	return (i);
}

int	set_width(int i, const char *fmt, t_info *info, va_list args)
{
	if (fmt[i] == '*')
	{
		info->width = va_arg(args, int);
		i++;
	}
	else
	{
		info->width = ft_atoi(&fmt[i]);
		while (ft_isdigit(fmt[i]))
			i++;
	}
	if (info->width < 0 || info->width == -2147483648)
	{
		if (info->width == -2147483648)
			info->width = 2147483647;
		else
			info->width *= -1;
		info->flag[minus] = 1;
	}
	return (i);
}

int	set_prec(int i, const char *fmt, t_info *info, va_list args)
{
	i++;
	if (fmt[i] == '*')
	{
		info->precision = va_arg(args, int);
		i++;
	}
	else if (!ft_isdigit(fmt[i]))
		info->precision = 0;
	else
	{
		info->precision = ft_atoi(&fmt[i]);
		while (ft_isdigit(fmt[i]))
			i++;
	}
	return (i);
}

int	set_type(int i, const char *fmt, t_info *info)
{
	info->type = fmt[i];
	i++;
	return (i);
}

int	ft_notype(int ret, t_info *info, char *pad)
{
	while (info->width-- > 1)
		ret += write(1, pad, 1);
	return (ret);
}
