/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:36:13 by alecoutr          #+#    #+#             */
/*   Updated: 2023/04/19 17:34:34 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    swap_values(t_stack *a, t_stack*b)
{
    int tmp;

    tmp = a->value;
    a->value = b->value;
    b->value = tmp;
}

void    bubble_sort(t_stack **stack)
{
    int swapped;
    t_stack *ptr1;
    t_stack *lptr = NULL;

    if (stack == NULL)
        return;

    while (swapped)
    {
        swapped = 0;
        ptr1 = *stack;

        while (ptr1->next != lptr) {
            if (ptr1->value > ptr1->next->value) {
                swap_values(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }

}

void    duplicate(t_stack *stack, t_stack **duplicate)
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
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int size;
    t_stack *duplicate_stack;

    duplicate(*stack_a, &duplicate_stack);
    bubble_sort(&duplicate_stack);
    printf("t : ");
    while (duplicate_stack)
    {
        printf("%d ", duplicate_stack->value);
        duplicate_stack = duplicate_stack->next;
    }
    printf("\n");
}