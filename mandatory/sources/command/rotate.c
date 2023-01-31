/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:06 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/31 16:49:26 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack *s)
{
	t_info *tmp;

	if (s->size <= 1)
		return (0);
	tmp = pop_back(s);
	push_front(s, tmp);
	return (1);
}

void	rr(t_stack *a, t_stack *b)
{
	if (!(rotate(a) && rotate(b)))
		return ;
	write(1, "rr\n", 4);
}

void	ra(t_stack *a)
{
	if (!rotate(a))
		return ;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (!rotate(b))
		return ;
	write(1, "rb\n", 3);
}
