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

static void	in_B_sort_three(t_stack *s)
{
	if (sort_132 || sort_312 || sort_123)
	{
		if (sort_123)
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

static void	in_A_sort_three(t_stack *s)
{
	if (sort_132 || sort_312)
	{
		if (sort_312)
			sa(s);
		ra(s);
		sa(s);
		rra(s);
	}
	else if (sort_231 || sort_213 || sort_321)
	{
		if (sort_321)
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

void	hard_coding(t_stack *s, int size, char c)
{
	if (s->size <= 3)
	{
		if (size == 1)
			return;
		else if (size == 2)
		{
			if (c == 'a' && first > second)
				sa(s);
			else if (c == 'b' && first < second)
				sb(s);
		}
		else if (size == 3)
		{
			if (c == 'a')
				in_A_sort_three(s);
			else if (c == 'b')
				in_B_sort_three(s);
		}
	}
	else
	{
		if (size == 1)
			return;
		else if (size == 2)
		{
			if (c == 'a' && first > second)
				sa(s);
			else if (c == 'b' && first < second)
				sb(s);
		}
		else if (size == 3)
		{
			if (c == 'a')
				in_A_sort_three(s);
			else if (c == 'b')
				in_B_sort_three(s);
		}
	}
}
