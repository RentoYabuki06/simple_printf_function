# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 14:59:44 by yabukirento       #+#    #+#              #
#    Updated: 2025/04/18 15:07:17 by yabukirento      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes
INCLUDES_BONUS = -I./bonus/includes

SRCS =	srcs/ft_printf.c \
		srcs/print_functions/ft_print_hex.c \
		srcs/print_functions/ft_print_percent.c \
		srcs/print_functions/ft_print_unsigned.c \
		srcs/print_functions/ft_print_char.c \
		srcs/print_functions/ft_print_nbr.c \
		srcs/print_functions/ft_print_ptr.c \
		srcs/print_functions/ft_print_str.c

SRCS_BONUS =	bonus/srcs/ft_printf_bonus.c \
				bonus/srcs/print_functions/ft_print_hex_bonus.c \
				bonus/srcs/print_functions/ft_print_percent_bonus.c \
				bonus/srcs/print_functions/ft_print_unsigned_bonus.c \
				bonus/srcs/print_functions/ft_print_char_bonus.c \
				bonus/srcs/print_functions/ft_print_nbr_bonus.c \
				bonus/srcs/print_functions/ft_print_ptr_bonus.c \
				bonus/srcs/print_functions/ft_print_str_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = libftprintf.a
BONS_NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

srcs/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS_BONUS)
	ranlib $(NAME)

bonus/%.o: bonus/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

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