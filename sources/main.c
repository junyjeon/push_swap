/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:24 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/20 06:39:36 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*arr;

	if (argc < 2)
		print_error("Argment count is zero.\n", 1);
	stack_init(&a, &b);
	arr = parse(&a, argc, argv);
	ranked(&a, arr, a.size);
	if (a.size <= 5)
		hard_coding(&a, &b, a.size, 'a');
	else
		quick_sort_stack(&a, &b, a.size, 1);
	exit(0);
}
