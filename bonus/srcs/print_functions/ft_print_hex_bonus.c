/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:38:35 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 18:36:57 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_hex_len_bonus(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

int	ft_put_hex_bonus(unsigned long long num, bool is_lower)
{
	if (num >= 16)
	{
		if (ft_put_hex_bonus(num / 16, is_lower) < 0)
			return (-1);
		if (ft_put_hex_bonus(num % 16, is_lower) < 0)
			return (-1);
	}
	else
	{
		if (num <= 9)
			return (ft_put_char('0' + num));
		else
		{
			if (is_lower == true)
				return (ft_put_char('a' + num - 10));
			else
				return (ft_put_char('A' + num - 10));
		}
	}
	return (EXIT_SUCCESS);
}

int	ft_print_hex_bonus(unsigned int num, char format, t_option *option)
{
	int	width;
	int	total_len;
	int	num_len;

	width = (*option).width;
	total_len = width;
	num_len = ft_hex_len_bonus(num);
	if (num_len > width)
		total_len = num_len;
	if (num == 0)
		return (ft_put_char('0'));
	if ((*option).left_aligned == true)
	{
		if (ft_put_hex_bonus(num, format == 'x') < 0)
			return (-1);
	}
	if (ft_put_space_or_zero(width, num_len, option) < 0)
		return (-1);
	if ((*option).left_aligned == false)
	{
		if (ft_put_hex_bonus(num, format == 'x') < 0)
			return (-1);
	}
	return (total_len);
}
