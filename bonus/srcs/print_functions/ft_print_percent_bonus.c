/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:38:52 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/23 16:39:19 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_percent_bonus(t_option *option)
{
	(void)	option;

	if (write(STDOUT_FILENO, "%", 1) < 0)
		return (-1);
	return (1);
}
