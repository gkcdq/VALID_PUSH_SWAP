/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:21:40 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/30 16:21:41 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(char *str, t_stack_node **stack)
{
	int		i;
	int		sign;
	long	number;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i + 1] >= 'a' && str[i + 1] <= 'z')
		|| (str[i + 1] >= 'A' && str[i + 1] <= 'Z'))
		free_errors(stack);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	check_atol(number, sign, stack);
	return (sign * number);
}

void	check_atol(long number, int sign, t_stack_node **stack)
{
	if (number * sign > INT_MAX || number * sign < INT_MIN)
		free_errors(stack);
}

int	ft_atol_for_split(char *str, t_stack_node **stack, char **av)
{
	int		i;
	int		sign;
	long	number;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i + 1] >= 'a' && str[i + 1] <= 'z')
		|| (str[i + 1] >= 'A' && str[i + 1] <= 'Z'))
		free_errors_for_split(stack, av);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	check_atol_split(number, sign, stack, av);
	return (sign * number);
}
