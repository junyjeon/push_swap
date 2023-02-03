/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:24:40 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/03 21:05:06 by junyojeo         ###   ########.fr       */
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

static int is_sorted(t_stack *s, int size, char c)
{
	t_info *cur;
	int i;

	i = -1;
	cur = s->top;
	while (++i < size && cur->prev)
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

static void	find_pivot(t_stack *s, int size, int *pivot_min, int *pivot_max)
{
	t_info	*cur;
	int		arr[size];
	int		tmp;
	int		i;
	int		j;

	i = -1;
	cur = s->top;
	while (++i < size)
	{
		arr[i] = cur->rank;
		cur = cur->prev;
	}
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	*pivot_min = arr[size / 3];
	*pivot_max = arr[size / 3 * 2];
}

void	reverse_rotation(t_stack *a, t_stack *b, t_cnt *cnt)
{
	int	i;

	i = 0;
	while (i < cnt->ra && i < cnt->rb)
	{
		rrr(a, b);
		i++;
	}
	while (i < cnt->ra)
	{
		rra(a);
		i++;
	}
	while (i < cnt->rb)
	{
		rrb(b);
		i++;
	}
}

static void	reverse_partition(t_stack *a, t_stack *b, t_cnt *cnt, int size)
{
	int			pivot_min;
	int			pivot_max;
	static int	i;
	
	pivot_min = 0;
	pivot_max = 0;
	find_pivot(b, size, &pivot_min, &pivot_max);
	i = -1;
	while (++i < size)
	{
		if (b->top->rank < pivot_min)
		{
			rb(b);
			cnt->rb++;
		}
		else
		{
			pa(a, b);
			cnt->pa++;
			if (a->top->rank < pivot_max)
			{
				ra(a);
				cnt->ra++;
			}
		}
	}
}

static void	partition(t_stack *a, t_stack *b, t_cnt *cnt, int size)
{
	int			pivot_min;
	int			pivot_max;
	static int	i;
	
	pivot_min = 0;
	pivot_max = 0;
	find_pivot(a, size, &pivot_min, &pivot_max);
	i = -1;
	while (++i < size)
	{
		if (a->top->rank > pivot_max)
		{
			ra(a);
			cnt->ra++;
		}
		else
		{
			pb(a, b);
			cnt->pb++;
			if (b->top->rank > pivot_min)
			{
				rb(b);
				cnt->rb++;
			}
		}
	}
}

static void	partition_when_first(t_stack *a, t_stack *b, t_cnt *cnt, int size)
{
	int	pivot_min;
	int	pivot_max;
	static int i;
	
	pivot_min = 0;
	pivot_max = 0;
	find_pivot(a, size, &pivot_min, &pivot_max);
	i = -1;
	while (++i < size)
	{
		if (a->top->rank > pivot_max)
		{
			ra(a);
			cnt->ra++;
		}
		else
		{
			pb(a, b);
			cnt->pb++;
			if (b->top->rank <= pivot_min)
			{
				rb(b);
				cnt->rb++;
			}
		}
	}
	cnt->rb = cnt->pb - cnt->rb;
}

void	quick_sort_stack_B(t_stack *a, t_stack *b, int size)
{
	t_cnt	cnt;
	static int		sorted;
	static int		i;

	sorted = is_sorted(b, size, 'b');
	if (sorted)
	{
		i = -1;
		while (++i < size)
			pa(a, b);
		return ;
	}
	if (size <= 3)
	{
		if (!sorted)
			hard_coding(b, a, size, 'b');
		i = -1;
		while (++i < size)
			pa(a, b);
		return ;
	}
	cnt_init(&cnt);
	reverse_partition(a, b, &cnt, size);;
	quick_sort_stack(a, b, cnt.pa - cnt.ra, 0);
	reverse_rotation(a, b, &cnt);
	quick_sort_stack(a, b, cnt.ra, 0);
	quick_sort_stack_B(a, b, cnt.rb);
}

void	quick_sort_stack(t_stack *a, t_stack *b, int size, int is_first)
{
	t_cnt		cnt;
	static int	sorted;

	sorted = is_sorted(a, size, 'a');
	if (sorted)
		return ;
	if (size <= 3)
	{
		if (!sorted)
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
		reverse_rotation(a, b, &cnt);
	}
	quick_sort_stack(a, b, cnt.ra, 0);
	quick_sort_stack_B(a, b, cnt.rb);
	quick_sort_stack_B(a, b, cnt.pb - cnt.rb);
}
