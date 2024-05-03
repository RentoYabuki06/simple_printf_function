# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 14:59:44 by yabukirento       #+#    #+#              #
#    Updated: 2024/05/03 15:11:31 by yabukirento      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRCS =	ft_itoa.c \
		ft_uitoa.c \
		ft_printchar.c \
		ft_printstr.c \
		ft_format.c \
		ft_printf.c \
		ft_printpercent.c \
		ft_printptr.c \
		ft_printnbr.c \
		ft_uitoa.c \
		ft_print_hex.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all