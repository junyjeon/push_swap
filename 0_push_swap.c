/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:24 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/07 17:45:36 by junyojeo         ###   ########.fr       */
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

void	print_error(char *ar)
{
	int ar_len;
	
	ar_len = ft_strlen(ar);
	write(2, ar, ar_len + 1);
	exit(1);
}

int	main(int ac, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*arg;

	if (ac < 2)
		print_error("Argment error\n");
	stack_init(&a, &b);
	arg = parsing_stack_and_array(&a, argv, ac);
	sort_arr(&a, arg);
	ranked(&a, arg);
	quick_sort(&a, &b, a.size);
	return (0);
}
//정렬 되어있는지, 중복 값이 있는지
