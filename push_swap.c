/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:25:00 by alecoutr          #+#    #+#             */
/*   Updated: 2023/03/18 11:00:22 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    exit_error(t_stack **stack_a, t_stack **stack_b)
{
    write(2, "Error\n", 6);
}

int fill_stack(t_stack **stack, int ac, char **av)
{
    int         i;
    long int    number;
    
    stack = NULL;
	i = 1;
	while (av[i])
	{
		number = ft_atoi(av[i]);
		if (number < INT_MIN || number > INT_MAX)
			return (0);
		if (i == 1)
			stack = new_stack(number);
		else
			add_bottom_stack(&stack, new_stack((int) number));
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
    t_stack     *stack_b;
	int			i;
	long int	number;

    if (!fill_stack(&stack_a, ac, av))
        exit_error(&stack_a, &stack_b);
    printf("rempli");
    system("leaks push_swap");
}