/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Marai <MasaDevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:05:37 by Marai             #+#    #+#             */
/*   Updated: 2023/01/15 12:46:46 by Marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

//void	quick_sort_a(ps_list **lstheada, ps_list **lstheadb, ps_list *baselst)
//{
//	ps_list	*lst;
//	ps_list	*prelst;

//	prelst = *lstheada;
//	if (!prelst)
//		return ;
//	lst = prelst->next;
//	while (lst != NULL)
//	{
//		if (lst->num < baselst->num)
//		{
//			sort_b(lst);
//			prelst->next = lst->next;
//		}
//		else if (lst->num > baselst->num)
//		{
//			prelst->next = lst->next;
//			addback(lstheada, lst);
//		}
//	}
//}

void			*error_exit(void);
ps_list			*make_list_node(int *nums, size_t numssize);
ps_list			*make_list(int argc, char *argv[]);
static int		*make_nums_2(char *argv[], size_t size);
static size_t	calc_nums(char *str);
static int		*make_nums_more_than_3(int argc, char *argv[]);
static long		ft_atol(const char *str);
int				ft_isspace(char c);

void	lstclear(ps_list *lst)
{
	ps_list	*next;

	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}

ps_list	*make_list_node(int *nums, size_t numssize)
{
	ps_list	*lsthead;
	ps_list	*lst;
	size_t	i;

	lsthead = malloc(sizeof(ps_list));
	if (!lsthead)
	{
		free(nums);
		error_exit();
	}
	i = 0;
	lst = lsthead;
	while (i < numssize)
	{
		lst->next = malloc(sizeof(ps_list));
		if (!lst->next)
		{
			free(nums);
			lstclear(lsthead);
			error_exit();
		}
		lst->next->num = nums[i];
		lst = lst->next;
		i++;
	}
	lst->next = NULL;
	return (lsthead);
}

ps_list	*make_list(int argc, char *argv[])
{
	ps_list	*lsthead;
	int		*nums;
	size_t	numssize;

	if (argc < 2)
		exit(-1);
	else if (argc == 2)
	{
		numssize = calc_nums(argv[1]);
		nums = make_nums_2(argv, numssize);
	}
	else
	{
		numssize = argc - 1;
		nums = make_nums_more_than_3(argc, argv);
	}
	if (nums == NULL)
		error_exit();
	lsthead = make_list_node(nums, numssize);
	return (lsthead);
}

static int	*make_nums_2(char *argv[], size_t size)
{
	int		*nums;
	long	num;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	nums = malloc(sizeof(int) * size);
	if (nums == NULL)
		error_exit();
	while (argv[1][i] != '\0')
	{
		num = ft_atol(&argv[1][i]);
		if (num < (long)INT_MIN || (long)INT_MAX < num)
		{
			free(nums);
			error_exit();
		}
		nums[j] = (int)num;
		while ((9 <= argv[1][i] && argv[1][i] <= 13) || argv[1][i] == ' ')
			i++;
		while (ft_isdigit(argv[1][i]))
			i++;
		j++;
	}
	return (nums);
}

static size_t	calc_nums(char *str)
{
	size_t	i;
	size_t	count;
	size_t	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]) || str[i] == '+' || str[i] == '-')
			flag = 0;
		else if (ft_isdigit(str[i]) && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (!ft_isdigit(str[i]))
			error_exit();
		i++;
	}
	return (count);
}

static int	*make_nums_more_than_3(int argc, char *argv[])
{
	int		i;
	int		*nums;
	long	num;

	nums = malloc(sizeof(int) * (argc - 1));
	if (nums == NULL)
		exit(-1);
	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if ((long)INT_MAX < num)
		{
			free(nums);
			error_exit();
		}
		nums[i - 1] = (int)num;
		i++;
	}
	return (nums);
}
static long	ft_atol(const char *str)
{
	long	ans;
	int		sign;
	size_t	i;

	ans = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (INT_MAX < ans || ans < INT_MIN)
			return (LONG_MAX);
		ans = 10 * ans + (str[i] - '0');
		i++;
	}
	return (ans * sign);
}

//void	*error_exit(void)
//{
//	ft_printf("Error\n");
//	exit(-1);
//}

int	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == ' ');
}
int	main(int argc, char *argv[])
{
	ps_list *lst;
	lst = make_list(argc, argv);
	while (lst)
	{
		printf("%d\n", lst->num);
		lst = lst->next;
	}
}