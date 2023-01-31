/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:24:40 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/31 20:00:41 by junyojeo         ###   ########.fr       */
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
		arr[i] = cur->val;
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
		if (i == size / 3)
			*pivot_min = arr[i];
		else if (i == size / 3 * 2 + size % 3)
			*pivot_max = arr[i];
	}
}

void	partition_B(t_stack *a, t_stack *b, t_cnt *cnt, int size)
{
	int	pivot_min;
	int	pivot_max;
	int i;
	
	pivot_min = 0;
	pivot_max = 0;
	find_pivot(a, size, &pivot_min, &pivot_max);
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
			if (b->top->rank < pivot_max)
			{
				ra(a);
				cnt->ra++;
			}
		}
	}
	i = 0;
	while (i < cnt->ra && i < cnt->rb)
	{
		rrr(a, b);
		i++;
	}
	while (i < cnt->ra)
	{
		rra(b);
		i++;
	}
	while (i < cnt->rb)
	{
		rrb(b);
		i++;
	}
}

void	partition_A(t_stack *a, t_stack *b, t_cnt *cnt, int size)
{
	int	pivot_min;
	int	pivot_max;
	int i;
	
	pivot_min = 0;
	pivot_max = 0;
	printf("size : %d\n", size);
	find_pivot(a, size, &pivot_min, &pivot_max);
	printf("min : %d, max : %d\n", pivot_min, pivot_max);
	i = -1;
	while (++i < size)
	{
		if (a->top->rank >= pivot_max)
		{
			ra(a);
			cnt->ra++;
		}
		else
		{
			pb(a, b);
			cnt->pb++;
			if (b->top->rank >= pivot_min)
			{
				rb(b);
				cnt->rb++;
			}
		}
	}
	i = 0;
	while (i < cnt->ra && i < cnt->rb)
	{
		rrr(a, b);
		i++;
	}
	while (i < cnt->ra)
	{
		rra(b);
		i++;
	}
	while (i < cnt->rb)
	{
		rrb(b);
		i++;
	}
}

void	showmethemoney(t_stack *a, t_stack *b)
{
	t_info	*cur;
	t_info	*cur2;


	cur = a->top;
	cur2 = b->top;
	while (cur)
	{
		printf("a. val: %d, rank: %d, asize: %d\n", cur->val, cur->rank, a->size);
		cur = cur->prev;
	}
	while (cur2)
	{
		printf("b. val: %d, rank: %d, bsize: %d\n", cur2->val, cur2->rank, b->size);
		cur2 = cur2->prev;
	}
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

static void	quick_sort_stack_B(t_stack *a, t_stack *b, int size)
{
	t_cnt	cnt;
	int	i;

	if (is_sorted(b, size, 'b'))
	{
		i = -1;
		while (++i < size)
			pa(a, b);
		return ;
	}
	if (size <= 3)
	{
		printf("0.BTA || size : %d\n", size);
		showmethemoney(a, b);
		hard_coding(b, size, 'b');
		i = -1;
		while (++i < size)
			pa(a, b);
		return ;
	}
	cnt_init(&cnt);
	partition_B(a, b, &cnt, size);
	printf("1.BTA\n");
	showmethemoney(a, b);
	quick_sort_stack(a, b, cnt.pa - cnt.ra);
	printf("2.BTA\n");
	showmethemoney(a, b);
	quick_sort_stack(a, b, cnt.ra);
	printf("3.BTA\n");
	showmethemoney(a, b);
	quick_sort_stack_B(a, b, cnt.rb);
	printf("4.BTA\n");
	showmethemoney(a, b);
}

void	quick_sort_stack(t_stack *a, t_stack *b, int size)
{
	t_cnt	cnt;

	printf("0.ATB || size : %d\n", size);
	showmethemoney(a, b);
	if (is_sorted(a, size, 'a'))
		return ;
	if (size <= 3)
	{
		printf("0.BTA || size : %d\n", size);
		showmethemoney(a, b);
		hard_coding(a, size, 'a');
		return ;
	}
	cnt_init(&cnt);
	partition_A(a, b, &cnt, size);
	printf("1.ATB\n");
	showmethemoney(a, b);
	quick_sort_stack(a, b, cnt.ra);
	printf("2.ATB\n");
	showmethemoney(a, b);
	quick_sort_stack_B(a, b, cnt.rb);
	printf("3.ATB\n");
	showmethemoney(a, b);
	quick_sort_stack_B(a, b, cnt.pb - cnt.rb);
	printf("4.ATB\n");
	showmethemoney(a, b);
}
