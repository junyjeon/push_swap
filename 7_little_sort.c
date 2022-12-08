/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_little_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:11:40 by junyojeo          #+#    #+#             */
/*   Updated: 2022/11/29 11:11:40 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_five(t_stack *a)
{
	if (sort_2134)
		sa(a);
	else if (sort_3124)
	{
		sa(a);
		ra(a);
		sa(a);
		rra(a);
	}
	else if (sort_41235)
	{
		rra(a);
		sa(a);
		ra(a);
		ra(a);
	}
	else if (last < first)
		ra(a);
}

static void sort_four(t_stack *a)
{
	if (sort_2134)
		sa(a);
	else if (sort_3124)
	{
		rra(a);
		sa(a);
		ra(a);
		ra(a);
	}
	else if (last < first)
		ra(a);
}

static void	sort_three(t_stack *a)
{
	if (sort_132)
	{
		sa(a);
		ra(a);
	}
	else if (sort_231)
		rra(a);
	else if (sort_213)
		sa(a);
	else if (sort_312)
		ra(a);
	else
	{
		sa(a);
		rra(a);
	}
}

void	little_sort(t_stack *a, t_stack *b)
{
	if (1 == a->size)
	{
		write(1, "Arguments vector is one\n", 24);
	}
	else if (2 == a->size)
	{
		if (first > second)
			sa(a);
	}
	else if (3 == a->size)
		sort_three(a);
	else if (4 == a->size)
	{
		pb(a, b);
		sort_three(a);
		pa(a, b);
		sort_four(a);
	}
	else if (5 == a->size)
	{
		pb(a, b);
		pb(a, b);
		sort_three(a);
		pa(a, b);
		sort_four(a);
		pa(a, b);
		sort_five(a);
	}
	exit(1);
}
