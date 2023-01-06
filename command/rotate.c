/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:06 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/06 16:51:58 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 4);
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
