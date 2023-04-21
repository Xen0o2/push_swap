/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:36:13 by alecoutr          #+#    #+#             */
/*   Updated: 2023/04/21 18:04:16 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    swap_values(t_stack *a, t_stack *b)
{
    int tmp;

    tmp = a->value;
    a->value = b->value;
    b->value = tmp;
}

void    bubble_sort(t_stack **stack)
{
    int swapped;
    t_stack *tmp_stack;

    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        tmp_stack = *stack;
        while (tmp_stack->next) {
            if (tmp_stack->value > tmp_stack->next->value) {
                swap_values(tmp_stack, tmp_stack->next);
                swapped = 1;
            }
            tmp_stack = tmp_stack->next;
        }
    }

}

int duplicate(t_stack *stack, t_stack **duplicate)
{
    int i;
    
    *duplicate = NULL;
	i = 1;
	while (stack)
	{
		if (i == 1)
			*duplicate = new_stack(stack->value);
		else
			add_bottom_stack(duplicate, new_stack(stack->value));
		i++;
        stack = stack->next;
	}
    bubble_sort(duplicate);
    return (i);
}

int get_middle(t_stack *stack)
{
    t_stack *duplicate_stack;
    t_stack *address;
    int size;
    int value;

    size = duplicate(stack, &duplicate_stack) / 2;
    while (--size)
    {
        address = duplicate_stack->next;
        free(duplicate_stack);
        duplicate_stack = address;
    }
    value = duplicate_stack->value;
    while (duplicate_stack)
    {
        address = duplicate_stack->next;
        free(duplicate_stack);
        duplicate_stack = address;
    }
    return (value);
}

void    push_b(t_stack **stack_a, t_stack **stack_b)
{
    int middle;
    int size;
    int i;
    t_stack *tmp_stack;

    tmp_stack = *stack_a;
    i = -1;
    size = get_stack_size(*stack_a) + 1;
    middle = get_middle(*stack_a);
    while (++i < size)
    {
        if (tmp_stack->value <= middle)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
        tmp_stack = *stack_a;
    }
    while (get_stack_size(*stack_a) > 3)
        pb(stack_a, stack_b);
    tree_sort(stack_a);
}

void    get_b_costs(t_stack *stack_b)
{
    int size;
    int i;

    size = get_stack_size(stack_b);
    i = 0;
    while (stack_b)
    {
        if (i > size / 2)
            stack_b->b_cost = i - size;
        else
            stack_b->b_cost = i;
        i++;
        stack_b = stack_b->next;
    }
}

void    get_a_costs(t_stack *stack_a, t_stack *stack_b)
{
    int i;
    int gap;
    int moves;
    int size;
    t_stack *tmp_stack;

    i = 0;
    moves = 0;
    tmp_stack = stack_a;
    size = get_stack_size(stack_a);
    while (stack_b)
    {
        gap = INT_MAX;
        printf("pour %d\n", tmp_stack->value);
        while (tmp_stack)
        {
            if (tmp_stack->value - stack_b->value < gap && tmp_stack->value > stack_b->value)
            {
                gap = tmp_stack->value - stack_b->value;
                if (i > size / 2)
                    moves = i - size;
                else
                    moves = i;
            }
            i++;
            printf("celui du dessus : %d\n", stack_b->value);
            tmp_stack = tmp_stack->next;
        }
        tmp_stack = stack_a;
        stack_b->a_cost = moves;
        stack_b->cost = ABS(stack_b->a_cost) + ABS(stack_b->b_cost);
        stack_b = stack_b->next;
    }
}

int get_best_position(t_stack *stack_b)
{
    int i;
    int min;
    int position;

    i = 0;
    min = stack_b->cost;
    position = 0;
    while (stack_b)
    {
        if (stack_b->cost < min)
        {
            min = stack_b->cost;
            position = i;  
        }
        i++;
        stack_b = stack_b->next;
    }
    return (position);
}

void    get_moves(t_stack *stack_b, int *nb_ra, int *nb_rb, int best_position)
{
    int i;

    i = -1;
    while (++i < best_position)
        stack_b = stack_b->next;
    *nb_ra = stack_b->a_cost;
    *nb_rb = stack_b->b_cost;
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
    int i;
    int best_position;
    int nb_ra;
    int nb_rb;

    push_b(stack_a, stack_b);

    int x = 0;

    while (get_stack_size(*stack_b))
    {
        get_b_costs(*stack_b);
        get_a_costs(*stack_a, *stack_b);
        i = -1;
        best_position = get_best_position(*stack_b);
        get_moves(*stack_b, &nb_ra, &nb_rb, best_position);

        while (nb_ra){
            if (nb_ra > 0)
            {
                ra(stack_a);
                nb_ra--;
            }
            else
            {
                rra(stack_a);
                nb_ra++;
            }
        }
        while (nb_rb){
            if (nb_rb > 0)
            {
                rb(stack_b);
                nb_rb--;
            }
            else
            {
                rrb(stack_a);
                nb_rb++;
            }
        }
        pa(stack_a, stack_b);
        x++;
    }
}