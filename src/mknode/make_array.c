/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:47:08 by marai             #+#    #+#             */
/*   Updated: 2023/03/25 23:27:12 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

ssize_t	check_compose(int argc, char *argv[]);
int		*make_array_2(ssize_t numslen, char *argv[]);
int		*make_array_3(ssize_t numslen, char *argv[]);
void	check_duplicate(ssize_t numslen, int *nums);

ssize_t	check_compose(int argc, char *argv[])
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	numslen;

	i = 1;
	numslen = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (skip_num(&argv[i][j]) <= 0)
				error_exit();
			j += skip_num(&argv[i][j]);
			while (ft_isspace(argv[i][j]))
				j++;
			numslen++;
		}
		i++;
	}
	return (numslen);
}

int	*make_array_2(ssize_t numslen, char *argv[])
{
	ssize_t	i;
	ssize_t	j;
	long	num;
	int		*nums;

	i = 0;
	j = 0;
	nums = malloc(sizeof(int) * numslen);
	if (!nums)
		error_exit();
	while (argv[1][j] != '\0')
	{
		num = ft_atol(&argv[1][j]);
		if ((long)INT_MAX < num)
		{
			free(nums);
			error_exit();
		}
		nums[i] = (int)num;
		j += skip_num(&argv[1][j]);
		i++;
	}
	return (nums);
}

int	*make_array_3(ssize_t numslen, char *argv[])
{
	ssize_t	i;
	long	num;
	int		*nums;

	nums = malloc(sizeof(int) * numslen);
	if (!nums)
		error_exit();
	i = 0;
	while (i < numslen)
	{
		num = ft_atol(argv[i + 1]);
		if ((long)INT_MAX < num)
		{
			free(nums);
			error_exit();
		}
		nums[i] = (int)num;
		i++;
	}
	return (nums);
}

void	check_duplicate(ssize_t numslen, int *nums)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while (i < numslen)
	{
		j = i + 1;
		while (j < numslen)
		{
			if (nums[i] == nums[j])
			{
				free(nums);
				error_exit();
			}
			j++;
		}
		i++;
	}
}
