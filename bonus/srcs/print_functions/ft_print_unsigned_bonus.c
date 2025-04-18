/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:39:10 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 14:39:13 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_len_unsigned_int(unsigned int num)
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

static int	ft_put_unsiged_int(unsigned int num)
{
	if (num >= 10)
	{
		if (ft_put_unsiged_int(num / 10) < 0)
			return (-1);
		if (ft_put_unsiged_int(num % 10) < 0)
			return (-1);
	}
	else
		return (ft_print_char('0' + num));
	return (EXIT_SUCCESS);
}

int	ft_print_unsigned(unsigned int num)
{
	if (num == 0)
		return (ft_print_char('0'));
	if (ft_put_unsiged_int(num) < 0)
		return (-1);
	return (ft_len_unsigned_int(num));
}
