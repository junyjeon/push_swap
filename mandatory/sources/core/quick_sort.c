/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:24:40 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/30 23:12:38 by junyojeo         ###   ########.fr       */
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

// static int	is_sorted(t_stack *s, int size, char c)
// {
// 	t_info	*cur;
// 	int		i;

// 	i = -1;
// 	cur = s->top;
// 	while (++i < size && cur->prev)
// 	{
// 		if (c == 'a')
// 		{
// 			if (cur->rank > cur->prev->rank)
// 				return (0);
// 		}
// 		else if (c == 'b')
// 			if (cur->rank < cur->prev->rank)
// 				return (0);
// 		cur = cur->prev;
// 	}
// 	return (1);
// }

//static void	find_pivot(t_stack *s, int size, int *pivot_min, int *pivot_max)
//{
//	t_info	*cur;
//	t_info	*cur2;
//	int		min;
//	int		i;
//	int		j;

//	cur = s->top;
//	cur2 = s->top;
//	i = -1;
//	while (i < size && cur)
//	{
//		j = -1;
//		while (++j < size)
//		{
//			min = cur->val;
//			if (min < cur2->val)
//				min = cur->val;
//			else
//				min = cur2->val;
//			cur2 = cur2->prev; 
//		}
//		if (i == size / 3)	
//			*pivot_min = i;
//		else if (i == size / 3 * 2)
//			*pivot_max = i;	
//		cur = cur->prev; 
//	}
//}

void	partition(t_stack *a, t_stack *b, t_cnt *cnt, int size)
{
	int		pivot_min;
	int		pivot_max;
	int i;
	
	pivot_min = size / 3;
	pivot_max = size / 3 * 2 + size % 3;
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
				if (b->size <= 1)
					cnt->rb++;
				else
				{
					rb(b);
					cnt->rb++;
				}
			}
			t_info	*cur;
			t_info	*cur2;

			printf("asize: %d\n", a->size);
			printf("0.ATB\n");
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

void	quicksort_stack_b(t_stack *a, t_stack b, int size)
{
		
}

void	quick_sort_stack(t_stack *a, t_stack *b, int size)
{
	t_cnt	cnt;
	t_info	*cur;
	t_info	*cur2;

	printf("asize: %d\n", a->size);
	printf("0.ATB\n");
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
	if (size <= 3)
	{
		hard_coding(a, size, 'a');
		return ;
	}
	cnt_init(&cnt);
	partition(a, b, &cnt, size);
	quick_sort_stack(a, b, cnt.ra);
	printf("1.ATB\n");
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
	quicksort_stack_b(a, b, cnt.rb);
	//quicksort_stack_b(a, b, cnt.pb - cnt.rb);
}

//void	quicksort_stack_b(t_stack *a, t_stack *b, int size)
//{
//	t_cnt	cnt;
//	int		i;
//	int		pivot_min;
//	int		pivot_max;

//	if (size <= 3)
//	{
//		hard_coding(b, size, 'b');
//		while (size--)
//			pa(a, b);
//		return ;
//	}
//	cnt_init(&cnt);
//	pivot_min = size / 3;
//	pivot_max = size / 3 * 2;
//	//정렬 되었는지 여기서 확인?
//	//피벗 두개도 여기서 확인?
//	i = -1;
//	while (++i < size)
//	{
//		if (b->top->rank < pivot_min)
//		{
//			rb(b);
//			cnt.rb++;
//		}
//		else
//		{
//			pa(a, b);
//			cnt.pa++;
//			if (a->top->rank < pivot_max && a->size != 1)
//			{
//				ra(a);
//				cnt.ra++;
//			}
//		}
//	}
//	quick_sort_stack(a, b, cnt.pa - cnt.ra);
//	i = 0;
//	while (i < cnt.ra && i < cnt.rb)
//	{
//		rrr(a, b);
//		i++;
//	}
//	while (i < cnt.ra)
//	{
//		rra(b);
//		i++;
//	}
//	while (i++ < cnt.rb)
//		rrb(b);
//	quick_sort_stack(a, b, cnt.ra);
//	quick_sort_stack_b(a, b, cnt.rb);
//}

//void	quick_sort(t_stack *a, t_stack *b, int size)
//{
//	a_to_b(a, b, size);
//}

