/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:26:39 by ryabuki           #+#    #+#             */
/*   Updated: 2025/04/25 20:45:54 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

int	ft_print_number(int num, int num_len, int len_zero, t_option *option)
{
	bool	is_negative;

	is_negative = false;
	if ((*option).is_space == true)
	{
		if (ft_put_char(' ') < 0)
			return (-1);
	}
	if (num < 0)
	{
		num *= -1;
		is_negative = true;
		if (ft_put_char('-') < 0)
			return (-1);
	}
	if (is_negative == false && (*option).show_plus == true)
	{
		if (ft_put_char('+') < 0)
			return (-1);
	}
	if (ft_put_zero(len_zero) < 0)
		return (-1);
	if (ft_put_nbr_bonus(num) < 0)
		return (-1);
	return (num_len);
}
