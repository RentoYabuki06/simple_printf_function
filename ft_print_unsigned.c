/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:52:58 by yabukirento       #+#    #+#             */
/*   Updated: 2024/05/03 15:54:10 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int a)
{
	int		count;
	char	*tmp;

	count = 0;
	tmp = ft_itoa(a);
	if (!tmp)
		return (-1);
	count += ft_printstr(tmp);
	free(tmp);
	return (count);
}
