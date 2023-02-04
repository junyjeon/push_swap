/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:59:41 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/05 01:42:31 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pivot_init(t_pivot *pivot)
{
	pivot->min = 0;
	pivot->max = 0;
}

void	cnt_init(t_cnt *cnt)
{
	cnt->sa = 0;
	cnt->sb = 0;
	cnt->ra = 0;
	cnt->rb = 0;
	cnt->pa = 0;
	cnt->pb = 0;
}

void	stack_init(t_stack *a, t_stack *b)
{
	a->bottom = NULL;
	b->bottom = NULL;
	a->top = NULL;
	b->top = NULL;
	a->size = 0;
	b->size = 0;
}

int	compare_init(t_stack *s, t_compare *c)
{
	c->fir = s->top->val;
	c->sec = s->top->prev->val;
	c->thi = s->top->prev->prev->val;
	if (c->fir < c->sec && c->sec < c->thi && c->fir < c->thi)
		return (SORT_123);
	else if (c->fir < c->sec && c->sec > c->thi && c->fir < c->thi)
		return (SORT_132);
	else if (c->fir > c->sec && c->sec < c->thi && c->fir < c->thi)
		return (SORT_213);
	else if (c->fir < c->sec && c->sec > c->thi && c->fir > c->thi)
		return (SORT_231);
	else if (c->fir > c->sec && c->sec < c->thi && c->fir > c->thi)
		return (SORT_312);
	else if (c->fir > c->sec && c->sec > c->thi && c->fir > c->thi)
		return (SORT_321);
	return (0);
}
