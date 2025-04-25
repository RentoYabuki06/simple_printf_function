/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:34:13 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/25 21:29:49 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

static int	ft_set_option(const char *format, t_option *option)
{
	int	i;

	option->precision = -1;
	option->alternative_form = false;
	option->is_space = false;
	option->left_aligned = false;
	option->width = 0;
	i = 0;
	while (ft_is_flag(format[i]) == true)
		ft_set_flag(format[i++], option);
	if (ft_isdigit(format[i]) == true)
	{
		option->width = ft_atoi(&format[i]);
		i += ft_len_num(option->width);
	}
	if (option->show_plus == true)
		option->is_space = false;
	return (i);
}

static void	ft_if_space(int i, const char *format, bool *flag)
{
	int	j;

	j = 0;
	ft_put_char('%');
	while (j <= i)
	{
		ft_put_char(format[j]);
		j++;
	}
	*flag = true;
}

int	ft_parse_format(const char *format, t_option *option, bool *flag)
{
	int	i;

	if (format[0] == '\0')
		return (-2);
	i = ft_set_option(format, option);
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
				option->precision = 0;
		}
	}
	if (option->left_aligned == true || option->precision != -1)
		option->zero_padding = false;
	if (ft_is_space(format[i]) == true)
		ft_if_space(i, format, flag);
	option->specifier = format[i];
	return (++i);
}
