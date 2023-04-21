# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 10:17:25 by alecoutr          #+#    #+#              #
#    Updated: 2023/04/21 19:29:22 by alecoutr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	= push_swap.c \
			stack.c \
			utils.c \
			moves/swap.c \
			check_input.c \
			moves/push.c \
			moves/reverse_rotate.c \
			moves/rotate.c \
			sorts/two_sort.c \
			sorts/tree_sort.c \
			sorts/little_sort.c \
			sorts/big_sort.c \
			select_algo.c

OBJS	= $(SRCS:.c=.o)

GCC		= gcc -Wall -Wextra -Werror

$(NAME)	: $(OBJS)
	$(GCC) $(OBJS) -o $(NAME)

all	: $(NAME) clean

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf $(NAME)

re	: fclean all