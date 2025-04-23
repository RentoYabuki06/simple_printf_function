/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:34:13 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/23 18:11:45 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// static bool ft_is_specifier(char c)
// {
// 	if (c == 'c')
// 		return (true);
// 	if (c == 's')
// 		return (true);
// 	if (c == 'p')
// 		return (true);
// 	if (c == 'd')
// 		return (true);
// 	if (c == 'i')
// 		return (true);
// 	if (c == 'u')
// 		return (true);
// 	if (c == 'x')
// 		return (true);
// 	if (c == 'X')
// 		return (true);
// 	if (c == '%')
// 		return (true);
// 	return (false);
// }

static bool	ft_is_space(char c)
{
	if (c == '\n')
		return (true);
	if (c == '\t')
		return (true);
	if (c == '\f')
		return (true);
	if (c == '\v')
		return (true);
	if (c == '\r')
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
	int	len;

	len = 0;
	if (n == 0)
		return (1);
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

int	ft_parse_format(char *format, t_option *option, bool *white_space)
{
	int	i;
	int j;

	i = 0;
	if (format[i] == '\0')
		return (-2);
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
	// if (option->width > 0)
	// 	option->left_aligned = false;
	if (option->show_plus == true)
		option->is_space = false;
	if (format[i] == '.')
	{
		if (format[i + 1])
		{			
			i++;
			if (ft_isdigit(format[i]) == true)
			{
				option->precision = ft_atoi(&format[i]);
				i += ft_len_num(option->precision);
			}
			else
			{
				option->precision = 0;
			}
		}
	}
	if (option->left_aligned == true || option->precision != -1)
		option->zero_padding = false;
	if (ft_is_space(format[i]) == true)
	{
		j = 0;
		ft_put_char('%');
		while (j <= i)
		{
			ft_put_char(format[j]);
			j++;
		}
		*white_space = true;
	}
	option->specifier = format[i];
	i++;
	return (i);
}
