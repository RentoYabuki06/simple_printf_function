/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:38:58 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 14:39:00 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_ptr(unsigned long long ptr)
{
	int	len_str;

	if (ptr == 0)
		return (ft_print_str("(nil)"));
	len_str = write(STDOUT_FILENO, "0x", 2);
	if (len_str == -1)
		return (-1);
	else
	{
		if (ft_put_hex(ptr, true) < 0)
			return (-1);
		len_str += ft_hex_len(ptr);
	}
	return (len_str);
}
