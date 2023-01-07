/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_0_quick_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:24:40 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/07 17:57:09 by junyojeo         ###   ########.fr       */
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

void	a_to_b(t_stack *a, t_stack *b, t_cnt cnt, int size)
{
	t_info	*cur;
	int	i;
	int	pivot_min;
	int	pivot_max;

	cnt_init(&cnt);
	pivot_min = size / 3;
	pivot_max = size / 3 * 2;
	if (size < 3)
	{
		//if (!is_sorted())
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
	a_to_b(a, b, cnt, cnt.ra);
	b_to_a(a, b, cnt, cnt.rb);
	b_to_a(a, b, cnt, cnt.pb - cnt.rb);
}

//a에서 pivot_max 보다 작은 것만 pb, size <= 5이면 hard_codin()만
//b에서 pivot_max 개수만큼 ra
//b에서 (new)pivot_min보다 큰 것만 pa

void	b_to_a(t_stack *a, t_stack *b, t_cnt cnt, int size)
{
	t_info	*cur;
	int	i;
	int	pivot_min;
	int	pivot_max;

	cnt_init(&cnt);
	pivot_min = size / 3;
	pivot_max = size / 3 * 2;
	if (size < 3)
	{
		//if (!is_sorted())
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
	a_to_b(a, b, cnt, cnt.pa - cnt.ra);
	i = 0;
	while (i < cnt.ra && i < cnt.rb)
	{
		cmd(a, b, "rrr", 'c');
		i++;
	}
	a_to_b(a, b, cnt, cnt.ra);
	b_to_a(a, b, cnt, cnt.rb);
}

void	quick_sort(t_stack *a, t_stack *b, int size)
{
	t_cnt	cnt;

	cnt_init(&cnt);
	a_to_b(a, b, cnt, size);
}
