/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ranked.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:14:19 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/06 15:40:06 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ranked(t_stack *a, int *arr)
{
	int		i;
	int		rank[a->size];
	t_info	*cur;

	cur = a;
	while (cur)
	{
		i = -1;
		while (++i < a->size)
			if (cur->val == arr[i])
				rank[i] = cur->index;
		cur = cur->next;
	}
	free(arr);
	return (rank);
}
