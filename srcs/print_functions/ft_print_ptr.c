/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:45:53 by yabukirento       #+#    #+#             */
/*   Updated: 2024/05/03 16:33:41 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
