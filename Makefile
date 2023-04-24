# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 10:17:25 by alecoutr          #+#    #+#              #
#    Updated: 2023/04/25 00:40:14 by alecoutr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
BONUS_NAME = checker

SRCS	=   push_swap.c \
			stack.c \
			utils.c \
			check_input.c \
			select_algo.c \
			moves/swap.c \
			moves/push.c \
			moves/reverse_rotate.c \
			moves/rotate.c \
			sorts/two_sort.c \
			sorts/tree_sort.c \
			sorts/little_sort.c \
			sorts/big_sort.c \
			sorts/big_sort2.c \
			sorts/big_sort3.c

BONUS_SRCS	= checker.c

OBJS	= $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

GCC		= gcc -Wall -Wextra -Werror

$(NAME)	: $(OBJS)
	$(GCC) $(OBJS) -o $(NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	$(GCC) $(BONUS_OBJS) -o $(BONUS_NAME)

all	: $(NAME)

bonus :	$(BONUS_NAME)

clean	:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean	: clean
	rm -rf $(NAME) $(BONUS_NAME)

re	: fclean all