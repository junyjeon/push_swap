/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_error_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:56:47 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/04 13:15:43 by junyojeo         ###   ########.fr       */
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

void	error_check(t_stack *a)
{
	t_info *cur1;
	t_info *cur2;
	int tmp;
	int swap_cnt;

	if (a->size < 2)
		return ;
	swap_cnt = 0;
	cur1 = a->bottom;
	cur2 = a->bottom;
	while (cur1)
	{
		while (cur2)
		{
			if (cur2->val > cur2->next->val && cur2)
			{
				tmp = cur2->val;
				cur2->val = cur2->next->val;
				cur2->next->val = tmp;
				swap_cnt++;
			}
			cur2 = cur2->next;
		}
		if (cur1 == cur1->next)
			print_error("Argument is duplicated.\n");
		cur1 = cur1->next;
	}
	if (swap_cnt == 0)
		print_error("It's already sorted.\n");
}
