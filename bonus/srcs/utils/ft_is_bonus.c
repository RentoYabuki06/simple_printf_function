/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:28:11 by ryabuki           #+#    #+#             */
/*   Updated: 2025/04/25 21:50:33 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

bool	ft_is_space(char c)
{
	if (c == '\n')
		return (true);
	if (c == '\t')
		return (true);
	if (c == '\f')
		return (true);
	if (c == '\v')
		return (true);
	if (c == '\r')
		return (true);
	return (false);
}

bool	ft_is_flag(char c)
{
	if (c == '-')
		return (true);
	if (c == '+')
		return (true);
	if (c == ' ')
		return (true);
	if (c == '#')
		return (true);
	if (c == '0')
		return (true);
	return (false);
}
