/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:39:03 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 19:22:32 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_str_bonus(char *str, t_option *option)
{
	int	len_total;
	int	len_str;
	int	width;

	if (!str)
		return (write(STDOUT_FILENO, "(null)", 6));
	width = (*option).width;
	len_str = ft_strlen(str);
	len_total = len_str;
	if (width > len_str)
		len_total = width;
	if ((*option).left_aligned == true)
	{
		if (write(STDOUT_FILENO, str, len_str) < 0)
			return (-1);
	}
	if (ft_put_space_or_zero(width, len_str, option) < 0)
		return (-1);
	if ((*option).left_aligned == false)
	{
		if (write(STDOUT_FILENO, str, len_str) < 0)
			return (-1);
	}
	return (len_total);
}
