/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:24 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/08 14:33:53 by junyojeo         ###   ########.fr       */
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

static void	check_duplicate(t_stack *a)
{
	t_info	*cur;
	t_info	*cur2;

	cur = a->bottom;
	cur2 = a->bottom->next;
	while (cur)
	{
		while (cur2)
		{
			if (cur->val == cur2->val)
				print_error("Is duplicate error\n");
			cur2 = cur2->next;
		}
		cur = cur->next;
	}		
}

int	main(int ac, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		*arr;

	if (ac < 2)
		print_error("Argment error\n");
	stack_init(&a, &b);
	arr = parsing_stack_and_array(&a, argv, ac);
	if (a.size <= 3)
		hard_coding(&a, &b, a.size, 'a');
	check_duplicate(&a);
	sort_arr(&a, arr);
	ranked(&a, arr);
	quick_sort(&a, &b, a.size);
	return (0);
}

//정렬 되어있는지, 중복 값이 있는지
//4, 6
