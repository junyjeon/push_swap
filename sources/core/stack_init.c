/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:59:41 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/09 05:32:10 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
