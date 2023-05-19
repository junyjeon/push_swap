/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:36:23 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 21:09:42 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

static void	in_a_sort_five(t_stack *s, t_stack *s2)
{
	static int	cnt;

	cnt = 2;
	while (cnt)
	{
		if (s->top->rank == 0 || s->top->rank == 1)
		{
			pb(s, s2, 1);
			cnt--;
		}
		else
			ra(s, 1);
	}
	quick_sort_stack(s, s2, 3, 0);
	quick_sort_stack_b(s, s2, 2);
}

static void	in_b_sort_five(t_stack *s, t_stack *s2)
{
	static int	cnt;

	cnt = 2;
	while (cnt)
	{
		if (s->top->rank == 0 || s->top->rank == 1)
		{
			pb(s2, s, 1);
			cnt--;
		}
		else
			rb(s, 1);
	}
	quick_sort_stack(s2, s, 3, 0);
	quick_sort_stack_b(s2, s, 2);
}

void	sort_five(t_stack *s, t_stack *s2, char ch)
{
	if (ch == 'a')
		in_a_sort_five(s, s2);
	else if (ch == 'b')
		in_b_sort_five(s, s2);
}
