/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:24 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/07 21:40:25 by junyojeo         ###   ########.fr       */
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

int	main(int ac, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*arg;

	if (ac < 2)
		print_error("Argment error\n");
	stack_init(&a, &b);
	arg = parsing_stack_and_array(&a, argv, ac);
	if (a.size <= 3)
		hard_coding(&a, &b, a.size, 'a');
	sort_arr(&a, arg);
	ranked(&a, arg);
	quick_sort(&a, &b, a.size);
	return (0);
}
//정렬 되어있는지, 중복 값이 있는지
//4, 6
