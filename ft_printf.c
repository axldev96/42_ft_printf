/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:08:56 by acaceres          #+#    #+#             */
/*   Updated: 2023/05/12 12:08:59 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_flag(const char *str, int i, va_list args, int count);

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		re;

	count = 0;
	i = 0;
	re = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				break ;
			if (str[i] == 'c')
			{
				re = ft_putchar(va_arg(args, int));
				if (re == -1)
					return (-1);
				count += re;
			}
			else if (str[i] == 's')
			{
				re = ft_putstr_printf(va_arg(args, char *));
				if (re == -1)
					return (-1);
				count += re;
			}
			else if (str[i] == 'p')
			{
				re = ft_putptr_printf(va_arg(args, void *));
				if (re == -1)
					return (-1);
				count += re;
			}
			else if (str[i] == 'd' || str[i] == 'i')
			{
				re = ft_putnbr_printf(va_arg(args, int));
				if (re == -1)
					return (-1);
				count += re;
			}
			else if (str[i] == 'u')
			{
				re = ft_putunsig_printf(va_arg(args, unsigned int));
				if (re == -1)
					return (-1);
				count += re;
			}
			else if (str[i] == 'x')
			{
				re = ft_putnbr_base_printf(va_arg(args, unsigned int), "0123456789abcdef");
				if (re == -1)
					return (-1);
				count += re;
			}
			else if (str[i] == 'X')
			{
				re = ft_putnbr_base_printf(va_arg(args, unsigned int), "0123456789ABCDEF");
				if (re == -1)
					return (-1);
				count += re;
			}
			else if (str[i] == '%')
			{
				re = ft_putchar('%');
				if (re == -1)
					return (-1);
				count += re;
			}
			else
				return (-1);
			i++;
		}
		if (str[i] == '\0')
			break ;
		if (str[i] != '%')
		{
			re = ft_putchar(str[i]);
			if (re == -1)
				return (-1);
			count += re;
			i++;
		}
	}
	va_end(args);
	return (count);
}

// int	ft_check_flag(const char *str, int i, va_list args, int count)
// {
// }
