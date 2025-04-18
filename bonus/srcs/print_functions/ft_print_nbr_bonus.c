/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:38:45 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 16:39:18 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_num_len(int num, bool is_negative)
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

static int	ft_put_nbr(int num)
{
	if (num >= 10)
	{
		if (ft_put_nbr(num / 10) < 0)
			return (-1);
		if (ft_put_nbr(num % 10) < 0)
			return (-1);
	}
	else
		return (ft_print_char('0' + num));
	return (EXIT_SUCCESS);
}

int	ft_print_nbr_bonus(int num, t_option *option)
{
	bool	is_negative;

	is_negative = false;
	if (num == -2147483648)
		return (ft_print_str("-2147483648"));
	if (num == 0)
		return (ft_print_char('0'));
	if (num < 0)
	{
		num *= -1;
		is_negative = true;
		if (ft_print_char('-') < 0)
			return (-1);
	}
	if (ft_put_nbr(num) < 0)
		return (-1);
	return (ft_num_len(num, is_negative));
}
