/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:58:34 by yabukirento       #+#    #+#             */
/*   Updated: 2024/05/03 14:54:58 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_numlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ans;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numlen(n);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (NULL);
	ans[len] = '\0';
	if (n < 0)
	{
		ans[0] = '-';
		n *= -1;
	}
	while (len > 0)
	{
		len--;
		if (ans[len] == '-')
			break ;
		ans[len] = n % 10 + '0';
		n /= 10;
	}
	return (ans);
}

char	*ft_uitoa(unsigned int n)
{
	char	*ans;
	size_t	len;

	len = ft_numlen(n);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (NULL);
	ans[len] = '\0';
	while (len > 0)
	{
		len--;
		if (ans[len] == '-')
			break ;
		ans[len] = n % 10 + '0';
		n /= 10;
	}
	return (ans);
}

char	*ft_ulitoa(unsigned long long n)
{
	char	*ans;
	size_t	len;

	len = ft_numlen(n);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (NULL);
	ans[len] = '\0';
	while (len > 0)
	{
		len--;
		if (ans[len] == '-')
			break ;
		ans[len] = n % 10 + '0';
		n /= 10;
	}
	return (ans);
}
