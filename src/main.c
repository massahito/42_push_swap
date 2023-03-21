/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Marai <MasaDevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 04:42:06 by marai             #+#    #+#             */
/*   Updated: 2023/03/21 12:39:18 by Marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}
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
	if (6 < get_node_len(stack_a))
	{
		push_smaller_nodes(stack_a, stack_b, get_node_len(stack_a), 1);
		push_swap(stack_a, stack_b, get_node_len(stack_a),
			get_node_len(stack_b));
	}
	else
		sort_node_under6(stack_a, stack_b, get_node_len(stack_a), 1);
	delete_node(stack_a);
	delete_node(stack_b);
}
