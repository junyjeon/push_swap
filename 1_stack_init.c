/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:59:41 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/05 22:59:47 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_init(t_stack *a, t_stack *b)
{
	a->bottom = malloc(sizeof(a->bottom));
	a->top = malloc(sizeof(a->top));
	a->size = 0;
	b->bottom = malloc(sizeof(b->bottom));
	b->top = malloc(sizeof(b->top));
	b->size = 0;
	if (!a->bottom || !a->top || !b->bottom || !b->top)
		return (0);
	return (1);
}
