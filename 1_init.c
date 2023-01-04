/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:59 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/04 13:13:16 by junyojeo         ###   ########.fr       */
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

static int	stack_init(t_stack *s)
{
	s->bottom = malloc(sizeof(s->bottom));
	if (!s->bottom)
		print_error("Malloc error\n");
	s->top = malloc(sizeof(s->top));
	if (!s->top)
		print_error("Malloc error\n");
	s->size = 0;
	return (1);
}

int	*init(t_stack *a, t_stack *b, char **ar, int ac)
{
	char		*str;
	char		**split_str;
	long long	res;
	int			i;

	if (ac < 2)
		print_error("Argment error\n");
	stack_init(a);
	stack_init(b);
	str = NULL;
	i = 0;
	while (++i < ac)
	{
		str = ft_strjoin(str, ar[i], i);
		if (!str)
			print_error("Malloc error\n");
	}
	split_str = ft_split(str, ' ');
	if (!split_str)
		print_error("Malloc error\n");
	i = -1;
	while (split_str[++i])
	{
		res = ft_atoi_ll(split_str[i]);
		if (res < -2147483648 || 2147483647 < res)
			print_error("Int range Error\n");
		if (!push_back(a, res))
			print_error("Malloc error\n");
	}
	//error_check(a);
	return (make_arr(a, split_str));
}
