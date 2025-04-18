/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:38:35 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 16:38:44 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_hex_len_bonus(unsigned long long num)
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

int	ft_print_hex_bonus(unsigned int nbr, char format, t_option *option)
{
	(void) option;
	if (nbr == 0)
		return (write(STDOUT_FILENO, "0", 1));
	if (0 > ft_put_hex_bonus(nbr, format == 'x'))
		return (-1);
	return(ft_hex_len_bonus(nbr));
}
