/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:29:51 by acaceres          #+#    #+#             */
/*   Updated: 2023/05/12 13:32:20 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <string.h>

int main() {
	int		i;
	char	*str;
	void	*ptr;

	i = 3123123;
	str = "Hello, world!";
	ptr = &i;
	// char *s = "The pointer is: 0x7ffee1ef66f8";

	// printf("%zu\n", strlen(s));
	// printf("Printed: %i\n", ft_printf("The pointer is: %p\n", ptr));
	// ft_printf("The number is: %d\n", i);
	// printf("Print: %%%%\n");
	// ft_printf("FT: %%%%\n");
// printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// printf("%s", NULL);
	printf("%i\n", ft_printf("%s\n", "some string with %s hehe"));
	printf("%i\n", printf("%s\n", "some string with %s hehe"));
	// ft_printf("%s", (char *)NULL);
	// printf("%p", ptr);
	// printf("%", i);
	// printf("%", i);
	// printf("%i", i);
	return 0;
}
