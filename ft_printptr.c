/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:45:53 by yabukirento       #+#    #+#             */
/*   Updated: 2024/05/03 15:14:01 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long long a)
{
	int		count;
	char	*tmp;

	count = 0;
	tmp = ft_ulitoa(a);
	count += ft_printstr(tmp);
	return (count);
}
