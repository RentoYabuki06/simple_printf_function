/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_space_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:06:42 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 17:22:47 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_put_space_or_zero(int width, t_option *option)
{
	char	c;

	if (width <= 0)
		return (-1);
	c = ' ';
	if ((*option).zero_padding == true)
		c = '0';
	while (width > 0)
	{
		width--;
		if (write(STDOUT_FILENO, &c, 1) < 0)
			return (-1);
	}
	return (width);
}
