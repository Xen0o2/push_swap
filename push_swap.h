/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:24:34 by alecoutr          #+#    #+#             */
/*   Updated: 2023/03/22 16:18:17 by alecoutr         ###   ########.fr       */
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

long long int	ft_atoi(char *s);


#endif