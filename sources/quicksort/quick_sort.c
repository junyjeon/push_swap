/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:24:40 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/05 21:53:28 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_sorted(t_stack *s, int size, char c)
{
	t_info	*cur;
	int		i;

	i = 0;
	cur = s->top;
	while (++i < size && cur)
	{
		if (c == 'a')
		{
			if (cur->rank > cur->prev->rank)
				return (0);
		}
		else if (c == 'b')
			if (cur->rank < cur->prev->rank)
				return (0);
		cur = cur->prev;
	}
	return (1);
}

void	quick_sort_stack_b(t_stack *a, t_stack *b, int size)
{
	t_cnt	cnt;
	int		i;

	if (size <= 3)
	{
		if (!is_sorted(b, size, 'b'))
			hard_coding(b, a, size, 'b');
		i = -1;
		while (++i < size)
			pa(a, b, 1);
		return ;
	}
	cnt_init(&cnt);
	reverse_partition(a, b, &cnt, size);
	quick_sort_stack(a, b, cnt.pa - cnt.ra, 0);
	rotation(a, b, &cnt);
	quick_sort_stack(a, b, cnt.ra, 0);
	quick_sort_stack_b(a, b, cnt.rb);
}

void	quick_sort_stack(t_stack *a, t_stack *b, int size, int is_first)
{
	t_cnt	cnt;

	if (size <= 3)
	{
		if (!is_sorted(a, size, 'a'))
			hard_coding(a, b, size, 'a');
		return ;
	}
	cnt_init(&cnt);
	if (is_first)
	{
		partition_when_first(a, b, &cnt, size);
		is_first = 0;
	}
	else
	{
		partition(a, b, &cnt, size);
		rotation(a, b, &cnt);
	}
	quick_sort_stack(a, b, cnt.ra, 0);
	quick_sort_stack_b(a, b, cnt.rb);
	quick_sort_stack_b(a, b, cnt.pb - cnt.rb);
}
