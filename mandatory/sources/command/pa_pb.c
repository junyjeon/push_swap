/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:52:34 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/14 00:46:01 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	t_info	*tmp;

	if (!a->size)
		return ;
	tmp = pop_front(a);
	push_back(b, tmp->val);
	b->top->rank = tmp->rank;
	free(tmp);
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_info	*tmp;

	if (!b->size)
		return ;
	tmp = pop_front(b);
	push_back(a, tmp->val);
	a->top->rank = tmp->rank;
	free(tmp);
	write(1, "pa\n", 3);
}
