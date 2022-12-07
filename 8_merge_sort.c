/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_merge_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:04:43 by junyojeo          #+#    #+#             */
/*   Updated: 2022/12/07 21:58:15 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_max(t_stack *a, t_stack *b)
{
	if (sort_231)
		rra(a);
	else if (sort_213 || sort_312)
		sa(a);
	pb(a, b);
}

static void	_max(t_stack *a, t_stack *b)
{
	if (sort_132 || sort_231)
		sa(a);
	else if (sort_213)
		rra(a);
	pb(a, b);
}

int	_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * _pow(nb, power - 1));
}

int	calc_direction(size_t p, size_t i)
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

size_t	calc_amount(size_t p, size_t i, size_t n)
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
#include <stdio.h>
void	make_arr(t_stack *a, t_stack *b)
{	
	int	stack_size;
	int depth;
	int i;

	depth = 0;
	stack_size = a->size;
	while (stack_size > 6)
	{
		stack_size /= 3;
		depth++;
	}
	int arr_size = _pow(3, depth);
	t_tri	map[arr_size];
	t_val	val;

	val = malloc(sizeof(val) * depth);
	i = 0;
	while (i < depth)
	{
		val[i].depth = i;
		int j = 0;
		while (j < depth * 3 = 
		{
			
			j++;
		}
	}
	i = 0;
	while (i < arr_size)
	{
		map[i].size = calc_amount(a->size, i, depth);
		map[i].inc_or_dec = calc_direction(a->size, i);
		map[i].a_or_b = IN_A;
		i++;
	}
	i = pow(3, depth);
	int j = pow(3, depth + 1);
	while (i < j)
	{
		if (map[i].inc_or_dec == 1)
			max(a, b);
		else
			min(a, b);
		map[i].a_or_b = IN_B;
		i++;
	}
	i = 0;
	while (map[i])
	{
		printf ("%d, size: %d inc_or_dec: %d a_or_b: %d", i, map[i].size, map[i], map[i].inc_or_dec, map[i].a_or_b);
		i++;
	}
}
