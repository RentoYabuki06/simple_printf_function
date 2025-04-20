/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:39:03 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/20 11:42:50 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_str_bonus(char *str, t_option *option)
{
	int	len_total;
	int	len_str;
	int	width;
	int precision;
	int	len_space;

	if (!str)
		return (write(STDOUT_FILENO, "(null)", 6));
	precision = (*option).precision;
	width = (*option).width;
	len_str = ft_strlen(str);
	if (precision != -1 && precision < len_str)
		len_str = precision;
	len_space = width - len_str;
	if (len_space < 0)
		len_space = 0;
	len_total = len_str + len_space;
	if ((*option).left_aligned == true)
	{
		if (ft_put_space(len_space) < 0)
			return (-1);
		if (write(STDOUT_FILENO, str, len_str) < 0)
			return (-1);
	}
	if (ft_put_space_or_zero(width, len_str, option) < 0)
		return (-1);
	if ((*option).left_aligned == false)
	{
		if (ft_put_space(len_space) < 0)
			return (-1);
		if (write(STDOUT_FILENO, str, len_str) < 0)
			return (-1);
	}
	return (len_total);
}
