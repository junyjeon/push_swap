/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:24 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 21:25:01 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*arr;

	if (argc < 2)
		print_error("Argment count is zero.\n");
	stack_init(&a, &b);
	arr = parse(&a, argc, argv);
	ranked(&a, arr, a.size);
	if (a.size <= 5)
		hard_coding(&a, &b, a.size, 'a');
	else
		quick_sort_stack(&a, &b, a.size, 1);
	while (a.size--)
	{
		free(a.top);
		a.top = a.top->prev;
	}
	return (0);
}

