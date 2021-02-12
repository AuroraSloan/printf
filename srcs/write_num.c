#include "../includes/ft_printf.h"

int			write_symbol(t_info *info)
{
	int ret;

	ret = 0;
	if (info->neg_num)
	{
		ret = write(1, "-", 1);
	}
	else
	{
		if (info->flag[plus])
			ret = write(1, "+", 1);
		else if (info->flag[space])
			ret = write(1, " ", 1);
	}
	return (ret);
}

static int	wrt_num_left_prec(int ret, t_info *info, char *s, char *pad)
{
	int	wid_len;
	int	s_len;
	int	tmp_prec;

	tmp_prec = info->precision;
	s_len = ft_strlen(s);
	wid_len = info->width > info->precision ? info->width : info->precision;
	if (info->flag[plus] || info->flag[space] || info->neg_num)
		wid_len--;
	ret += write_symbol(info);
	while (tmp_prec-- > s_len)
		ret += write(1, "0", 1);
	while (s_len-- > 0)
		ret += write(1, s++, 1);
	while (wid_len-- > info->precision)
		ret += write(1, pad, 1);
	return (ret);
}

int			write_num_left(int ret, t_info *info, char *s, char *pad)
{
	int	wid_len;
	int	s_len;

	s_len = ft_strlen(s);
	wid_len = info->width > s_len ? info->width : 0;
	if (info->precision < s_len)
	{
		if (s[0] == '0' && info->precision == 0 && info->type != 'p')
			s_len--;
		if (info->flag[plus] || info->flag[space] || info->neg_num)
			wid_len--;
		ret += write_symbol(info);
		ret += write(1, s, s_len);
		while (wid_len-- > s_len)
			ret += write(1, pad, 1);
	}
	else
		ret = wrt_num_left_prec(ret, info, s, pad);
	return (ret);
}

static int	wrt_num_right_prec(int ret, t_info *info, char *s, char *pad)
{
	int	wid_len;
	int	s_len;

	s_len = ft_strlen(s);
	wid_len = info->width > info->precision ? info->width : info->precision;
	if (info->flag[plus] || info->flag[space] || info->neg_num)
		wid_len--;
	if (pad[0] == '0')
		ret += write_symbol(info);
	while (wid_len-- > info->precision)
		ret += write(1, pad, 1);
	if (pad[0] == ' ')
		ret += write_symbol(info);
	while (info->precision-- > s_len)
		ret += write(1, "0", 1);
	ret += write(1, s, s_len);
	return (ret);
}

int			write_num_right(int ret, t_info *info, char *s, char *pad)
{
	int	wid_len;
	int	s_len;

	s_len = ft_strlen(s);
	wid_len = info->width > s_len ? info->width : 0;
	if (info->precision < s_len)
	{
		if (s[0] == '0' && info->precision == 0 && info->type != 'p')
			s_len--;
		if (info->flag[plus] || info->flag[space] || info->neg_num)
			wid_len--;
		if (pad[0] == '0')
			ret += write_symbol(info);
		while (wid_len-- > s_len)
			ret += write(1, pad, 1);
		if (pad[0] == ' ')
			ret += write_symbol(info);
		ret += write(1, s, s_len);
	}
	else
		ret = wrt_num_right_prec(ret, info, s, pad);
	return (ret);
}
