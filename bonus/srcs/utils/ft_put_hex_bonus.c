/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:50:10 by ryabuki           #+#    #+#             */
/*   Updated: 2025/04/25 20:45:16 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_hex_len_bonus(unsigned long long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
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
