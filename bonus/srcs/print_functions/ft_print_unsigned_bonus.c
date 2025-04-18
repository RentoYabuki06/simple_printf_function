/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:39:10 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 18:37:37 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_len_unsigned_int_bonus(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static int	ft_put_unsiged_int_bonus(unsigned int num)
{
	if (num >= 10)
	{
		if (ft_put_unsiged_int_bonus(num / 10) < 0)
			return (-1);
		if (ft_put_unsiged_int_bonus(num % 10) < 0)
			return (-1);
	}
	else
		return (ft_put_char('0' + num));
	return (EXIT_SUCCESS);
}

int	ft_print_unsigned_bonus(unsigned int num, t_option *option)
{
	int	width;
	int	total_len;
	int	num_len;

	width = (*option).width;
	total_len = width;
	num_len = ft_len_unsigned_int_bonus(num);
	if (num_len > width)
		total_len = num_len;
	if (num == 0)
		return (ft_put_char('0'));
	if ((*option).left_aligned == true)
	{
		if (ft_put_unsiged_int_bonus(num) < 0)
			return (-1);
	}
	if (ft_put_space_or_zero(width, num_len, option) < 0)
		return (-1);
	if ((*option).left_aligned == false)
	{
		if (ft_put_unsiged_int_bonus(num) < 0)
			return (-1);
	}
	return (total_len);
}
