/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:43:59 by alecoutr          #+#    #+#             */
/*   Updated: 2023/03/22 16:18:04 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:49:33 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/06 20:30:16 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long ft_atoi(char *s)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*s == ' ' || *s == '\r' || *s == '\t')
		|| (*s == '\n' || *s == '\v' || *s == '\f'))
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}