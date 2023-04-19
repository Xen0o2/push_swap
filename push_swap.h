/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:24:34 by alecoutr          #+#    #+#             */
/*   Updated: 2023/04/17 18:34:55 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
    int             value;
    struct s_stack  *next;
}	t_stack;

t_stack			*new_stack(int value);
t_stack			*get_bottom_stack(t_stack *stack);
t_stack			*get_pre_bottom_stack(t_stack *stack);
void			add_bottom_stack(t_stack **stack, t_stack *new);
int	get_stack_size(t_stack *stack);

void			select_algo(t_stack **stack_a, t_stack **stack_b);
void			two_sort(t_stack **stack_a);
void			tree_sort(t_stack **stack_a);
void			little_sort(t_stack **stack_a, t_stack **stack_b);

long long int	ft_atoi(char *s);
int				ft_strcmp(char *s1, char *s2);
char			*remove_zero(char *s1);
int				is_number(char *str);
int				is_double(char **av, int i);
int				check_input(char **av);
void			ft_putstr(char *str);

void			ss(t_stack **stack_a, t_stack **stack_b);
void		    sa(t_stack **stack_a);
void		    sb(t_stack **stack_b);

void		    pa(t_stack **stack_a, t_stack **stack_b);
void    		pb(t_stack **stack_a, t_stack **stack_b);

void		    rr(t_stack **stack_a, t_stack **stack_b);
void		    ra(t_stack **stack_a);
void		    rb(t_stack **stack_b);

void			rrr(t_stack **stack_a, t_stack **stack_b);
void    		rra(t_stack **stack_a);
void    		rrb(t_stack **stack_b);

#endif