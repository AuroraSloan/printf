#include "../includes/ft_printf.h"

int		write_special_zero(int ret, t_info *info)
{
	ret += write_symbol(info);
	if (!info->flag[plus] && !info->flag[space])
		ret += write(1, " ", 1);
	return (ret);
}

int		ft_isflag(int c)
{
	return (c == '-' || c == '0' || c == ' ' || c == '+');
}

int		ft_istype(int c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 's' || c == 'c' ||
			c == 'x' || c == 'X' || c == 'p' || c == '%' || c == 'n');
}

char	*ft_uitoax(unsigned int n, t_info *info)
{
	char	*str;
	int		len;
	int		base;
	char	*hex;

	base = info->type == 'x' || info->type == 'X' ? 16 : 10;
	hex = info->type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
	len = ft_numlen(n, base);
	if (!(str = (char*)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[len--] = hex[n % base];
		n /= base;
	}
	return (str);
}

char	*ft_ulltox(unsigned long long n)
{
	char	*hex;
	int		len;
	char	*str;

	hex = "0123456789abcdef";
	len = ft_numlen(n, 16) + 2;
	if (!(str = (char*)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[len--] = hex[n % 16];
		n /= 16;
	}
	return (str);
}
