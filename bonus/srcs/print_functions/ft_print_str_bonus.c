/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:13:08 by ryabuki           #+#    #+#             */
/*   Updated: 2025/04/25 20:13:10 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_helper(char *str, int len_str, int len_space)
{
	if (write(STDOUT_FILENO, str, len_str) < 0)
		return (EXIT_FAILURE);
	if (ft_put_space(len_space) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_print_str_bonus(char *str, t_option *option)
{
	int	len_str;
	int	len_space;

	if (!str)
		return (write(STDOUT_FILENO, "(null)", 6));
	len_str = ft_strlen(str);
	if ((*option).precision != -1 && (*option).precision < len_str)
		len_str = (*option).precision;
	len_space = (*option).width - len_str;
	if (len_space < 0)
		len_space = 0;
	if ((*option).left_aligned == true)
	{
		if (ft_helper(str, len_str, len_space) == EXIT_FAILURE)
			return (-1);
	}
	if ((*option).left_aligned == false)
	{
		if (ft_helper(str, len_str, len_space) == EXIT_FAILURE)
			return (-1);
	}
	return (len_str + len_space);
}
