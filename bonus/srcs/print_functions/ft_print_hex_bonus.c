/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:38:35 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/25 21:50:15 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_static_print_hex(unsigned int num, int len_zero, char format)
{
	if (num == 0)
	{
		if (ft_put_zero(len_zero + 1) < 0)
			return (-1);
	}
	else
	{
		if (ft_put_zero(len_zero) < 0)
			return (-1);
		if (num != 0 && ft_put_hex_bonus(num, format == 'x') < 0)
			return (-1);
	}
	return (1);
}

static int	ft_put_prefix_hex(unsigned int num, char format, t_option *option)
{
	if ((*option).alternative_form == true && num != 0)
	{
		if (format == 'x' && write(STDOUT_FILENO, "0x", 2) < 0)
			return (EXIT_SUCCESS);
		if (format == 'X' && write(STDOUT_FILENO, "0X", 2) < 0)
			return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

static int	ft_total(unsigned int num, int num_len, int ret, t_option *option)
{
	if ((*option).width < num_len)
		ret = num_len;
	if (ret < (*option).precision)
	{
		ret = (*option).precision;
		if (num != 0 && (*option).alternative_form == true)
			ret += 2;
	}
	return (ret);
}

static int	do_print(unsigned int num, char format, t_option *option, int len_z)
{
	if ((*option).precision == 0 && num == 0)
		return (EXIT_SUCCESS);
	else if (ft_static_print_hex(num, len_z, format) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_print_hex_bonus(unsigned int num, char format, t_option *option)
{
	int	total_len;
	int	num_len;
	int	len_zero;

	num_len = ft_hex_len_bonus(num);
	len_zero = (*option).precision - num_len;
	if (len_zero < 0)
		len_zero = 0;
	if (num != 0 && (*option).alternative_form == true)
		num_len += 2;
	total_len = ft_total(num, num_len, (*option).width, option);
	if (((*option).is_space || (*option).show_plus) && (*option).precision > 0)
		len_zero++;
	if (ft_put_prefix_hex(num, format, option) == EXIT_FAILURE)
		return (-1);
	if ((*option).left_aligned == true)
	{
		if (do_print(num, format, option, len_zero) == EXIT_FAILURE)
			return (-1);
	}
	if (ft_put_space_or_zero((*option).width - len_zero - num_len, option) < 0)
		return (-1);
	if ((*option).left_aligned && do_print(num, format, option, len_zero))
		return (-1);
	return (total_len);
}
