/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_swap_ss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:51:26 by junyojeo          #+#    #+#             */
/*   Updated: 2022/12/07 21:53:59 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b->size <= 1)
		return ;
	tmp = b->bottom->dir->val;
	b->bottom->dir->val = b->bottom->dir->next->val;
	b->bottom->dir->next->val = tmp;
	write(1, "sb\n", 3);
}

void	sa(t_stack *a)
{
	int	tmp;

	if (a->size <= 1)
		return ;
	tmp = a->bottom->dir->val;
	a->bottom->dir->val = a->bottom->dir->next->val;
	a->bottom->dir->next->val = tmp;
	write(1, "sa\n", 3);
}
