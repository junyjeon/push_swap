/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranked_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:14:19 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 21:09:42 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	ranked(t_stack *a, int *arr, int size)
{
	t_info	*cur;
	int		i;
	int		j;

	cur = a->top;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (cur->val == arr[j])
				cur->rank = j;
		cur = cur->prev;
	}
	free(arr);
}
