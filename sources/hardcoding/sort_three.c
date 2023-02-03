/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:29:26 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 01:33:42 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	in_b_sort_three(t_stack *s, int c)
{
	if (SORT_132 == c || SORT_312 == c || SORT_123 == c)
	{
		if (SORT_123 == c)
		{
			rb(s);
			sb(s);
			rrb(s);
			sb(s);
		}
		if (SORT_132 == c)
			sb(s);
		rb(s);
		sb(s);
		rrb(s);
	}
	else if (SORT_231 == c || SORT_213 == c)
	{
		if (SORT_213 == c)
		{
			rb(s);
			sb(s);
			rrb(s);
		}
		sb(s);
	}
}

static void	in_a_sort_three(t_stack *s, int c)
{
	if (SORT_132 == c || SORT_312 == c)
	{
		if (SORT_312 == c)
			sa(s);
		ra(s);
		sa(s);
		rra(s);
	}
	else if (SORT_231 == c || SORT_213 == c || SORT_321 == c)
	{
		if (SORT_321 == c)
		{
			sa(s);
			ra(s);
			sa(s);
			rra(s);
		}
		if (SORT_231 == c)
		{
			ra(s);
			sa(s);
			rra(s);
		}
		sa(s);
	}
}

static void	sort_b(t_stack *s, int c)
{
	if (SORT_123 == c)
	{
		sb(s);
		rrb(s);
	}
	else if (SORT_132 == c)
		rb(s);
	else if (SORT_213 == c)
	{
		rrb(s);
	}
	else if (SORT_231 == c)
		sb(s);
	else if (SORT_312 == c)
	{
		sb(s);
		rb(s);
	}
}

static void	sort_a(t_stack *s, int c)
{
	if (SORT_132 == c)
	{
		rra(s);
		sa(s);
	}
	else if (SORT_213 == c)
		sa(s);
	else if (SORT_231 == c)
		rra(s);
	else if (SORT_312 == c)
		ra(s);
	else if (SORT_321 == c)
	{
		ra(s);
		sa(s);
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
