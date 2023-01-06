/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:51:26 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/06 16:52:01 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack *s)
{
	int	tmp;

	if (s->size <= 1)
		return ;
	tmp = s->bottom->val;
	s->bottom->val = s->bottom->next->val;
	s->bottom->next->val = tmp;
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}
