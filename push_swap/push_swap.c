/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:00:25 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/30 15:00:26 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_av(char **av)
{
	int	i;

	if (av == NULL)
		return ;
	i = 0;
	while (av[i])
	{
		if (av[i] != NULL)
		{
			free(av[i]);
		}
		i++;
	}
	free(av);
	return ;
}

static void	clear_end_of_main(int ac, char **av, t_stack_node *a)
{
	if (ac == 2)
		free_av(av);
	free_stack(&a);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	else if (ac == 2)
	{
		av = split_for_push_swap(av[1]);
		init_stack_a_for_split(&a, av);
	}
	else
		init_stack_a(&a, av + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_3(&a);
		else
			sort_stacks(&a, &b);
	}
	clear_end_of_main(ac, av, a);
	return (0);
}
