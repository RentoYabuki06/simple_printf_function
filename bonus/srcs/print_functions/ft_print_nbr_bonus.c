/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:38:45 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 20:43:13 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_num_len_bonus(int num, bool is_negative)
{
	int	len;

	len = 0;
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

static int	ft_put_nbr_bonus(int num)
{
	if (num >= 10)
	{
		if (ft_put_nbr_bonus(num / 10) < 0)
			return (-1);
		if (ft_put_nbr_bonus(num % 10) < 0)
			return (-1);
	}
	else
		return (ft_put_char('0' + num));
	return (EXIT_SUCCESS);
}

static int	ft_len_print_num_bonus(int num, t_option *option)
{
	bool	is_negative;
	int 	total_len;

	total_len = 0;
	if (num == 0)
		return (1);
	is_negative = false;
	if (num < 0)
	{
		num *= -1;
		is_negative = true;
	}
	if (is_negative == false && ((*option).show_plus == true || (*option).is_space == true))
		total_len++;
	total_len += ft_num_len_bonus(num, is_negative);
	return (total_len);
}

static int	ft_print_number(int num, int num_len, int num_zero, t_option *option)
{
	bool	is_negative;
	int 	total_len;

	total_len = num_len;
	is_negative = false;
	if (num < 0)
	{
		num *= -1;
		is_negative = true;
		if (ft_put_char('-') < 0)
			return (-1);
	}
	if (ft_put_zero(num_zero) < 0)
		return (-1);
	if (is_negative == false)
	{
		if ((*option).show_plus == true)
		{
			if (ft_put_char('+') < 0)
				return (-1);
		}
		else if ((*option).is_space == true)
		{
			if (ft_put_char(' ') < 0)
				return (-1);
		}
	}
	if (ft_put_nbr_bonus(num) < 0)
		return (-1);
	return (total_len);
}

int	ft_print_nbr_bonus(int num, t_option *option)
{
	int 	total_len;
	int 	num_len;
	int		width;
	int		precision;
	int		len_zero;

	precision = (*option).precision;
	width = (*option).width;
	total_len = width;
	if (num == -2147483648)
		return (ft_print_str_bonus("-2147483648", option));
	num_len = ft_len_print_num_bonus(num, option);
	len_zero = precision - num_len;
	if (len_zero < 0)
		len_zero = 0;
	if (num_len > width)
		total_len = num_len;
	if (total_len < precision)
		total_len = precision;
	if ((*option).left_aligned == true)
	{
		if (num == 0)
		{
			if (ft_put_zero(len_zero + 1) < 0)
				return (-1);
		}
		else if (ft_print_number(num, num_len, len_zero, option) < 0)
			return (-1);
	}
	if (ft_put_space_or_zero(width, num_len + len_zero, option) < 0)
		return (-1);
	if ((*option).left_aligned == false)
	{
		if (num == 0)
		{
			if (ft_put_zero(len_zero + 1) < 0)
				return (-1);
		}
		else if (ft_print_number(num, num_len, len_zero, option) < 0)
			return (-1);
	}
	return (total_len);
}
