#include "push_swap.h"

void	sort_node_under12(t_node *stack1, t_node *stack2, ssize_t activelen,
		ssize_t stacknum)
{	
	ssize_t	movednum;

	if(6 < activelen)
	{
		movednum = 0;
		while (6 < get_node_len(stack1))
		{
			if(nth_smallest(stack1, activelen) <= (get_node_len(stack1) + 1) / 2)
				while (stack1->next->compressed_num != nth_small_num(stack1, 1,
					get_node_len(stack1)))
					rotate_stack(stack1, stacknum);
			else
				while (stack1->next->compressed_num != nth_small_num(stack1, 1, 
					get_node_len(stack1)))
					reverse_rotate_stack(stack1, stacknum);
			push_headnode(stack2, stack1, stacknum + 1);
			movednum++;
		}
		sort_node_under6(stack1, stack2, activelen - movednum, stacknum);
		activelen = movednum;
		while (movednum--)
			push_headnode(stack1, stack2, stacknum);
	}
	sort_node_under6(stack1, stack2, activelen, stacknum);
}