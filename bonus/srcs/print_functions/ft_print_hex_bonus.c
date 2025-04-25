/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:38:35 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/25 20:11:20 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_static_print_hex_bonus(unsigned int num, int len_zero, char format)
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

static int	ft_set_total_len(unsigned int num, int num_len, int total_len, t_option *option)
{
	if ((*option).width < num_len)
		total_len = num_len;
	if (total_len < (*option).precision)
	{
		total_len = (*option).precision;
		if (num != 0 && (*option).alternative_form == true)
			total_len += 2;
	}
	return (total_len);
}

int	ft_print_hex_bonus(unsigned int num, char format, t_option *option)
{
	int	total_len;
	int	num_len;
	int	len_zero;

	total_len = (*option).width;
	num_len = ft_hex_len_bonus(num);
	len_zero = (*option).precision - num_len;
	if (len_zero < 0)
		len_zero = 0;
	if (num != 0 && (*option).alternative_form == true)
		num_len += 2;
	total_len = ft_set_total_len(num, num_len, total_len, option);
	if (((*option).is_space == true || (*option).show_plus == true) && (*option).precision > 0)
		len_zero++;
	if (ft_put_prefix_hex(num, format, option) == EXIT_FAILURE)
		return (-1);
	if ((*option).left_aligned == true)
	{
		if ((*option).precision == 0 && num == 0)
			return (0);
		else if (ft_static_print_hex_bonus(num, len_zero, format) < 0)
			return (-1);
	}
	if (ft_put_space_or_zero((*option).width - len_zero - num_len, option) < 0)
		return (-1);
	if ((*option).left_aligned == false)
	{
		if ((*option).precision == 0 && num == 0)
			return (0);
		else if (ft_static_print_hex_bonus(num, len_zero, format) < 0)
			return (-1);
	}
	return (total_len);
}
