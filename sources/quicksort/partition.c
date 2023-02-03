/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:54:17 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 00:22:31 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	reverse_partition(t_stack *a, t_stack *b, t_cnt *cnt, int size)
{
	t_pivot	pivot;
	int		i;

	pivot_init(&pivot);
	find_pivot(b, size, &pivot);
	i = -1;
	while (++i < size)
	{
		if (b->top->rank < pivot.min)
		{
			rb(b);
			cnt->rb++;
		}
		else
		{
			pa(a, b);
			cnt->pa++;
			if (a->top->rank < pivot.max)
			{
				ra(a);
				cnt->ra++;
			}
		}
	}
}

void	partition(t_stack *a, t_stack *b, t_cnt *cnt, int size)
{
	t_pivot	pivot;
	int		i;

	pivot_init(&pivot);
	find_pivot(a, size, &pivot);
	i = -1;
	while (++i < size)
	{
		if (a->top->rank > pivot.max)
		{
			ra(a);
			cnt->ra++;
		}
		else
		{
			pb(a, b);
			cnt->pb++;
			if (b->top->rank > pivot.min)
			{
				rb(b);
				cnt->rb++;
			}
		}
	}
}

void	partition_when_first(t_stack *a, t_stack *b, t_cnt *cnt, int size)
{
	t_pivot	pivot;
	int		i;

	pivot_init(&pivot);
	find_pivot(a, size, &pivot);
	i = -1;
	while (++i < size)
	{
		if (a->top->rank > pivot.max)
		{
			ra(a);
			cnt->ra++;
		}
		else
		{
			pb(a, b);
			cnt->pb++;
			if (b->top->rank <= pivot.min)
			{
				rb(b);
				cnt->rb++;
			}
		}
	}
	cnt->rb = cnt->pb - cnt->rb;
}
