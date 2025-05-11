/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:39:10 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/11 10:08:20 by ryabuki          ###   ########.fr       */
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

static int	ft_unsigned_helper(unsigned int num, int len_zero, t_option *option)
{
	if (option->precision == 0)
		return (EXIT_SUCCESS);
	if (num == 0)
	{
		if (ft_put_zero(len_zero + 1) < 0)
			return (EXIT_FAILURE);
	}
	else
	{
		if (ft_put_zero(len_zero) < 0)
			return (EXIT_FAILURE);
		if (ft_put_unsiged_int_bonus(num) < 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	ft_set_total_len(int num_len, int total_len, t_option *option)
{
	if ((*option).width < num_len)
		total_len = num_len;
	if (total_len < (*option).precision)
		total_len = (*option).precision;
	if ((*option).precision == 0 && (*option).width == 0)
		total_len = 0;
	return (total_len);
}

int	ft_print_unsigned_bonus(unsigned int num, t_option *option)
{
	int	total_len;
	int	num_len;
	int	len_zero;

	num_len = ft_len_unsigned_int_bonus(num);
	len_zero = (*option).precision - num_len;
	if (len_zero < 0)
		len_zero = 0;
	total_len = ft_set_total_len(num_len, (*option).width, option);
	if ((*option).left_aligned == true)
	{
		if (ft_unsigned_helper(num, len_zero, option) == EXIT_FAILURE)
			return (-1);
	}
	if (ft_put_space_or_zero((*option).width - len_zero - num_len, option) < 0)
		return (-1);
	if ((*option).left_aligned == false)
	{
		if (ft_unsigned_helper(num, len_zero, option) == EXIT_FAILURE)
			return (-1);
	}
	return (total_len);
}
