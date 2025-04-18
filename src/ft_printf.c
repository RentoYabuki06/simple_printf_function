/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:04:25 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 13:23:22 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list *args, const char format)
{
	int	count_chars;

	count_chars = 0;
	if (format == 'c')
		count_chars = ft_print_char(va_arg(*args, int));
	else if (format == 's')
		count_chars = ft_print_str(va_arg(*args, char *));
	else if (format == 'p')
		count_chars = ft_print_ptr(va_arg(*args, unsigned long long));
	else if (format == 'd' || format == 'i')
		count_chars = ft_print_nbr(va_arg(*args, int));
	else if (format == 'u')
		count_chars = ft_print_unsigned(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		count_chars = ft_print_hex(va_arg(*args, unsigned int), format);
	else if (format == '%')
		count_chars = ft_print_percent();
	else
		count_chars = ft_print_percent();
	return (count_chars);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len_tmp;
	int		len_total_len;
	va_list	args;

	i = -1;
	len_total_len = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (format[++i] == '\0')
				return (-1);
			len_tmp = ft_format(&args, format[i]);
		}
		else
			len_tmp = ft_print_char(format[i]);
		if (len_tmp < 0)
			return (-1);
		len_total_len += len_tmp;
	}
	va_end(args);
	return (len_total_len);
}
