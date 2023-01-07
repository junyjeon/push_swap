/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_stack_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:59:41 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/07 19:56:59 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_init(t_stack *a, t_stack *b)
{
	a->bottom = malloc(sizeof(a->bottom));
	if (!a->bottom)
		return (0);
	a->top = malloc(sizeof(a->top));
	if (!a->top)
		return (0);
	a->size = 0;
	b->bottom = malloc(sizeof(b->bottom));
	if (!b->bottom)
		return (0);
	b->top = malloc(sizeof(b->top));
	if (!b->top)
		return (0);
	b->size = 0;
	return (1);
}
