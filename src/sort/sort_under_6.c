/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Marai <MasaDevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:01:46 by marai             #+#    #+#             */
/*   Updated: 2023/03/26 19:16:11 by Marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>

void	sort_node_under3(t_node *stack, ssize_t activelen, ssize_t stacknum);
void	sort_node_under6(t_node *stack1, t_node *stack2, ssize_t activelen,
			ssize_t stacknum);
t_node	*sort_node_2(t_node *stack, ssize_t stacknum);
t_node	*sort_node_3(t_node *stack, ssize_t stacknum);
ssize_t	is_nodes_sorted(t_node *stack);

void	sort_node_under3(t_node *stack, ssize_t activelen, ssize_t stacknum)
{
	if (activelen < 2)
		return ;
	else if (activelen == 2)
		sort_node_2(stack, stacknum);
	else if (activelen == 3)
		sort_node_3(stack, stacknum);
	return ;
}

void	sort_node_under6(t_node *stack1, t_node *stack2, ssize_t activelen,
		ssize_t stacknum)
{
	ssize_t	movednum;

	if (activelen < 2)
		return ;
	else if (activelen == 2)
		sort_node_2(stack1, stacknum);
	else if (activelen == 3)
		sort_node_3(stack1, stacknum);
	else if (activelen < 7 && !is_nodes_sorted(stack1))
	{
		movednum = 0;
		while (3 < get_node_len(stack1))
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
		sort_node_under3(stack1, get_node_len(stack1), stacknum);
		while (movednum--)
			push_headnode(stack1, stack2, stacknum);
	}
	return ;
}

t_node	*sort_node_2(t_node *stack, ssize_t stacknum)
{
	t_node	*nownode;

	nownode = stack->next;
	if (nownode->compressed_num < nownode->next->compressed_num)
		return (stack);
	swap_headnode(stack, stacknum);
	return (stack);
}

t_node	*sort_node_3(t_node *stack, ssize_t stacknum)
{
	t_node	*nownode;

	nownode = stack->next;
	if (nownode->compressed_num < nownode->next->next->compressed_num
		&& nownode->next->next->compressed_num < nownode->next->compressed_num)
	{
		swap_headnode(stack, stacknum);
		rotate_stack(stack, stacknum);
	}
	else if (nownode->next->compressed_num < nownode->compressed_num
		&& nownode->compressed_num < nownode->next->next->compressed_num)
		swap_headnode(stack, stacknum);
	else if (nownode->next->compressed_num < nownode->next->next->compressed_num
		&& nownode->next->next->compressed_num < nownode->compressed_num)
		rotate_stack(stack, stacknum);
	else if (nownode->next->next->compressed_num < nownode->compressed_num
		&& nownode->compressed_num < nownode->next->compressed_num)
		reverse_rotate_stack(stack, stacknum);
	else if (nownode->next->next->compressed_num < nownode->next->compressed_num
		&& nownode->next->compressed_num < nownode->compressed_num)
	{
		rotate_stack(stack, stacknum);
		swap_headnode(stack, stacknum);
	}
	return (stack);
}

ssize_t	is_nodes_sorted(t_node *stack)
{
	t_node	*nownode;
	int		previous;

	nownode = stack->next;
	previous = 0;
	while (nownode != stack)
	{
		if (nownode->compressed_num < previous)
			return (0);
		previous = nownode->compressed_num;
		nownode = nownode->next;
	}
	return (1);
}
