# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 14:59:44 by yabukirento       #+#    #+#              #
#    Updated: 2025/04/18 13:19:13 by yabukirento      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

SRC_DIR = src
PRINT_FUNC_DIR = $(SRC_DIR)/print_functions

PRINT_SRCS = $(addprefix $(PRINT_FUNC_DIR)/, \
	ft_print_hex.c \
	ft_print_percent.c \
	ft_print_unsigned.c \
	ft_print_char.c \
	ft_print_nbr.c \
	ft_print_ptr.c \
	ft_print_str.c)

MAIN_SRCS = $(addprefix $(SRC_DIR)/, \
	ft_printf.c)

SRCS = $(PRINT_SRCS) $(MAIN_SRCS)

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

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

test: $(NAME)
	$(CC) $(INCLUDES) -o test_printf main.c -L. -lftprintf
	./test_printf
	$(RM) test_printf
	@echo "テストが完了しました。"

help:
	@echo "使用可能なターゲット:"
	@echo "  all     : ライブラリをビルド"
	@echo "  clean   : オブジェクトファイルを削除"
	@echo "  fclean  : オブジェクトファイルとライブラリを削除"
	@echo "  re      : 全てを再ビルド"
	@echo "  test    : テストを実行"
	@echo "  help    : このヘルプメッセージを表示"

.PHONY: all clean fclean re test help