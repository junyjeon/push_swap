/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_rotate_rr_rrr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:06 by junyojeo          #+#    #+#             */
/*   Updated: 2022/12/09 19:39:32 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}

void	revers_rotate(t_stack *s)
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

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 4);
}

void	rotate(t_stack *s)
{
	if (s->size <= 1)
		return ;
	s->top->next = s->bottom;
	s->bottom->prev = s->top;
	s->bottom = s->top;
	s->top = s->top->prev;
	s->top->next = NULL;
	s->bottom->prev = NULL;
}

void	rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}
