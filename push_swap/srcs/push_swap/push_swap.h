#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

void			init_node_value(t_stack_node *node, int n);
void			free_errors_for_split(t_stack_node **a, char **av);
void			init_stack_a_for_split(t_stack_node **a, char **av);
void			free_av(char **av);
int				ft_atol(char *str, t_stack_node **stack);
void			check_atol(long number, int sign, t_stack_node **stack);
int				ft_atol_for_split(char *str, t_stack_node **stack, char **av);
void			check_atol_for_split(long number, int sign, t_stack_node **stack, char **av);
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);
void			init_stack_a(t_stack_node **a, char **argv); //Initiate stack `a` before processing
//char			**split(char *s, char c); //To handle input of numbers as a string argument, e.g. enclosed in " "
void			init_nodes_a(t_stack_node *a, t_stack_node *b); //To prep all nodes for pushing `a` to `b`
void			init_nodes_b(t_stack_node *a, t_stack_node *b); //To prep all nodes for pushing `b` back to `a`
void			current_index(t_stack_node *stack); //Set the node's current index
void			set_cheapest(t_stack_node *stack); //Set the stack's cheapest node
t_stack_node	*get_cheapest(t_stack_node *stack); //Get the cheapest node of a stack
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c); //Prep the required nodes on top for pushing
int				stack_len(t_stack_node *stack); //Calculate the length of a stack
t_stack_node	*find_last(t_stack_node *stack); //Find the last node of a stack
bool			stack_sorted(t_stack_node *stack); //To check whether a stack is sorted
t_stack_node	*find_min(t_stack_node *stack); //Find the smallest number
t_stack_node	*find_max(t_stack_node *stack); //Find the biggest number
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
char 			**split(char *str);

#endif