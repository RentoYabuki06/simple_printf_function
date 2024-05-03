/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:42:47 by yabukirento       #+#    #+#             */
/*   Updated: 2024/05/03 15:16:22 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_printchar(str[i]);
		i++;
	}
	return (i);
}
