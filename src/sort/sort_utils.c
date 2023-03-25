/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 03:19:33 by marai             #+#    #+#             */
/*   Updated: 2023/03/26 00:23:25 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

ssize_t	get_node_len(t_node *stack);
t_node	*get_lastnode(t_node *stack);
int		nth_small_num(t_node *stack, ssize_t nth, ssize_t activelen);
ssize_t	find_num_node(t_node *stack, int num);

ssize_t	get_node_len(t_node *stack)
{
	t_node	*nownode;
	ssize_t	len;

	len = 0;
	nownode = stack->next;
	while (stack != nownode)
	{
		len++;
		nownode = nownode->next;
	}
	return (len);
}

t_node	*get_lastnode(t_node *stack)
{
	t_node	*nownode;

	nownode = stack->next;
	while (nownode->next != stack)
		nownode = nownode->next;
	return (nownode);
}

int	nth_small_num(t_node *stack, ssize_t nth, ssize_t activelen)
{
	t_node	*nownode;
	int		ans;
	int		lower_limit;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	lower_limit = 0;
	while (i < nth)
	{
		nownode = stack->next;
		j = 0;
		ans = INT_MAX;
		while (j < activelen)
		{
			if (nownode->compressed_num < ans
				&& lower_limit < nownode->compressed_num)
				ans = nownode->compressed_num;
			nownode = nownode->next;
			j++;
		}
		lower_limit = ans;
		i++;
	}
	return (ans);
}

ssize_t	nth_smallest(t_node *stack, ssize_t activelen)
{
	t_node	*nownode;
	int		lowest;
	ssize_t	i;
	ssize_t	ans;

	i = 0;
	ans = 0;
	nownode = stack->next;
	lowest = nownode->compressed_num;
	while (i < activelen)
	{
		if (nownode->compressed_num < lowest)
		{
			lowest = nownode->compressed_num;
			ans = i;
		}
		nownode = nownode->next;
		i++;
	}
	return (ans + 1);
}

ssize_t	find_num_node(t_node *stack, int num)
{
	t_node	*nownode;
	ssize_t	nodenum;

	nodenum = 0;
	nownode = stack->next;
	while (nownode != stack)
	{
		nodenum++;
		if (nownode->compressed_num == num)
			return (nodenum);
		nownode = nownode->next;
	}
	return (0);
}
