/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:13:21 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/29 09:41:46 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(char const *str, ...);
int	ft_putchar(char c);
int	ft_putstr_printf(char *s);
int	ft_putnbr_printf(int n, int count, int re);
int	ft_putnbr_base(unsigned long n, char *base);
int	ft_putptr_printf(void *ptr);
int	ft_putunsig_printf(unsigned int n);

#endif
