/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:52:11 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/01 21:20:30 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	revers_rotate(t_stack *s)
{
	t_info	*tmp;

	tmp = pop_front(s);
	push_back(s, tmp);
}

void	rrr(t_stack *a, t_stack *b)
{
	revers_rotate(a);
	revers_rotate(b);
	write(1, "rrr\n", 5);
}

void	rrb(t_stack *b)
{
	revers_rotate(b);
	write(1, "rrb\n", 5);
}

void	rra(t_stack *a)
{
	revers_rotate(a);
	write(1, "rra\n", 5);
}
