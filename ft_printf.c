/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:04:25 by yabukirento       #+#    #+#             */
/*   Updated: 2024/05/04 17:37:07 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len_tmp;
	int		len_total_len;
	va_list	args;

	i = 0;
	len_total_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			len_tmp = ft_format(&args, format[++i]);
		else
			len_tmp = ft_printchar(format[i]);
		if (len_tmp >= 0)
			len_total_len += len_tmp;
		else
			return (-1);
		i++;
	}
	va_end(args);
	return (len_total_len);
}

// int	main() {
//     // Test cases for %c
// 	printf("---------------------- test for c option --------------------\n");
//     printf("printf:    %c%c\n", 'A', '1');
//     ft_printf("ft_printf: %c%c\n", 'A', '1');
//     printf("printf:    %c%c\n", 'Z', '1');
//     ft_printf("ft_printf: %c%c\n", 'Z', '1');
//     printf("printf:    %c\n", '0');
//     ft_printf("ft_printf: %c\n", '0');
//     printf("printf:    %c\n", '9');
//     ft_printf("ft_printf: %c\n", '9');
//     printf("printf:    %c\n", ' ');
//     ft_printf("ft_printf: %c\n", ' ');
//     printf("printf:    %c\n", '~');
//     ft_printf("ft_printf: %c\n", '~');
//     printf("printf:    %c\n", '\n');
//     ft_printf("ft_printf: %c\n", '\n');
//     printf("printf:    %c\n", '\t');
//     ft_printf("ft_printf: %c\n", '\t');
//     printf("printf:    %c\n", '\0');
//     ft_printf("ft_printf: %c\n", '\0');
//     printf("printf:    %c\n", 255);
//     ft_printf("ft_printf: %c\n", 255);

//     // Test cases for %s
// 	printf("---------------------- test for s option --------------------\n");
//     printf("printf:    %s\n", "Hello, world!");
//     ft_printf("ft_printf: %s\n", "Hello, world!");
//     printf("printf:    %s\n", "");
//     ft_printf("ft_printf: %s\n", "");
//     printf("printf:    %s\n", "123");
//     ft_printf("ft_printf: %s\n", "123");
//     printf("printf:    %s\n", "!@#$%^&*()_+");
//     ft_printf("ft_printf: %s\n", "!@#$%^&*()_+");
//     printf("printf:    %s\n", "アイウエオ");
//     ft_printf("ft_printf: %s\n", "アイウエオ");
//     printf("printf:    %s\n", "😀😃😄😁");
//     ft_printf("ft_printf: %s\n", "😀😃😄😁");
//     printf("printf:    %s\n", "long long long long long string");
//     ft_printf("ft_printf: %s\n", "long long long long long string");
//     printf("printf:    %s\n", (char *)NULL);
//     ft_printf("ft_printf: %s\n", (char *)NULL);
//     printf("printf:    %s\n", "\\n\\t\\r\\b\\a");
//     ft_printf("ft_printf: %s\n", "\\n\\t\\r\\b\\a");
//     printf("printf:    %s%s\n", "Hello", ", world!");
//     ft_printf("ft_printf: %s%s\n", "Hello", ", world!");

//     // Test cases for %p
// 	printf("---------------------- test for p option --------------------\n");
//     printf("printf:    %p\n", (void *)0);
//     ft_printf("ft_printf: %p\n", (void *)0);
//     printf("printf:    %p\n", (void *)1);
//     ft_printf("ft_printf: %p\n", (void *)1);
//     printf("printf:    %p\n", (void *)0x1234abcd);
//     ft_printf("ft_printf: %p\n", (void *)0x1234abcd);
//     printf("printf:    %p\n", (void *)0x7fffffffdeb0);
//     ft_printf("ft_printf: %p\n", (void *)0x7fffffffdeb0);
//     printf("printf:    %p\n", (void *)0xffffffffffffffff);
//     ft_printf("ft_printf: %p\n", (void *)0xffffffffffffffff);
//     printf("printf:    %p\n", (void *)main);
//     ft_printf("ft_printf: %p\n", (void *)main);
//     printf("printf:    %p\n", NULL);
//     ft_printf("ft_printf: %p\n", NULL);
//     printf("printf:    %p %p\n", (void *)0, (void *)0);
//     ft_printf("ft_printf: %p %p\n", (void *)0, (void *)0);
//     printf("printf:    %p %p\n", (void *)0, (void *)1);
//     ft_printf("ft_printf: %p %p\n", (void *)0, (void *)1);
//     printf("printf:    %p %p\n", (void *)1, (void *)0);
//     ft_printf("ft_printf: %p %p\n", (void *)1, (void *)0);

//     // Test cases for %d and %i
// 	printf("---------------------- test for d and i option --------------------\n");
//     printf("printf:    %d\n", 0);
//     ft_printf("ft_printf: %d\n", 0);
//     printf("printf:    %d\n", 42);
//     ft_printf("ft_printf: %d\n", 42);
//     printf("printf:    %d\n", -42);
//     ft_printf("ft_printf: %d\n", -42);
//     printf("printf:    %d\n", 2147483647);
//     ft_printf("ft_printf: %d\n", 2147483647);
//     printf("printf:    %d\n", -2147483648);
//     ft_printf("ft_printf: %d\n", -2147483648);
//     printf("printf:    %i\n", 0);
//     ft_printf("ft_printf: %i\n", 0);
//     printf("printf:    %i\n", 42);
//     ft_printf("ft_printf: %i\n", 42);
//     printf("printf:    %i\n", -42);
//     ft_printf("ft_printf: %i\n", -42);
//     printf("printf:    %i\n", 2147483647);
//     ft_printf("ft_printf: %i\n", 2147483647);
//     printf("printf:    %i\n", -2147483648);
//     ft_printf("ft_printf: %i\n", -2147483648);

//     // Test cases for %x and %X
// 	printf("---------------------- test for x and X option --------------------\n");
//     printf("printf:    %x\n", 0);
//     ft_printf("ft_printf: %x\n", 0);
//     printf("printf:    %x\n", 42);
//     ft_printf("ft_printf: %x\n", 42);
//     printf("printf:    %x\n", -42);
//     ft_printf("ft_printf: %x\n", -42);
//     printf("printf:    %x\n", 2147483647);
//     ft_printf("ft_printf: %x\n", 2147483647);
//     printf("printf:    %x\n", -2147483648);
//     ft_printf("ft_printf: %x\n", -2147483648);
//     printf("printf:    %X\n", 0);
//     ft_printf("ft_printf: %X\n", 0);
//     printf("printf:    %X\n", 42);
//     ft_printf("ft_printf: %X\n", 42);
//     printf("printf:    %X\n", -42);
//     ft_printf("ft_printf: %X\n", -42);
//     printf("printf:    %X\n", 2147483647);
//     ft_printf("ft_printf: %X\n", 2147483647);
//     printf("printf:    %X\n", -2147483648);
//     ft_printf("ft_printf: %X\n", -2147483648);

//     // Test cases for %u
// 	printf("---------------------- test for u option --------------------\n");
//     printf("printf:    %u\n", 0);
//     ft_printf("ft_printf: %u\n", 0);
//     printf("printf:    %u\n", 42);
//     ft_printf("ft_printf: %u\n", 42);
//     printf("printf:    %u\n", -42);
//     ft_printf("ft_printf: %u\n", -42);
//     printf("printf:    %u\n", 2147483647);
//     ft_printf("ft_printf: %u\n", 2147483647);
//     printf("printf:    %u\n", -2147483648);
//     ft_printf("ft_printf: %u\n", -2147483648);
//     printf("printf:    %u\n", 4294967295);
//     ft_printf("ft_printf: %u\n", 4294967295);
//     printf("printf:    %u\n", -1);
//     ft_printf("ft_printf: %u\n", -1);
//     printf("printf:    %u\n", 0x7fffffff);
//     ft_printf("ft_printf: %u\n", 0x7fffffff);
//     printf("printf:    %u\n", 0x80000000);
//     ft_printf("ft_printf: %u\n", 0x80000000);
//     printf("printf:    %u\n", 0xffffffff);
//     ft_printf("ft_printf: %u\n", 0xffffffff);

//     // Test cases for %%
// 	printf("---------------------- test for % option --------------------\n");
//     printf("printf:    %%\n");
//     ft_printf("ft_printf: %%\n");
//     printf("printf:    %%%%\n");
//     ft_printf("ft_printf: %%%%\n");
//     printf("printf:    %%%%%\n");
//     ft_printf("ft_printf: %%%%%\n");
//     printf("printf:    %%%%%%\n");
//     ft_printf("ft_printf: %%%%%%\n");
//     printf("printf:    %%%%%%%\n");
//     ft_printf("ft_printf: %%%%%%%\n");
//     printf("printf:    %%%%%%%%\n");
//     ft_printf("ft_printf: %%%%%%%%\n");
//     printf("printf:    %%%%%%%%%\n");
//     ft_printf("ft_printf: %%%%%%%%%\n");
//     printf("printf:    %%%%%%%%%%\n");
//     ft_printf("ft_printf: %%%%%%%%%%\n");
//     printf("printf:    %%%%%%%%%%%\n");
//     ft_printf("ft_printf: %%%%%%%%%%%\n");
//     printf("printf:    %%%%%%%%%%%%\n");
//     ft_printf("ft_printf: %%%%%%%%%%%%\n");

//     return 0;
// }

