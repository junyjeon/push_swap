/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_rotate_rr_rrr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:06 by junyojeo          #+#    #+#             */
/*   Updated: 2022/11/27 17:56:29 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}

void	rrb(t_stack *b)
{
	if (b->size <= 1)
		return ;
	b->top->dir->next = b->bottom->dir;
	b->bottom->dir->prev = b->top->dir;
	b->top->dir = b->bottom->dir;
	b->bottom->dir = b->bottom->dir->next;
	b->top->dir->next = NULL;
	b->bottom->dir->prev = NULL;
	write(1, "rra\n", 4);
}

void	rra(t_stack *a)//스택 a의 bottom을 top로 이동
{
	if (a->size <= 1)
		return ;
	a->top->dir->next = a->bottom->dir;
	a->bottom->dir->prev = a->top->dir;
	a->top->dir = a->bottom->dir;
	a->bottom->dir = a->bottom->dir->next;
	a->top->dir->next = NULL;
	a->bottom->dir->prev = NULL;
	write(1, "rra\n", 4);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 4);
}

void	rb(t_stack *b)
{
	if (b->size <= 1)
		return ;
	b->top->dir->next = b->bottom->dir;
	b->bottom->dir->prev = b->top->dir;
	b->bottom->dir = b->top->dir;
	b->top->dir = b->top->dir->prev;
	b->top->dir->next = NULL;
	b->bottom->dir->prev = NULL;
	write(1, "rb\n", 3);
}

void	ra(t_stack *a)//스택 a의 top을 bottom으로 이동
{
	if (a->size <= 1)
		return ;
	// top->next = bottom;
	// bottom->prev = top;
	// bottom = top;
	// top = top->prev;
	// top->next = NULL;
	// bottom->prev = NULL;
	a->top->dir->next = a->bottom->dir;
	a->bottom->dir->prev = a->top->dir;
	a->bottom->dir = a->top->dir;
	a->top->dir = a->top->dir->prev;
	a->top->dir->next = NULL;
	a->bottom->dir->prev = NULL;
	write(1, "ra\n", 3);
}
