/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:38:45 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/25 20:43:51 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_num_len_bonus(int num, bool is_negative)
{
	int	len;

	len = 0;
	if (num == -2147483648)
		return (11);
	if (is_negative == true)
		len++;
	if (num == 0)
		return (len + 1);
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static int	ft_len_print_num_bonus(int num, t_option *option)
{
	bool	is_negative;
	int		total_len;

	total_len = 0;
	if (num == 0)
		return (1);
	is_negative = false;
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		num *= -1;
		is_negative = true;
	}
	if (!is_negative && ((*option).show_plus || (*option).is_space))
		total_len++;
	total_len += ft_num_len_bonus(num, is_negative);
	return (total_len);
}

static int	ft_preput_nbr(int num, int num_len, int len_zero, t_option *option)
{
	if (num == 0)
	{
		if (ft_put_zero(len_zero + 1) < 0)
			return (EXIT_FAILURE);
	}
	else if (ft_print_number(num, num_len, len_zero, option) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_ret_calc(int num_len, t_option *option)
{
	int	total_len;

	total_len = (*option).width;
	if (num_len > (*option).width)
		total_len = num_len;
	if (total_len < (*option).precision)
		total_len = (*option).precision;
	return (total_len);
}

int	ft_print_nbr_bonus(int num, t_option *option)
{
	int		num_len;
	int		len_zero;

	if (num < 0)
		(*option).is_space = false;
	num_len = ft_len_print_num_bonus(num, option);
	len_zero = (*option).precision - num_len;
	if (len_zero < 0)
		len_zero = 0;
	if (((*option).is_space || (*option).show_plus) && (*option).precision > 0)
		len_zero++;
	if ((*option).left_aligned == true)
	{
		if (ft_preput_nbr(num, num_len, len_zero, option) == EXIT_FAILURE)
			return (-1);
	}
	if (ft_put_space_or_zero((*option).width - len_zero - num_len, option) < 0)
		return (-1);
	if ((*option).left_aligned == false)
	{
		if (ft_preput_nbr(num, num_len, len_zero, option) == EXIT_FAILURE)
			return (-1);
	}
	return (ft_ret_calc(num_len, option));
}
