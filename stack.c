/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:31:40 by alecoutr          #+#    #+#             */
/*   Updated: 2023/03/17 02:46:26 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		printf("Erreur d'allocation");
		return (new);
	}
	new->value = value;
	new->next = NULL;
	return (new);
}

t_stack	*get_bottom_stack(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return(stack);
	
}

void	add_bottom_stack(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = get_bottom_stack(*stack);
	last->next = new;
}