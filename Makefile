# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 14:59:44 by yabukirento       #+#    #+#              #
#    Updated: 2025/03/31 18:11:42 by yabukirento      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

SRC_DIR = src
PRINT_FUNC_DIR = $(SRC_DIR)/print_functions
UTILS_DIR = $(SRC_DIR)/utils

PRINT_SRCS = $(addprefix $(PRINT_FUNC_DIR)/, \
	ft_print_hex.c \
	ft_print_percent.c \
	ft_print_unsigned.c \
	ft_print_char.c \
	ft_print_nbr.c \
	ft_print_ptr.c \
	ft_print_str.c)

UTILS_SRCS = $(addprefix $(UTILS_DIR)/, \
	ft_itoa.c \
	ft_strdup.c)

MAIN_SRCS = $(addprefix $(SRC_DIR)/, \
	ft_printf.c)

SRCS = $(PRINT_SRCS) $(UTILS_SRCS) $(MAIN_SRCS)

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.aa

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re