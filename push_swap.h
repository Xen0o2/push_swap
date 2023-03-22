/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:24:34 by alecoutr          #+#    #+#             */
/*   Updated: 2023/03/18 10:58:13 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* BESOIN */
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/* PAS BESOIN */

typedef struct s_stack
{
    int             value;
    struct s_stack  *next;
}   t_stack;

t_stack	*new_stack(int value);
t_stack	*get_bottom_stack(t_stack *stack);
void    add_bottom_stack(t_stack **stack, t_stack *new);

int	ft_atoi(char *s);


#endif