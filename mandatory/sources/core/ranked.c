/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:14:19 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/13 21:58:03 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ranked(t_stack *a, int *arr)
{
	t_info	*cur;
	int		i;

	cur = a->top;
	while (cur)
	{
		i = -1;
		while (++i < a->size)
			if (cur->val == arr[i])
				cur->rank = i;
		cur = cur->prev;
	}
	free(arr);
}
