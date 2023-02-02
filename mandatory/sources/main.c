/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:24 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/02 16:27:46 by junyojeo         ###   ########.fr       */
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
	ranked(&a, arr, a.size);
	quick_sort_stack(&a, &b, a.size);
	return (0);
}
