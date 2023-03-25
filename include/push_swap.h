/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:21:59 by marai             #+#    #+#             */
/*   Updated: 2023/03/26 00:05:58 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				num;
	int				compressed_num;
	struct s_node	*back;
	struct s_node	*next;
}					t_node;

// make_array_utils.c
int					ft_isspace(char c);
void				error_exit(void);
long				ft_atol(char *str);
ssize_t				skip_num(char *str);

// make_array.c
t_node				*make_list(int argc, char *argv[]);
ssize_t				check_compose(int argc, char *argv[]);
void				check_duplicate(ssize_t numslen, int *nums);
int					*make_array_2(ssize_t numslen, char *argv[]);
int					*make_array_3(ssize_t numslen, char *argv[]);
void				check_duplicate(ssize_t numslen, int *nums);

// make_nodes.c
t_node				*make_nodes(ssize_t numslen, int *nums);
void				detele_everything(int *nums, t_node *stack);
void				delete_node(t_node *stack);
void				compress_nodes(t_node *stack, ssize_t numslen, int *nums);

//heap_sort.c
int					*heap_sort(int *nums, ssize_t numslen);
void				push_up(int *nums, ssize_t parent, ssize_t last);
int					*swap(int *nums, ssize_t first, ssize_t second);

// push_swap_utils
ssize_t				get_node_len(t_node *stack);
t_node				*get_lastnode(t_node *stack);
int					nth_small_num(t_node *stack, ssize_t nth,
						ssize_t activelen);
ssize_t				find_num_node(t_node *stack, int num);
ssize_t				nth_smallest(t_node *stack, ssize_t activelen);

//sort operation
void				rotate_stack(t_node *stack, ssize_t stacknum);
void				reverse_rotate_stack(t_node *stack, ssize_t stacknum);
void				push_headnode(t_node *stack1, t_node *stack2,
						ssize_t stacknum);
void				swap_headnode(t_node *stack, ssize_t stacknum);

//node_sort
void				sort_node_under6(t_node *stack1, t_node *stack2,
						ssize_t activelen, ssize_t stacknum);
ssize_t				push_bigger_nodes(t_node *stack1, t_node *stack2,
						ssize_t activelen, ssize_t stacknum);
ssize_t				push_smaller_nodes(t_node *stack1, t_node *stack2,
						ssize_t activelen, ssize_t stacknum);
t_node				*sort_node_2(t_node *stack, ssize_t stacknum);
t_node				*sort_node_3(t_node *stack, ssize_t stacknum);

//push_swap
void				print(t_node *stack_a, t_node *stack_b);
void				push_swap(t_node *stack_a, t_node *stack_b,
						ssize_t a_activelen, ssize_t b_activelen);
void				see_node(t_node *stack);
ssize_t				is_nodes_ordered(t_node *stack);
#endif
