/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmptmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:04:43 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/07 17:18:56 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ascending(t_stack *a, t_stack *b)
{
	if (sort_231)
		rra(a);
	else if (sort_213 || sort_312)
		sa(a);
	pb(a, b);
}

static void	descending(t_stack *a, t_stack *b)
{
	if (sort_132 || sort_231)
		sa(a);
	else if (sort_213)
		rra(a);
	pb(a, b);
}

int	ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_pow(nb, power - 1));
}

int	calc_direction(size_t p, size_t i)//i번째 삼각형의 방향
{
	if (p == 1)
		return (1);
	else if (i < p / 3)
		return (calc_direction(p / 3, i));
	else if (i < 2 * p / 3)
		return (calc_direction(p / 3, 2 * p / 3 - 1 - i));
	else
		return (calc_direction(p / 3, p - 1 - i));
}

size_t	calc_amount(size_t p, size_t i, size_t n)//i번째 삼각형의 크기(데이터의 개수)
{
	size_t	tmp;
	
	if (p == 1)
		return (n);
	else if (i < p / 3)
		return (calc_amount(p / 3, i, n) / 3);
	else if (i < 2 * p / 3)
	{
		tmp = calc_amount(p / 3, 2 * p / 3 - 1 - i, n);
		return (tmp / 3 + (tmp % 3 > 1));
	}
	else
	{
		tmp = calc_amount(p / 3, p - 1 - i , n);
		return (tmp / 3 + (tmp % 3 > 0));
	}
}

//[0] [1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] [12]

//s_size = 10;

//depth = 1;

//arr_size = ft_pow(3, depth(1)) + 1;//== 3
//[10][3][4][3]

//map[arr_size] = [size, inc_or_dec, a_or_b] [] []

//map[0] = 10, inc, a;
//map[1] = 3, dec, a;
//map[2] = 4, dec, b;
//map[3] = 3, inc, b;

void	a_to_b(t_stack *a, t_stack *b, int size)
{
	int	i;
	int	j;
	int	pivot_min;
	int	pivot_max;

	pivot_min = size / 3;
	pivot_max = size / 3 * 2;
	if (size < 6)
	{
		if (is_sorted())
			hard_coding(a, b, 0);
		return ;
	}
	i = -1;
	while (++i < size)
		if (arr[i] < pivot_max)
			pb(a, b);
	i = -1;
	while (++i < pivot_max)
		if (arr[i] < pivot_min)
			rb(b);
	a_to_b(a, b, arr, pivot_min);
	b_to_a(a, b, arr, pivot_min);
	b_to_a(a, b, arr, pivot_min);
}

int merge_sort(t_stack *a, t_stack *b, int depth, int size)
{
	int	i;
	int	pivot_min;
	int	pivot_max;

	i = 0;
	pivot_min = size / 3;
	pivot_max = size / 3 * 2;
	if (depth % 2 == 1)
	{
		while (++i < size)
			pb(a, b);
		if (size < 6)
		{
			if (!is_sorted(b))
				hard_coding(a, b)
		b_to_a(a, b, pivot_min);
	}
}

void	aamake_array(t_stack *a, t_stack *b)
{	
	int	s_size;
	int	arr_size;
	int depth;
	int i;

	depth = 0;
	s_size = a->size;
	while (s_size > 6)
		s_size /= 3; depth++;
	arr_size = ft_pow(3, depth);
	t_tri	map[arr_size];
	i = -1;
	while (++i < s_size)
	{
		map[i].size = calc_amount(a->size, i, depth);
		map[i].inc_or_dec = calc_direction(a->size, i);
		map[i].a_or_b = IN_A;
	}
	merge_sort();
}
