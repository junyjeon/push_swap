/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:59 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/05 22:26:08 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*make_arr(t_stack *a, char **split_str)
{
	int *arr;
	int i;
	
	arr = (int *)malloc(sizeof(arr) * a->size);
	i = -1;
	while (split_str[++i])
	{
		arr[i] = ft_atoi_ll(split_str[i]);
		if (!arr[i])
			return (0);
	}
	return (arr);
}

int	stack_init(t_stack *a, t_stack *b)
{
	a->bottom = malloc(sizeof(a->bottom));
	a->top = malloc(sizeof(a->top));
	a->size = 0;
	b->bottom = malloc(sizeof(b->bottom));
	b->top = malloc(sizeof(b->top));
	b->size = 0;
	if (!a->bottom || !a->top || !b->bottom || !b->top)
		return (0);
	return (1);
}

int	*parsing(t_stack *a, t_stack *b, char **ar, int ac)
{
	char		*str;
	char		**split_str;
	long long	res;
	int			*arr;
	int			i;

	str = NULL;
	i = 0;
	while (++i < ac)
	{
		str = ft_strjoin(str, ar[i], i);
		if (!str)
			print_error("Memory allocation fail.\n");
	}
	split_str = ft_split(str, ' ');
	if (!split_str)
		print_error("Memory allocation fail.\n");
	i = -1;
	while (split_str[++i])
	{
		res = ft_atoi(split_str[i]);
		if (res < -2147483648 || 2147483647 < res)
			print_error("Int range Error\n");
		if (!push_back(a, res))
			print_error("Memory allocation fail.\n");
	}
	make_arr(a, split_str);
	error_check(arr, a->size);
	sorted(a, arr);
	return (0);
}
