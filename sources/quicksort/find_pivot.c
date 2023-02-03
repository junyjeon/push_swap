/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:55:07 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 00:29:49 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_swap(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void	find_pivot(t_stack *s, int size, t_pivot *pivot)
{
	t_info	*cur;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * size);
	cur = s->top;
	i = -1;
	while (++i < size)
	{
		arr[i] = cur->rank;
		cur = cur->prev;
	}
	ft_swap(arr, size);
	pivot->min = arr[size / 3];
	pivot->max = arr[size / 3 * 2];
	free(arr);
}
