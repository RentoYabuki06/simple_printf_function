/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:36:02 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/23 18:10:31 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_print_format_bonus(va_list *args, t_option *option)
{
	int		count_chars;
	char	format;

	format = (*option).specifier;
	count_chars = 0;
	if (format == 'c')
		count_chars += ft_print_char_bonus(va_arg(*args, int), option);
	else if (format == 's')
		count_chars += ft_print_str_bonus(va_arg(*args, char *), option);
	else if (format == 'p')
		count_chars += ft_print_ptr_bonus(va_arg(*args, unsigned long long), option);
	else if (format == 'd' || format == 'i')
		count_chars += ft_print_nbr_bonus(va_arg(*args, int), option);
	else if (format == 'u')
		count_chars += ft_print_unsigned_bonus(va_arg(*args, unsigned int), option);
	else if (format == 'x' || format == 'X')
		count_chars += ft_print_hex_bonus(va_arg(*args, unsigned int), format, option);
	else if (format == '%')
		count_chars += ft_print_percent_bonus(option);
	else
		count_chars = -2;
	return (count_chars);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	int			len_tmp;
	int			parse_len;
	int			len_total_len;
	char		*tmp_format;
	va_list		args;
	t_option	option;
	bool		white_space;

	tmp_format = ft_strdup(format);
	va_start(args, format);
	i = -1;
	len_total_len = 0;
	while (tmp_format[++i])
	{
		white_space = false;
		if (tmp_format[i] == '%')
		{
			ft_bzero(&option, sizeof(t_option));
			parse_len = ft_parse_format(&tmp_format[i + 1], &option, &white_space);
			if (white_space == true)
			{
				i += parse_len;
				len_tmp = parse_len + 1;
			}
			else
			{
				if (parse_len == -1)
				{
					write(STDOUT_FILENO, "%", 1);
					len_total_len++;
					i++;
					continue;
				}
				else if (parse_len == -2)
				{
					len_total_len = -1;
					break ;
				}
				len_tmp = ft_print_format_bonus(&args, &option);
				if (len_tmp == -2)
				{
					if (write(STDOUT_FILENO, "Invalid argument", 17) < 0)
					{
						len_tmp = -1;
						break ;
					}
					i += parse_len;
					len_tmp = 16;
				}
				else 
					i += parse_len;
			}
		}
		else
			len_tmp = ft_put_char(tmp_format[i]);
		if (len_tmp == -1)
		{
			len_total_len = -1;
			break;
		}
		len_total_len += len_tmp;
	}
	free(tmp_format);
	va_end(args);
	return (len_total_len);
}
