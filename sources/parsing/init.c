/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:59:41 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 00:29:49 by junyojeo         ###   ########.fr       */
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
	a->bottom = malloc(sizeof(t_info));
	b->bottom = malloc(sizeof(t_info));
	a->top = malloc(sizeof(t_info));
	b->top = malloc(sizeof(t_info));
	if (!a->bottom || !a->top || !b->bottom || !b->top)
		print_error("Memory allocation fail.\n");
	a->size = 0;
	b->size = 0;
}
