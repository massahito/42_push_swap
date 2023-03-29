/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Marai <MasaDevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:42:06 by marai             #+#    #+#             */
/*   Updated: 2023/03/29 13:07:57 by Marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = make_list(argc, argv);
	stack_b = malloc(sizeof(t_node));
	if (!stack_b)
	{
		delete_node(stack_a);
		error_exit();
	}
	stack_b->next = stack_b;
	stack_b->back = stack_b;
	if (!is_nodes_ordered(stack_a) && 6 < get_node_len(stack_a))
	{
		while (get_node_len(stack_a))
		{	
			push_headnode(stack_b, stack_a, 0);
		}
		push_swap(stack_a, stack_b, get_node_len(stack_a),
			get_node_len(stack_b));
	}
	else
		sort_node_under6(stack_a, stack_b, get_node_len(stack_a), 1);
	delete_node(stack_a);
	delete_node(stack_b);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }
