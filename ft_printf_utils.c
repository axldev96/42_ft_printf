#include "ft_printf.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	int	result;

	result = write(1, &c, 1);
	if (result == -1)
		return (-1);
	return (result);
}

int	ft_putstr_printf(char *s)
{
	int	count;
	int	re;

	count = 0;
	re = 0;
	if (!s)
	{
		re = write(1, "(null)", 6);
		if (re == -1)
			return (-1);
		return (re);
	}
	while (*s)
	{
		re = ft_putchar(*s++);
		if (re == -1)
			return (-1);
		count += re;
	}
	return (count);
}

int	ft_putnbr_printf(int n)
{
	int	count;
	int	re;

	count = 0;
	re = 0;
	if (n == -2147483648)
	{
		re = write(1, "-2147483648", 11);
		if (re == -1)
			return (-1);
		return (re);
	}
	if (n < 0)
	{
		re = ft_putchar('-');
		if (re == -1)
			return (-1);
		count += re;
		n = n * -1;
	}
	if (n >= 10)
	{
		re = ft_putnbr_printf(n / 10);
		if (re == -1)
			return (-1);
		count += re;
		re = ft_putchar(n % 10 + '0');
		if (re == -1)
			return (-1);
		count += re;
	}
	else
	{
		re = ft_putchar(n + '0');
		if (re == -1)
			return (-1);
		count += re;
	}
	return (count);
}

int	ft_putnbr_base_printf(unsigned long n, char *base)
{
	int	count;
	int	base_len;
	int	re;

	count = 0;
	re = 0;
	base_len = ft_strlen(base);
	if (n >= (unsigned long)base_len)
	{
		re = ft_putnbr_base_printf(n / base_len, base);
		if (re == -1)
			return (-1);
		count += re;
		re = ft_putchar(base[n % base_len]);
		if (re == -1)
			return (-1);
		count += re;
	}
	else
	{
		re = ft_putchar(base[n % base_len]);
		if (re == -1)
			return (-1);
		count += re;
	}
	return (count);
}

int	ft_putptr_printf(void *ptr)
{
	int	count;
	int	re;

	count = 0;
	re = 0;
	re = ft_putstr_printf("0x");
	if (re == -1)
		return (-1);
	count += re;
	re = ft_putnbr_base_printf((unsigned long)ptr, "0123456789abcdef");
	if (re == -1)
		return (-1);
	count += re;
	return (count);
}

int	ft_putunsig_printf(unsigned int n)
{
	int				count;
	unsigned int	nb;
	int				re;

	count = 0;
	nb = n;
	re = 0;
	if (nb >= 10)
	{
		re = ft_putnbr_printf(nb / 10);
		if (re == -1)
			return (-1);
		count += re;
		re = ft_putchar(nb % 10 + '0');
		if (re == -1)
			return (-1);
		count += re;
	}
	else
	{
		re = ft_putchar(nb + '0');
		if (re == -1)
			return (-1);
		count += re;
	}
	return (count);
}
