/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:36:23 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 00:29:49 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	in_a_sort_five(t_stack *s, t_stack *s2)
{
	static int	cnt;

	cnt = 2;
	while (cnt)
	{
		if (s->top->rank == 0 || s->top->rank == 1)
		{
			pa(s, s2);
			cnt--;
		}
		else
			rb(s);
	}
	quick_sort_stack_b(s2, s, 3);
	quick_sort_stack(s2, s, 2, 0);
}

static void	in_b_sort_five(t_stack *s, t_stack *s2)
{
	static int	cnt;

	cnt = 2;
	while (cnt)
	{
		if (s->top->rank == 0 || s->top->rank == 1)
		{
			pb(s, s2);
			cnt--;
		}
		else
			ra(s);
	}
	quick_sort_stack(s, s2, 3, 0);
	quick_sort_stack_b(s, s2, 2);
}

void	sort_five(t_stack *s, t_stack *s2, char c)
{
	if (c == 'a')
		in_a_sort_five(s, s2);
	else if (c == 'b')
		in_b_sort_five(s, s2);
}
