/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:24 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/08 21:20:01 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

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
	int		*arr;

	if (ac < 2)
		print_error("Argment count is zero.\n");
	stack_init(&a, &b);
	arr = parsing_stack_and_array(&a, argv, ac);
	check_duplicate_and_sort(arr, a.size);
	if (a.size <= 3)
	{
		hard_coding(&a, &b, a.size, 'a');
		exit(1);
	}
	else if (a.size >= 4)
	{
		print_error("hi");
	}
	//ranked(&a, arr);
	//quick_sort(&a, &b, a.size);
	return (0);
}

//정렬 되어있는지, 중복 값이 있는지
//4, 6
