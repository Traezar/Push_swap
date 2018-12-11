#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void debug_print_state(t_node **headlist, t_oplist **oplist)
{
  t_node *a;
  t_oplist *op;
  char *placeholder;
  int i;


  i = 0;
  a = *headlist;
  op = *oplist;
  placeholder = ft_strnew(100);
  ft_printf("The current state is :\n");
  while (a != NULL)
  {

    ft_printf("%20d\n",a->value);
    a = a->next;
  }
  ft_printf("The commands that have been is are :");
  while (op != NULL)
  {
    ft_printf("%s ",op->op);
    op = op->next;
    i++;
  }
  ft_putchar('\n');
  //get_next_line(1, &placeholder);
  if (ft_strcmp(placeholder, "q") == 0)
    exit(0);
  free(placeholder);
  ft_printf("The number of commands generated is : %i\n", i);
  return ;
}
