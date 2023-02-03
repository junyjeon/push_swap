/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:34:12 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 01:15:56 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	in_b_sort_four(t_stack *s, t_stack *s2, t_compare *c)
{
	static int	tmp;

	pa(s2, s);
	hard_coding(s2, s, 3, 'b');
	tmp = s2->top->val;
	if (tmp > c->first)
		pb(s, s2);
	else if (c->first > tmp && tmp > c->second)
	{
		pb(s, s2);
		sb(s);
	}
	else if (c->second > tmp && tmp > c->third)
	{
		rrb(s);
		pb(s, s2);
		rb(s);
		rb(s);
	}
	else
	{
		pb(s, s2);
		rb(s);
	}
}

static void	in_a_sort_four(t_stack *s, t_stack *s2, t_compare *c)
{
	static int	tmp;

	pb(s, s2);
	hard_coding(s, s2, 3, 'a');
	tmp = s2->top->val;
	if (tmp < c->first)
		pa(s, s2);
	else if (c->first < tmp && tmp < c->second)
	{
		pa(s, s2);
		sa(s);
	}
	else if (c->second < tmp && tmp < c->third)
	{
		rra(s);
		pa(s, s2);
		ra(s);
		ra(s);
	}
	else
	{
		pa(s, s2);
		ra(s);
	}
}

void	sort_four(t_stack *s, t_stack *s2, char ch)
{
	t_compare	c;

	compare_init(s, &c);
	if (ch == 'a')
		in_a_sort_four(s, s2, &c);
	else if (ch == 'b')
		in_b_sort_four(s, s2, &c);
}
