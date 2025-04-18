/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:38:45 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 18:38:23 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_num_len_bonus(int num, bool is_negative)
{
	int	len;

	len = 0;
	if (is_negative == true)
		len++;
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
	is_negative = false;
	if (num < 0)
	{
		num *= -1;
		is_negative = true;
		total_len++;
	}
	if (is_negative == false && ((*option).show_plus == true || (*option).is_space == true))
		total_len++;
	total_len += ft_num_len_bonus(num, is_negative);
	return (total_len);
}

static int	ft_print_number(int num, t_option *option)
{
	bool	is_negative;
	int 	total_len;

	total_len = ft_len_print_num_bonus(num, option);
	is_negative = false;
	if (num < 0)
	{
		num *= -1;
		is_negative = true;
		if (ft_put_char('-') < 0)
			return (-1);
	}
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

	width = (*option).width;
	total_len = width;
	if (num == -2147483648)
		return (ft_print_str_bonus("-2147483648", option));
	if (num == 0)
		return (ft_put_char('0'));
	num_len = ft_len_print_num_bonus(num, option);
	if (num_len > width)
		total_len = num_len;
	if ((*option).left_aligned == true)
	{
		if (ft_print_number(num, option) < 0)
			return (-1);
	}
	if (ft_put_space_or_zero(width, num_len, option) < 0)
		return (-1);
	if ((*option).left_aligned == false)
	{
		if (ft_print_number(num, option) < 0)
			return (-1);
	}
	return (total_len);
}
