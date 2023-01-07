/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_0_quick_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:24:40 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/07 21:49:46 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cnt_init(t_cnt *cnt)
{
	cnt->sa = 0;
	cnt->sb = 0;
	cnt->ra = 0;
	cnt->rb = 0;
	cnt->rra = 0;
	cnt->rrb = 0;
	cnt->pa = 0;
	cnt->pb = 0;
}
static int	is_sorted(t_stack *s, int size)
{
	t_info	*cur;
	int		i;

	cur = s->top;
	i = -1;
	while (++i < size)
	{
		if (cur->rank > cur->prev->rank)
			return (0);
		cur = cur->prev;
	}
	return (1);
}

void	a_to_b(t_stack *a, t_stack *b, int size)
{
	t_info	*cur;
	t_cnt	cnt;
	int	i;
	int	pivot_min;
	int	pivot_max;

	cnt_init(&cnt);
	pivot_min = size / 3;
	pivot_max = size / 3 * 2;
	if (size < 3)
	{
		if (!is_sorted(a, size))
			hard_coding(a, b, size, 'a');
		return ;
	}
	cur = a->top;
	i = -1;
	while (++i < size)
	{
		if (pivot_max <= cur->rank)
		{
			cmd(a, b, "r", 'a');
			cnt.ra++;
		}
		else
		{
			cmd(a, b, "p", 'b');
			cnt.pb++;
			if (cur->rank >= pivot_min)
			{
				cmd(a, b, "r", 'b');
				cnt.rb++;
			}
		}
		cur = cur->prev;
	}
	i = 0;
	while (i < cnt.ra && i < cnt.rb)
	{
		cmd(a, b, "rrr", 'c');
		i++;
	}
	a_to_b(a, b, cnt.ra);
	b_to_a(a, b, cnt.rb);
	b_to_a(a, b, cnt.pb - cnt.rb);
}

void	b_to_a(t_stack *a, t_stack *b, int size)
{
	t_info	*cur;
	t_cnt	cnt;
	int	i;
	int	pivot_min;
	int	pivot_max;

	cnt_init(&cnt);
	pivot_min = size / 3;
	pivot_max = size / 3 * 2;
	if (size < 3)
	{
		if (!is_sorted(b, size))
			hard_coding(a, b, size, 'b');
		return ;
	}
	cur = a->top;
	i = -1;
	while (++i < size)
	{
		if (cur->rank < pivot_min)
		{
			cmd(a, b, "r", 'b');
			cnt.rb++;
		}
		else
		{
			cmd(a, b, "p", 'a');
			cnt.pa++;
			if (cur->rank < pivot_max)
			{
				cmd(a, b, "r", 'a');
				cnt.ra++;
			}
		}
		cur = cur->next;
	}
	a_to_b(a, b, cnt.pa - cnt.ra);
	i = 0;
	while (i < cnt.ra && i < cnt.rb)
	{
		cmd(a, b, "rrr", 'c');
		i++;
	}
	a_to_b(a, b, cnt.ra);
	b_to_a(a, b, cnt.rb);
}

void	quick_sort(t_stack *a, t_stack *b, int size)
{
	a_to_b(a, b, size);
}
