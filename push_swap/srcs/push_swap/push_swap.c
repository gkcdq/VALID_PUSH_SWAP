#include "push_swap.h"

void free_av(char **av)
{
    int i;

    if (av == NULL)
        return;

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
    return;
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
		av = split(av[1]);
		init_stack_a_for_split(&a, av);
	}
	else
		init_stack_a(&a, av + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	if (ac == 2)
		free_av(av);
	free_stack(&a);
	return (0);
}
