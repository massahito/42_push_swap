/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Marai <MasaDevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:19:11 by Marai             #+#    #+#             */
/*   Updated: 2023/01/15 17:55:01 by Marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

void		*error_exit(void);

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

int	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == ' ');
}

//Check the args is composed in the right way.
int	arg_check(int argc, char *argv[])
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			while (ft_isspace(argv[i][j]))
				j++;
			while (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if ((argv[i][j] != '\0') && !ft_isdigit(argv[i][j]))
				error_exit();
			while (ft_isdigit(argv[i][j]))
				j++;
		}
		i++;
	}
	return (1);
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
		if ((long)INT_MAX < ans || ans < (long)INT_MIN)
			return (LONG_MAX);
		ans = 10 * ans + (str[i] - '0');
		i++;
	}
	return (ans * sign);
}

void	*error_exit(void)
{
	ft_printf("Error\n");
	exit(-1);
}
size_t	calc_num(int argc, char *argv[])
{
	size_t	i;
	size_t	count;
	size_t	flag;

	count = 0;
	if (argc == 2)
	{
		i = 0;
		flag = 0;
		while (argv[1][i] != '\0')
		{
			if (ft_isspace(argv[1][i]) || argv[1][i] == '+'
				|| argv[1][i] == '-')
				flag = 0;
			else if (ft_isdigit(argv[1][i]) && flag == 0)
			{
				flag = 1;
				count++;
			}
			i++;
		}
	}
	else
		count = (size_t)(argc - 1);
	printf("%ld\n", count);
	return (count);
}

static long	*make_nums_2(long *nums, char *argv[], size_t size)
{
	long	num;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
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

static long	*make_nums_more_than_3(long *nums, char *argv[], size_t size)
{
	int		i;
	long	num;

	i = 1;
	while (i <= size)
	{
		num = ft_atol(argv[i]);
		if ((long)INT_MAX < num)
		{
			free(nums);
			error_exit();
		}
		nums[i - 1] = num;
		i++;
	}
	return (nums);
}


long	*make_nums_array(int argc, char *argv[], size_t size)
{
	long	*nums;

	nums = malloc(sizeof(long) * size);
	if (!nums)
		error_exit();
	if (argc == 2)
		nums = make_nums_2(nums, argv, size);
	else
		nums = make_nums_more_than_3(nums, argv, size);
	//check duplicate and overflow
	return (nums);
}

ps_list	*make_list_node(ps_list *lsthead, long *nums, size_t numssize)
{
	ps_list	*lst;
	size_t	i;

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
	long	*nums;
	size_t	numssize;

	arg_check(argc, argv);
	numssize = calc_num(argc, argv);
	if (nums == NULL)
		error_exit();
	nums = make_nums_array(argc, argv, numssize);
	for (int i = 0; i < numssize; i++)
		printf("nums %d: %ld\n", i, nums[i]);
	lsthead = malloc(sizeof(ps_list));
	if (!lsthead)
	{
		free(nums);
		error_exit();
	}
	lsthead = make_list_node(lsthead, nums, numssize);
	return (lsthead);
}
int	main(int argc, char *argv[])
{
	ps_list *lsthead;
	ps_list *lst;
	lsthead = make_list(argc, argv);
	lst = lsthead->next;
	while (lst != NULL)
	{
		printf("%d\n", lst->num);
		lst = lst->next;
	}
}