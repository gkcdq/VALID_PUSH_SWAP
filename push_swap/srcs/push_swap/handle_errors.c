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
	if ((str[i + 1] >= 'a' && str[i + 1] <= 'z') || (str[i + 1] >= 'A' && str[i + 1] <= 'Z'))
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
	if ((str[i + 1] >= 'a' && str[i + 1] <= 'z') || (str[i + 1] >= 'A' && str[i + 1] <= 'Z'))
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
	check_atol_for_split(number, sign, stack, av);
	return (sign * number);
}

void	check_atol_for_split(long number, int sign, t_stack_node **stack, char **av)
{
	if (number * sign > INT_MAX || number * sign < INT_MIN)
		free_errors_for_split(stack, av);
}

int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
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
		current->nbr = 0;
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
