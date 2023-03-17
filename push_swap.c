/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:25:00 by alecoutr          #+#    #+#             */
/*   Updated: 2023/03/17 02:56:55 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	int			i;
	long int	number;

	stack_a = malloc((ac - 1) * sizeof(t_stack));
	if (!stack_a)
		return (printf("Failed allocation"));
	i = 1;
	while (av[i])
	{
		number = atoi(av[i]);
		if (number < INT_MIN || number > INT_MAX)
			return (0);
		if (i == 1)
			stack_a = new_stack(number);
		else
			add_bottom_stack(&stack_a, new_stack((int) number));
		i++;
	}
	
	while (stack_a)
	{
		printf("%d ", stack_a->value);
		stack_a = stack_a->next;	
	}
}