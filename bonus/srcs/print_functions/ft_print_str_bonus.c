/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:39:03 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 17:20:24 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_str(const char *str, t_option *option)
{
	int	width;
	int	len_str;

	if (!str)
		return (write(STDOUT_FILENO, "(null)", 6));
	width = (*option).width;
	len_str = ft_strlen(str);
	if ((*option).left_aligned == true)
	{
		if (write(STDOUT_FILENO, str, len_str < 0))
			return (-1);
	}
	if (width - len_str > 0)
	{
		if (ft_put_space_or_zero(width - len_str, option) < 0)
			return (-1);
	}
	if ((*option).left_aligned == false)
	{
		if (write(STDOUT_FILENO, str, len_str))
			return (-1);
	}
	return (width);
}
