/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_space_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:06:42 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/23 18:21:33 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_put_space_or_zero(int len, t_option *option)
{
	if ((*option).width <= 0)
		return (EXIT_SUCCESS);
	if ((*option).zero_padding == true)
	{
		if (ft_put_zero(len) < 0)
			return (-1);
	}
	else
	{
		if (ft_put_space(len) < 0)
			return (-1);
	}
	return (EXIT_SUCCESS);
}

int	ft_put_zero(int len)
{
	while (len > 0)
	{
		len--;
		if (write(STDOUT_FILENO, "0", 1) < 0)
			return (-1);
	}
	return (EXIT_SUCCESS);
}

int	ft_put_space(int len)
{
	while (len > 0)
	{
		len--;
		if (write(STDOUT_FILENO, " ", 1) < 0)
			return (-1);
	}
	return (EXIT_SUCCESS);
}
