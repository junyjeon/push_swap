/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:51:26 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/20 06:29:06 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

static void	swap(t_stack *s)
{
	int	val;

	if (s->size <= 1)
		return ;
	val = s->top->val;
	s->top->val = s->top->prev->val;
	s->top->prev->val = val;
}

void	ss(t_stack *a, t_stack *b, int flag)
{
	swap(a);
	swap(b);
	if (flag)
		write(1, "ss\n", 3);
}

void	sa(t_stack *a, int flag)
{
	swap(a);
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int flag)
{
	swap(b);
	if (flag)
		write(1, "sb\n", 3);
}
