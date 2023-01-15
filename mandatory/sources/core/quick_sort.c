/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:24:40 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/15 21:39:39 by junyojeo         ###   ########.fr       */
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

static int	is_sorted(t_stack *s, int size, char c)
{
	t_info	*cur;
	int		i;

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

static int	find_pivot(t_stack *s, int size, int *pivot_min, int pivot_max)
{
	t_info	*cur;
	t_info	*cur2;
	int		min;
	int		i;
	int		j;

	cur = s->top;
	cur2 = s->top;
	i = -1;
	while (i < size && cur)
	{
		j = -1;
		while (++j < size)
		{
			min = cur->val;
			if (min < cur2->val)
				min = cur->val;
			else
				min = cur2->val;
			cur2 = cur2->prev; 
		}
		if (i == size / 3)	
			pivot_min = i;
		else if (i == size / 3 * 2)
			pivot_max = i;	
		cur = cur->prev; 
	}
}

void	a_to_b(t_stack *a, t_stack *b, int size)
{
	t_cnt	cnt;
	int		i;
	int		pivot_min;
	int		pivot_max;

	cnt_init(&cnt);
	pivot_min = size / 3;
	pivot_max = size / 3 * 2;
	if (size <= 3)
	{
		if (!is_sorted(a, size, 'a'))
			hard_coding(a, size, 'a');
		return ;
	}
	i = -1;
	while (++i < size)
	{
		if (a->top->rank >= pivot_max)
		{
			ra(a);
			cnt.ra++;
		}
		else
		{
			pb(a, b);
			cnt.pb++;
			if (b->top->rank >= pivot_min && b->size != 1)
			{
				rb(b);
				cnt.rb++;
			}
		}
	}
	i = 0;
	while (i < cnt.ra && i < cnt.rb)
	{
		rrr(a, b);
		i++;
	}
	while (i < cnt.ra)
	{
		rra(b);
		i++;
	}
	while (++i < cnt.rb)
	{
		rrb(b);
		i++;
	}
	t_info	*cur;
	t_info	*cur2;

	cur = a->top;
	cur2 = b->top;
	printf("1_ a_to_b\n");
	while (cur)
	{
		printf("a. val: %d, rank: %d\n", cur->val, cur->rank);
		cur = cur->prev;
	}
	while (cur2)
	{
		printf("b. val: %d, rank: %d\n", cur2->val, cur2->rank);
		cur2 = cur2->prev;
	}
	a_to_b(a, b, cnt.ra);
	cur = a->top;
	cur2 = b->top;
	printf("2_ a_to_b\n");
	while (cur)
	{
		printf("a. val: %d, rank: %d\n", cur->val, cur->rank);
		cur = cur->prev;
	}
	while (cur2)
	{
		printf("b. val: %d, rank: %d\n", cur2->val, cur2->rank);
		cur2 = cur2->prev;
	}
	b_to_a(a, b, cnt.rb);
	cur = a->top;
	cur2 = b->top;
	printf("3_ b_to_a\n");
	while (cur)
	{
		printf("a. val: %d, rank: %d\n", cur->val, cur->rank);
		cur = cur->prev;
	}
	while (cur2)
	{
		printf("b. val: %d, rank: %d\n", cur2->val, cur2->rank);
		cur2 = cur2->prev;
	}
	b_to_a(a, b, cnt.pb - cnt.rb);
	cur = a->top;
	cur2 = b->top;
	printf("4_ b_to_a\n");
	while (cur)
	{
		printf("a. val: %d, rank: %d\n", cur->val, cur->rank);
		cur = cur->prev;
	}
	while (cur2)
	{
		printf("b. val: %d, rank: %d\n", cur2->val, cur2->rank);
		cur2 = cur2->prev;
	}
}

void	b_to_a(t_stack *a, t_stack *b, int size)
{
	t_cnt	cnt;
	int		i;
	int		j;
	int		pivot_min;
	int		pivot_max;

	cnt_init(&cnt);
	//정렬 되었는지 여기서 확인?
	//피벗 두개도 여기서 확인?
	find_pivot(b, size, NULL, NULL);
	if (size <= 3)
	{
		if (!is_sorted(b, size, 'b'))
			hard_coding(b, size, 'b');
		while (size--)
			pa(a, b);
		return ;
	}
	i = -1;
	while (++i < size)
	{
		if (b->top->rank < pivot_min)
		{
			rb(b);
			cnt.rb++;
		}
		else
		{
			pa(a, b);
			cnt.pa++;
			if (a->top->rank < pivot_max && a->size != 1)
			{
				ra(a);
				cnt.ra++;
			}
		}
	}
	a_to_b(a, b, cnt.pa - cnt.ra);
	i = 0;
	while (i < cnt.ra && i < cnt.rb)
	{
		rrr(a, b);
		i++;
	}
	while (i < cnt.ra)
	{
		rra(b);
		i++;
	}
	while (++i < cnt.rb)
	{
		rrb(b);
		i++;
	}
	a_to_b(a, b, cnt.ra);
	b_to_a(a, b, cnt.rb);
}

void	quick_sort(t_stack *a, t_stack *b, int size)
{
	t_info	*cur;
	t_info	*cur2;

	cur = a->top;
	cur2 = b->top;
	printf("Before\n");
	while (cur)
	{
		printf("a. val: %d, rank: %d\n", cur->val, cur->rank);
		cur = cur->prev;
	}
	a_to_b(a, b, size);
	cur = a->top;
	cur2 = b->top;
	printf("After\n");
	while (cur)
	{
		printf("a. val: %d, rank: %d\n", cur->val, cur->rank);
		cur = cur->prev;
	}
	while (cur2)
	{
		printf("b. val: %d, rank: %d\n", cur2->val, cur2->rank);
		cur2 = cur2->prev;
	}
}

