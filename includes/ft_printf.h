/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:59:11 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 13:02:09 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>

int		ft_printf(const char *format, ...);

/* print_functions */
int		ft_print_char(int a);
int		ft_print_str(const char *str);
int		ft_print_percent(void);
int		ft_print_ptr(unsigned long long a);
int		ft_print_nbr(int a);
int		ft_print_hex(unsigned int nbr, char format);
int		ft_print_unsigned(unsigned int num);
int		ft_put_hex(unsigned long long num, bool is_lower);
int		ft_hex_len(unsigned long long num);

#endif