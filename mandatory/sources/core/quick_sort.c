/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:24:40 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/14 07:19:23 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cnt_init(t_cnt *cnt)
{
	cnt->sa = 0;
	cnt->sb = 0;
	cnt->ra = 0;
	cnt->rb = 0;
	cnt->pa = 0;
	cnt->pb = 0;
}

static int	is_sorted(t_stack *s, int size)
{
	t_info	*cur;
	int		i;

	i = -1;
	cur = s->top;
	while (++i < size && cur->prev)
	{
		if (cur->rank > cur->prev->rank)
			return (0);
		cur = cur->prev;
	}
	return (1);
}

void	a_to_b(t_stack *a, t_stack *b, int size, t_cnt *cnt)
{
	int	i;
	int	pivot_min;
	int	pivot_max;

	pivot_min = size / 3;
	pivot_max = size / 3 * 2;
	if (size < 3)
	{
		if (!is_sorted(a, size))
			hard_coding(a, b, size, 'a');
		return ;
	}
	i = -1;
	while (++i < size)
	{
		if (a->top->rank >= pivot_max)
		{
			cmd(a, b, "r", 'a');
			cnt->ra++;
		}
		else
		{
			cmd(a, b, "p", 'b');
			cnt->pb++;
			if (a->top->rank >= pivot_min)
			{
				cmd(a, b, "r", 'b');
				cnt->rb++;
			}
		}
	}
	i = 0;
	while (i < cnt->ra && i < cnt->rb)
	{
		cmd(a, b, "rrr", 'c');
		i++;
	}
	a_to_b(a, b, cnt->ra, cnt);
	b_to_a(a, b, cnt->rb, cnt);
	b_to_a(a, b, cnt->pb - cnt->rb, cnt);
	printf("OK\n");
}

void	b_to_a(t_stack *a, t_stack *b, int size, t_cnt *cnt)
{
	int	i;
	int	pivot_min;
	int	pivot_max;

	pivot_min = size / 3;
	pivot_max = size / 3 * 2;
	if (size < 3)
	{
		if (!is_sorted(b, size))
			hard_coding(a, b, size, 'b');
		return ;
	}
	i = -1;
	while (++i < size)
	{
		if (a->top->rank < pivot_min)
		{
			cmd(a, b, "r", 'b');
			cnt->rb++;
		}
		else
		{
			cmd(a, b, "p", 'a');
			cnt->pa++;
			if (a->top->rank < pivot_max)
			{
				cmd(a, b, "r", 'a');
				cnt->ra++;
			}
		}
	}
	a_to_b(a, b, cnt->pa - cnt->ra, cnt);
	i = 0;
	while (i < cnt->ra && i < cnt->rb)
	{
		cmd(a, b, "rrr", 'c');
		i++;
	}
	a_to_b(a, b, cnt->ra, cnt);
	b_to_a(a, b, cnt->rb, cnt);
}

void	quick_sort(t_stack *a, t_stack *b, int size)
{
	t_cnt	cnt;

	cnt_init(&cnt);
	a_to_b(a, b, size, &cnt);
}

