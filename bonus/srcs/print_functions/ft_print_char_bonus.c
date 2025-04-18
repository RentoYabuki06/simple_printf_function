/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:38:28 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 19:21:43 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_char_bonus(int a, t_option *option)
{
	int	width;

	width = (*option).width;
	if ((*option).left_aligned == true)
	{
		if (write(STDOUT_FILENO, &a, 1) < 0)
			return (-1);
	}
	if(ft_put_space_or_zero(width, 1, option) < 0)
		return (-1);
	if ((*option).left_aligned == false)
	{
		if (write(STDOUT_FILENO, &a, 1) < 0)
			return (-1);
	}
	if (width  > 0)
		return (width);
	return (1);
}
