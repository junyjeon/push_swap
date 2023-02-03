/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_little_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:11:40 by junyojeo          #+#    #+#             */
/*   Updated: 2022/11/29 11:11:40 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	hard_coding(t_stack *s, t_stack *s2, int size, char ch)
{
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if (ch == 'a' && s->top->val > s->top->prev->val)
			sa(s, 1);
		else if (ch == 'b' && s->top->val < s->top->prev->val)
			sb(s, 1);
	}
	else if (size == 3)
		sort_three(s, ch);
	else if (size == 4)
		sort_four(s, s2, ch);
	else if (size == 5)
		sort_five(s, s2, ch);
}
