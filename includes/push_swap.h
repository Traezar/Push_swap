/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:25:29 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/18 10:25:32 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_array
{
  int size;
  int largest_value;
  int smallest_value;
  struct s_node *stack;
} t_array;


typedef struct s_node
{
	int value;
	int distance_to_top;
	int distance_to_bottom;
	int rank;
	struct s_node *next;
} t_node;

typedef struct s_oplist
{
	char *op;
	struct s_oplist *next;
} t_oplist;


t_node *create_stack_array (char **ptr,int size);
int get_largest_value(t_array *array);
int get_smallest_value(t_array *array);
void sort_with_commands(t_array **array);
void assign_rank_to_stack_elements (t_node *ranker, t_array **array);
void sort_inplace(t_node **stack_a, t_node **stack_b, t_oplist **op);
void sort_insert(t_node **stack_a, t_node **stack_b, t_oplist **op);
void sort_big(t_node **head_of_a, t_node **head_of_b, t_oplist **op,int max);
void align_stacks(t_node **stack_a, t_node **stack_b, t_oplist **op, int mid);
void sort_with_commands(t_array **array);

void push_front_node(t_node **head_of_stack,t_node **ptr_to_node);
void push_back_node(t_node **head_of_stack,t_node **ptr_to_node);
t_node *extract_out_of_stack(t_node **head_of_stack,int node_with_this_value);
void initialise_stack_a(t_node **head_of_a,char **int_array);
void reverse_stack_order(t_node **head_of_stack);
void move_them_over_to_stack_b(t_node ** stack_a, t_node **stack_b, int middle, t_oplist **op);
int there_are_numbers_bigger_than_the_middle(t_node *stack_a, int middle);
void best_move (t_node **stack_a, t_node **stack_b, t_node *target, t_oplist **op);
int find_next_to_push (t_node **a,t_node **target,int middle);
void rotate(int rotate, t_node ** stack, t_oplist **op);
void sort_both_stacks(t_node **stack_a, t_node **stack_b, t_oplist **op);
t_array *get_params(char **int_array);
void execute_push_swap (char **int_array);
void rotate_stacka(int rotate, t_node ** stack, t_oplist **op);
void rotate_stackb(int rotate, t_node ** stack, t_oplist **op);
void rank(t_node **ranker);
void sort(t_node **ranker);

void sa(t_node **head_of_a, t_oplist **op);
void sb( t_node **head_of_b, t_oplist **op);
void ss(t_node **head_of_a, t_node **head_of_b, t_oplist **op_a , t_oplist **op_b);
void pa(t_node **head_of_a, t_node **head_of_b, t_oplist **op);
void pb(t_node **head_of_a, t_node **head_of_b, t_oplist **op);
void ra(t_node **head_of_a, t_oplist **op);
void rb(t_node **head_of_b, t_oplist **op);
void rr(t_node **head_of_a, t_node **head_of_b, t_oplist **op_a , t_oplist **op_b);
void rra(t_node **head_of_a, t_oplist **op);
void rrb(t_node **head_of_b, t_oplist **op);
void rrr(t_node **head_of_a, t_node **head_of_b, t_oplist **op_a , t_oplist **op_b);

int rotate_or_swap_ascending(int rank, int next_rank, int  size);
int rotate_or_swap_descending(int rank, int next_rank, int  size);
void print_to_oplist(char *str, t_oplist **head);
int not_sorted(t_node **stack_a, t_node **stack_b);
void sort_small(t_node **stack_a, int size, t_oplist **op);
int  rotations_to_a_swap_ascending(t_node *node,int count);
int  rotations_to_a_swap_descending(t_node *node,int count);
int get_direction(t_node **node);
int get_chain_size(t_node *a);




void debug_print_state(t_node **headlist, t_node **blist, t_oplist **oplist);
