/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:06 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 01:56:45 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	rotate(t_stack *s)
{
	t_info	*tmp;

	tmp = pop_back(s);
	push_front(s, tmp);
	return (1);
}

void	rr(t_stack *a, t_stack *b, int flag)
{
	rotate(a);
	rotate(b);
	if (flag)
		write(1, "rr\n", 3);
}

void	ra(t_stack *a, int flag)
{
	if (a->size <= 1)
		return ;
	rotate(a);
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_stack *b, int flag)
{
	if (b->size <= 1)
		return ;
	rotate(b);
	if (flag)
		write(1, "rb\n", 3);
}
