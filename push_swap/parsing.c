/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:00:17 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/30 15:00:19 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nb == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nb = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}

void	free_errors_for_split(t_stack_node **a, char **av)
{
	free_av(av);
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
