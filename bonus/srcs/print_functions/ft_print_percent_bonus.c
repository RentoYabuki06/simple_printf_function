/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:38:52 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 17:24:13 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_percent(t_option *option)
{
	int	width;

	width = (*option).width;
	if ((*option).left_aligned == true)
	{
		if (write(STDOUT_FILENO, "%", 1) < 0)
			return (-1);
	}
	if (width > 1)
	{
		if(ft_put_space_or_zero(width - 1, option) < 0)
			return (-1);
	}
	if ((*option).left_aligned == false)
	{
		if (write(STDOUT_FILENO, "%", 1) < 0)
			return (-1);
	}
	return (width);
}
