/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:38:58 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/23 12:24:05 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_ptr_bonus(unsigned long long ptr, t_option *option)
{
	int	width;
	int	total_len;
	int	ptr_len;
	
	if (ptr == 0)
		return (write(STDOUT_FILENO, "(nil)", 5));
	width = (*option).width;
	total_len = width;
	ptr_len = ft_hex_len_bonus(ptr) + 2;
	if (ptr_len > width)
		total_len = ptr_len;
	if ((*option).left_aligned == true)
	{
		if (write(STDOUT_FILENO, "0x", 2) < 0)
			return (-1);
		if (ft_put_hex_bonus(ptr, true) < 0)
			return (-1);
	}
	if (ft_put_space_or_zero(width, ptr_len, option) < 0)
		return (-1);
	if ((*option).left_aligned == false)
	{
		if (write(STDOUT_FILENO, "0x", 2) < 0)
			return (-1);
		if (ft_put_hex_bonus(ptr, true) < 0)
			return (-1);
	}
	return (total_len);
}
