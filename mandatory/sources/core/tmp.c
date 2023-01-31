
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

//static void	showmethemoney(t_stack *a, t_stack *b)
//{
//	t_info	*cur;
//	t_info	*cur2;


//	cur = a->top;
//	cur2 = b->top;
//	while (cur)
//	{
//		printf("a. val: %d, rank: %d, asize: %d\n", cur->val, cur->rank, a->size);
//		cur = cur->prev;
//	}
//	while (cur2)
//	{
//		printf("b. val: %d, rank: %d, bsize: %d\n", cur2->val, cur2->rank, b->size);
//		cur2 = cur2->prev;
//	}
//}
