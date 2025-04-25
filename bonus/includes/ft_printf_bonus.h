/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:36:12 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/25 21:28:49 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_option
{
	bool	left_aligned;
	bool	zero_padding;
	bool	alternative_form;
	bool	show_plus;
	bool	is_space;
	int		width;
	int		precision;
	char	specifier;
}	t_option;

int		ft_printf(const char *format, ...);
int		ft_parse_format(const char *format, t_option *option, bool *flag);

/* print_functions */
int		ft_print_char_bonus(int a, t_option *option);
int		ft_print_str_bonus(char *str, t_option *option);
int		ft_print_percent_bonus(void);
int		ft_print_ptr_bonus(unsigned long long a, t_option *option);
int		ft_print_nbr_bonus(int a, t_option *option);
int		ft_print_hex_bonus(unsigned int num, char format, t_option *option);
int		ft_print_unsigned_bonus(unsigned int num, t_option *option);
int		ft_put_hex_bonus(unsigned long long num, bool is_lower);
int		ft_hex_len_bonus(unsigned long long num);

/* utils */
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_isdigit(int c);
int		ft_put_char(char c);
int		ft_put_zero(int len);
int		ft_put_space(int len);
int		ft_put_space_or_zero(int len, t_option *option);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
int		ft_print_number(int num, int num_len, int len_zero, t_option *option);
bool	ft_is_space(char c);
bool	ft_is_flag(char c);
#endif