/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:59:11 by yabukirento       #+#    #+#             */
/*   Updated: 2024/05/03 15:15:38 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
int		ft_printchar(char a);
int		ft_printstr(const char *str);
int		ft_format(va_list args, const char format);
int		ft_printf(const char *format, ...);
int		ft_printpercent(void);
int		ft_printptr(unsigned long long a);
int		ft_printnbr(int a);
char	*ft_ulitoa(unsigned long long n);
int		ft_print_hex(unsigned int nbr, char format);

#endif