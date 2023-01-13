/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:24 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/14 05:50:13 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*arr;

	if (argc < 2)
		print_error("Argment count is zero.\n");
	stack_init(&a, &b);
	arr = parsing_stack_and_array(&a, argc, argv);
	check_duplicate_and_sort(arr, a.size);
	if (a.size <= 3)
	{
		hard_coding(&a, &b, a.size, 'a');
		exit(1);
	}
	ranked(&a, arr);
	
	pb(&a, &b);
	t_info	*cur;
	t_info	*cur2;

	cur = a.top;
	cur2 = b.top;
	while (cur)
	{
		printf("1. val: %d, rank: %d\n", cur->val, cur->rank);
		cur = cur->prev;
	}
	while (cur2)
	{
		printf("2. val: %d, rank: %d\n", cur2->val, cur2->rank);
		cur2 = cur2->prev;
	}
	pa(&a, &b);
	//quick_sort(&a, &b, a.size);
	return (0);
}
