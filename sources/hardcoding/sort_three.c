/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:29:26 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 00:30:17 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	in_b_sort_three(t_stack *s)
{
	if (sort_132 || sort_312 || first < second \
&& second < third && first < third)
	{
		if (first < second && second < third && first < third)
		{
			rb(s);
			sb(s);
			rrb(s);
		}
		if (sort_132)
			sb(s);
		rb(s);
		sb(s);
		rrb(s);
	}
	else if (sort_231 || sort_213)
	{
		if (sort_213)
		{
			rb(s);
			sb(s);
			rrb(s);
		}
		sb(s);
	}
}

static void	in_a_sort_three(t_stack *s)
{
	if (sort_132 || sort_312)
	{
		if (sort_312)
			sa(s);
		ra(s);
		sa(s);
		rra(s);
	}
	else if (sort_231 || sort_213 || first > second \
&& second > third && first > third)
	{
		if (first > second && second > third && first > third)
			sa(s);
		if (sort_231)
		{
			ra(s);
			sa(s);
			rra(s);
		}
		sa(s);
	}
}

static void	sort_b(t_stack *s)
{
	if (first < second && second < third && first < third)
	{
		sb(s);
		rrb(s);
	}
	else if (sort_132)
		rb(s);
	else if (sort_213)
	{
		rrb(s);
	}
	else if (sort_231)
		sb(s);
	else if (sort_312)
	{
		sb(s);
		rb(s);
	}
}

static void	sort_a(t_stack *s)
{
	if (sort_132)
	{
		rra(s);
		sa(s);
	}
	else if (sort_213)
		sa(s);
	else if (sort_231)
		rra(s);
	else if (sort_312)
		ra(s);
	else if (first > second && second > third && first > third)
	{
		ra(s);
		sa(s);
	}
}

void	sort_three(t_stack *s, char c)
{
	if (s->size <= 3)
	{
		if (c == 'a')
			sort_a(s);
		else if (c == 'b')
			sort_b(s);
	}
	else
	{
		if (c == 'a')
			in_a_sort_three(s);
		else if (c == 'b')
			in_b_sort_three(s);
	}
}
