/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_space_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:06:42 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 18:03:14 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_put_space_or_zero(int width, int len, t_option *option)
{
	char	c;

	if (len >= width)
		return (EXIT_SUCCESS);
	c = ' ';
	if ((*option).zero_padding == true)
		c = '0';
	while (width - len > 0)
	{
		width--;
		if (write(STDOUT_FILENO, &c, 1) < 0)
			return (-1);
	}
	return (width - len);
}
