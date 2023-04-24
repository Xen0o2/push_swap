/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 02:25:00 by alecoutr          #+#    #+#             */
/*   Updated: 2023/04/21 17:49:40 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	fill_stack(t_stack **stack, int ac, char **av)
{
	int				i;
	long long int	number;

	*stack = NULL;
	i = 1;
	while (av[i])
	{
		number = ft_atoi(av[i]);
		if (number < INT_MIN || number > INT_MAX)
			return (0);
		if (i == 1)
			*stack = new_stack(number);
		else
			add_bottom_stack(stack, new_stack((int) number));
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			i;
	long int	number;

	if (!check_input(av))
		exit_error(NULL, NULL);
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || ac == 2)
		exit(1);
	if (!fill_stack(&stack_a, ac, av))
		exit_error(&stack_a, NULL);
	if (!is_sorted(stack_a))
		select_algo(&stack_a, &stack_b);
}
