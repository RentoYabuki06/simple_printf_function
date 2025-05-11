/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:04:41 by yabukirento       #+#    #+#             */
/*   Updated: 2025/05/11 10:20:16 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned long long num)
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

int	ft_put_hex(unsigned long long num, bool is_lower)
{
	if (num >= 16)
	{
		if (ft_put_hex(num / 16, is_lower) < 0)
			return (-1);
		if (ft_put_hex(num % 16, is_lower) < 0)
			return (-1);
	}
	else
	{
		if (num <= 9)
			return (ft_print_char('0' + num));
		else
		{
			if (is_lower == true)
				return (ft_print_char('a' + num - 10));
			else
				return (ft_print_char('A' + num - 10));
		}
	}
	return (EXIT_SUCCESS);
}

int	ft_print_hex(unsigned int nbr, char format)
{
	if (nbr == 0)
		return (write(STDOUT_FILENO, "0", 1));
	if (0 > ft_put_hex(nbr, format == 'x'))
		return (-1);
	return (ft_hex_len(nbr));
}
