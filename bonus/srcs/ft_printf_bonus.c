/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:36:02 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/25 21:18:21 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_print_format_bonus(va_list args, t_option *option)
{
	int		ret;
	char	format;

	format = (*option).specifier;
	ret = 0;
	if (format == 'c')
		ret += ft_print_char_bonus(va_arg(args, int), option);
	else if (format == 's')
		ret += ft_print_str_bonus(va_arg(args, char *), option);
	else if (format == 'p')
		ret += ft_print_ptr_bonus(va_arg(args, unsigned long long), option);
	else if (format == 'd' || format == 'i')
		ret += ft_print_nbr_bonus(va_arg(args, int), option);
	else if (format == 'u')
		ret += ft_print_unsigned_bonus(va_arg(args, unsigned int), option);
	else if (format == 'x' || format == 'X')
		ret += ft_print_hex_bonus(va_arg(args, unsigned int), format, option);
	else if (format == '%')
		ret += ft_print_percent_bonus();
	else
	{
		write(STDOUT_FILENO, "Invalid argument", 17);
		ret = -2;
	}
	return (ret);
}

static int	handle_percent(const char *format, int *i, va_list args, int *ret)
{
	int			parse_len;
	int			len_tmp;
	t_option	option;
	bool		white_space;

	ft_bzero(&option, sizeof(t_option));
	white_space = false;
	parse_len = ft_parse_format(&format[(*i) + 1], &option, &white_space);
	if (white_space)
		return (*i += parse_len, *ret += parse_len + 1, 0);
	if (parse_len == -1)
	{
		write(STDOUT_FILENO, "%", 1);
		(*ret)++;
		(*i)++;
		return (0);
	}
	if (parse_len == -2)
		return (-1);
	len_tmp = ft_print_format_bonus(args, &option);
	if (len_tmp == -2)
		return (*i += parse_len, *ret += 16, 0);
	return (*i += parse_len, *ret += len_tmp, 0);
}

static int	handle_format_loop(const char *tmp_format, va_list args)
{
	int		i;
	int		ret;
	int		len_tmp;

	i = -1;
	ret = 0;
	while (tmp_format[++i])
	{
		if (tmp_format[i] == '%')
		{
			if (handle_percent(tmp_format, &i, args, &ret) < 0)
				return (-1);
		}
		else
		{
			len_tmp = ft_put_char(tmp_format[i]);
			if (len_tmp < 0)
				return (-1);
			ret += len_tmp;
		}
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	char		*tmp_format;
	int			ret;

	tmp_format = ft_strdup(format);
	va_start(args, format);
	ret = handle_format_loop(tmp_format, args);
	va_end(args);
	free(tmp_format);
	return (ret);
}
