/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:06 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 00:22:31 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	rotate(t_stack *s)
{
	t_info	*tmp;

	tmp = pop_back(s);
	push_front(s, tmp);
	return (1);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	ra(t_stack *a)
{
	if (a->size <= 1)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (b->size <= 1)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
}
