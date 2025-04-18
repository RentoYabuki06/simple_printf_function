# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 14:59:44 by yabukirento       #+#    #+#              #
#    Updated: 2025/04/18 15:17:51 by yabukirento      ###   ########.fr        #
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

# テストターゲットの修正・追加

# 通常版テスト（既存）
test: $(NAME)
	$(CC) $(INCLUDES) -o test_printf main.c -L. -lftprintf
	./test_printf
	$(RM) test_printf
	@echo "Standard version test completed."

# ボーナス版テスト（新規追加）
test_bonus: bonus
	$(CC) $(INCLUDES_BONUS) -o test_bonus main.c -L. -lftprintf
	./test_bonus
	$(RM) test_bonus
	@echo "Bonus version test completed."

# 全テスト（新規追加）
test_all: clean all test fclean bonus test_bonus
	@echo "All tests completed."

# ヘルプメッセージの更新
help:
	@echo "Available targets:"
	@echo "  all       : Build standard library"
	@echo "  bonus     : Build bonus library"
	@echo "  clean     : Remove object files"
	@echo "  fclean    : Remove object files and libraries"
	@echo "  re        : Rebuild everything"
	@echo "  test      : Run tests on standard version"
	@echo "  test_bonus: Run tests on bonus version"
	@echo "  test_all  : Test both standard and bonus versions"
	@echo "  help      : Display this help message"

.PHONY: all bonus clean fclean re test test_bonus test_all help