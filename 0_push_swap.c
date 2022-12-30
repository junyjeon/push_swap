/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:24 by junyojeo          #+#    #+#             */
/*   Updated: 2022/12/29 22:00:22 by junyojeo         ###   ########.fr       */
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
	t_stack a;
	t_stack b;

	init(&a, &b, ar, ac);
	little_sort(&a, &b);
	//greedy_algorithm(&a, &b);
	//merge_sort(&a, &b);
	return (0);
}

//집에서 git push 안하고 온 나, MergeSort, checker만 완성하기
