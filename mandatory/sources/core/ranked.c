/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:14:19 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/09 10:17:32 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ranked(t_stack *a, int *arr)
{
	int		i;
	t_info	*cur;

	cur = a->top;
	while (cur)
	{
		i = -1;
		while (++i < a->size - 1)
			if (cur->val == arr[i])
				cur->rank = i;
		cur = cur->prev;
	}
	free(arr);
}
