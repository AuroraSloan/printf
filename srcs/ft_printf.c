#include "../includes/ft_printf.h"

static void	clear_info(t_info *info)
{
	info->flag[minus] = 0;
	info->flag[zero] = 0;
	info->flag[hash] = 0;
	info->flag[space] = 0;
	info->flag[plus] = 0;
	info->width = 0;
	info->precision = -1;
	info->has_prec = 0;
	info->type = 0;
	info->neg_num = 0;
}

static void	sort_flags(t_info *info)
{
	if (info->flag[minus])
		info->flag[zero] = 0;
	if (info->flag[plus])
		info->flag[space] = 0;
	if (info->type == 'u' || info->type == 'x' || info->type == 'X')
	{
		info->flag[plus] = 0;
		info->flag[space] = 0;
	}
}

static int	parse_conv(int i, const char *fmt, t_info *info, va_list args)
{
	int	flag;

	clear_info(info);
	i++;
	if (!fmt[i])
		return (i);
	while (fmt[i] && info->type == 0)
	{
		flag = i;
		if (ft_isflag(fmt[i]))
			i = set_flag(i, fmt, info);
		if (ft_isdigit(fmt[i]) || fmt[i] == '*')
			i = set_width(i, fmt, info, args);
		if (fmt[i] == '.')
			i = set_prec(i, fmt, info, args);
		if (ft_istype(fmt[i]))
			i = set_type(i, fmt, info);
		if (flag == i)
			i++;
	}
	if (fmt[i] == '\0' && info->type == 0)
		i = flag;
	sort_flags(info);
	return (i);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	args;
	int	i;
	int	ret;
	t_info	info;

	ret = 0;
	i = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i = parse_conv(i, fmt, &info, args);
			ret = set_conv(ret, &info, args);
		}
		else if (fmt[i])
			ret += write(1, &fmt[i++], 1);
	}
	va_end(args);
	return (ret);
}
