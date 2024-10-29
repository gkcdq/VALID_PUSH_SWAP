#include "push_swap.h"

void	init_node_value(t_stack_node *node, int n)
{
	node->next = NULL;
	node->nbr = n;
	node->index = 0;
	node->push_cost = 0;
	node->above_median = 0;
	node->cheapest = 0; 
	node->target_node = NULL;
}

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	init_node_value(node, n);
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		n = ft_atol(av[i], a);
		if (error_duplicate(*a, (int)n))
			free_errors(a); 
		append_node(a, (int)n);
		i++;
	}
}

void	init_stack_a_for_split(t_stack_node **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (!ft_atol_for_split(av[i], a, av))
			free_errors_for_split(a, av);
		n = ft_atol_for_split(av[i], a, av);
		if (error_duplicate(*a, (int)n))
			free_errors_for_split(a, av); 
		append_node(a, (int)n);
		i++;
	}
}




t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name) 
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}