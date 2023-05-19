/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:52:34 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 21:09:42 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	pb(t_stack *a, t_stack *b, int flag)
{
	t_info	*tmp;

	if (!a->size)
		return ;
	tmp = pop_back(a);
	push_back(b, tmp);
	if (flag)
		write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b, int flag)
{
	t_info	*tmp;

	if (!b->size)
		return ;
	tmp = pop_back(b);
	push_back(a, tmp);
	if (flag)
		write(1, "pa\n", 3);
}
