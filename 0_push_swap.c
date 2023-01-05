/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:24 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/05 23:00:35 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

//int	find_best(t_stack *a, t_stack *b, int data_a, int data_b);
//{
//	t_info *tmp;
//	int		i;
	
//	i = 0;
//	loc_a = find_loc_a(a, info->data);
//}

//int	greedy_algorithm(t_stack *a, t_stack *b)
//{
//	int data_a;
//	int data_b;

//	data_a = 0;
//	data_b = 0;
//	while (b->size)
//	{
//		find_best(a, b, data_a, data_b);
		
//	}	
//	return (0);
//}

int	main(int ac, char **ar)
{
	t_stack	a;
	t_stack	b;

	1. init()
	2. make_stack(join, split, atoi, int range)
	3. make_arr(atoi)
	4. arr_sort(merge_sort)
	5. sorted_arr->(overlab_check, sorted)
	if (ac < 2)
		print_error("Argment error\n");
	stack_init(a, b);
	parsing(&a, &b, ar, ac);
	make_array
	sorted(a, arr);
	error_check(arr, a->size);
	little_sort(&a, &b);
	//greedy_algorithm(&a, &b);
	//merge_sort(&a, &b);
	return (0);
}

//집에서 git push 안하고 온 나, MergeSort, checker만 완성하기
