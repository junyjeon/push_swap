/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:24 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/09 05:36:20 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *ar)
{
	int ar_len;
	
	ar_len = ft_strlen(ar);
	write(2, ar, ar_len + 1);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*arr;

	if (argc < 2)
		print_error("Argment count is zero.\n");
	stack_init(&a, &b);
	arr = parsing_stack_and_array(&a, argc, argv);
	printf("%d\n", arr[1]);
	check_duplicate_and_sort(arr, a.size);
	if (a.size <= 3)
	{
		hard_coding(&a, &b, a.size, 'a');
		exit(1);
	}
	ranked(&a, arr);
	quick_sort(&a, &b, a.size);
	return (0);
}
