/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:52:11 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/07 16:15:38 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	revers_rotate(t_stack *s)
{
	if (s->size <= 1)
		return ;
	s->top->next = s->bottom;
	s->bottom->prev = s->top;
	s->top = s->bottom;
	s->bottom = s->bottom->next;
	s->top->next = NULL;
	s->bottom->prev = NULL;
}

void	rrr(t_stack *a, t_stack *b)
{
	revers_rotate(a);
	revers_rotate(b);
	write(1, "rrr\n", 4);
}

void	rrb(t_stack *b)
{
	revers_rotate(b);
	write(1, "rrb\n", 4);
}

void	rra(t_stack *a)
{
	revers_rotate(a);
	write(1, "rra\n", 4);
}
