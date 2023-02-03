/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:29:26 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 02:00:24 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	in_b_sort_three(t_stack *s, int c)
{
	if (SORT_132 == c || SORT_312 == c || SORT_123 == c)
	{
		if (SORT_123 == c)
		{
			rb(s, 1);
			sb(s, 1);
			rrb(s, 1);
			sb(s, 1);
		}
		if (SORT_132 == c)
			sb(s, 1);
		rb(s, 1);
		sb(s, 1);
		rrb(s, 1);
	}
	else if (SORT_231 == c || SORT_213 == c)
	{
		if (SORT_213 == c)
		{
			rb(s, 1);
			sb(s, 1);
			rrb(s, 1);
		}
		sb(s, 1);
	}
}

static void	in_a_sort_three(t_stack *s, int c)
{
	if (SORT_132 == c || SORT_312 == c)
	{
		if (SORT_312 == c)
			sa(s, 1);
		ra(s, 1);
		sa(s, 1);
		rra(s, 1);
	}
	else if (SORT_231 == c || SORT_213 == c || SORT_321 == c)
	{
		if (SORT_321 == c)
		{
			sa(s, 1);
			ra(s, 1);
			sa(s, 1);
			rra(s, 1);
		}
		if (SORT_231 == c)
		{
			ra(s, 1);
			sa(s, 1);
			rra(s, 1);
		}
		sa(s, 1);
	}
}

static void	sort_b(t_stack *s, int c)
{
	if (SORT_123 == c)
	{
		sb(s, 1);
		rrb(s, 1);
	}
	else if (SORT_132 == c)
		rb(s, 1);
	else if (SORT_213 == c)
		rrb(s, 1);
	else if (SORT_231 == c)
		sb(s, 1);
	else if (SORT_312 == c)
	{
		sb(s, 1);
		rb(s, 1);
	}
}

static void	sort_a(t_stack *s, int c)
{
	if (SORT_132 == c)
	{
		rra(s, 1);
		sa(s, 1);
	}
	else if (SORT_213 == c)
		sa(s, 1);
	else if (SORT_231 == c)
		rra(s, 1);
	else if (SORT_312 == c)
		ra(s, 1);
	else if (SORT_321 == c)
	{
		ra(s, 1);
		sa(s, 1);
	}
}

void	sort_three(t_stack *s, char ch)
{
	t_compare	compare;
	int			c;

	c = compare_init(s, &compare);
	if (s->size <= 3)
	{
		if (ch == 'a')
			sort_a(s, c);
		else if (ch == 'b')
			sort_b(s, c);
	}
	else
	{
		if (ch == 'a')
			in_a_sort_three(s, c);
		else if (ch == 'b')
			in_b_sort_three(s, c);
	}
}
