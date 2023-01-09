/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:13:27 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/09 05:20:59 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*lstnew(t_stack *s, int val)
{
	t_info	*elem;
	
	elem = malloc(sizeof(t_info));
	if (!elem)
		print_error("Memory allocation fail.\n");
	elem->val = val;
	elem->index = s->size;
	elem->rank = 0;
	return (elem);
}
