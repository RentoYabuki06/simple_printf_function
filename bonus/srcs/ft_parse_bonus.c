/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:34:13 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 19:59:38 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static bool ft_is_specifier(char c)
{
	if (c == 'c')
		return (true);
	if (c == 's')
		return (true);
	if (c == 'p')
		return (true);
	if (c == 'd')
		return (true);
	if (c == 'i')
		return (true);
	if (c == 'u')
		return (true);
	if (c == 'x')
		return (true);
	if (c == 'X')
		return (true);
	if (c == '%')
		return (true);
	return (false);
}

static bool	ft_is_flag(char c)
{
	if (c == '-')
		return (true);
	if (c == '+')
		return (true);
	if (c == ' ')
		return (true);
	if (c == '#')
		return (true);
	if (c == '0')
		return (true);
	return (false);
}

static int	ft_len_num(int n)
{
	size_t	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_set_flag(char c, t_option *option)
{
	if (c == '-')
		option->left_aligned = true;
	if (c == '+')
		option->show_plus = true;
	if (c == ' ')
		option->is_space = true;
	if (c == '#')
		option->alternative_form = true;
	if (c == '0')
		option->zero_padding = true;
}

int	ft_parse_format(char *format, t_option *option)
{
	int	i;

	i = 0;
	option->precision = -1;
	option->alternative_form = false;
	option->is_space = false;
	option->left_aligned = false;
	option->width = 0;
	while (ft_is_flag(format[i]) == true)
		ft_set_flag(format[i++], option);
	if (ft_isdigit(format[i]) == true)
	{
		option->width = ft_atoi(&format[i]);
		i += ft_len_num(option->width);
	}
	if (option->width > 0)
		option->left_aligned = false;
	if (option->show_plus == true)
		option->is_space = false;
	if (option->left_aligned == true || option->precision != -1)
		option->zero_padding = false;
	if (format[i] == '.')
	{
		option->precision = ft_atoi(&format[++i]);
		i += ft_len_num(option->precision);
	}
	if (format[i] == '\0')
		return (-2);
	if (ft_is_specifier(format[i]) == false)
		return (-1);
	option->specifier = format[i];
	i++;
	return (i);
}
