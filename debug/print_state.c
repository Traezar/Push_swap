#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void debug_print_state(t_node **alist, t_node **blist, t_oplist **oplist)
{
  t_node *a;
  t_node *b;
  t_oplist *op;
  char *placeholder;
  int i;


  i = 0;
  a = *alist;
  b = *blist;
  op = *oplist;
  placeholder = ft_strnew(100);
  ft_printf("The current state is :\n");
  ft_printf("A | ");
  while (a != NULL)
  {

    ft_printf("%d ",a->value);
    a = a->next;
  }
  ft_printf("\n");
  ft_printf("B | ");
  while (b != NULL)
  {

    ft_printf("%d ",b->value);
    b = b->next;
  }
  ft_printf("\n");
  ft_printf("The commands that have been is are :");
  while (op != NULL)
  {
    ft_printf("%s ",op->op);
    op = op->next;
    i++;
  }
  ft_putchar('\n');
  get_next_line(1, &placeholder);
  if (ft_strcmp(placeholder, "q") == 0)
    exit(0);
  free(placeholder);
  ft_printf("The number of commands generated is : %i\n", i);
  return ;
}
