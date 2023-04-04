# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 10:17:25 by alecoutr          #+#    #+#              #
#    Updated: 2023/03/28 11:31:18 by alecoutr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	= push_swap.c \
			stack.c \
			utils.c \
			swap.c \
			push.c \
			check_input.c \
			rotate.c \
			reverse_rotate.c

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