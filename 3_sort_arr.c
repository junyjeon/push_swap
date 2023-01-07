/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:37:25 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/07 18:30:38 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge(int *ar, int *sorted, int start, int end)
{
	int	mid;
	int	i;
	int	j;
	int	k;
	
	mid = (start + end) / 2;
	i = start;
	j = mid + 1;
	k = start;
	while (i <= mid && j <= end)
	{
		if (ar[i] <= ar[j])
			sorted[k++] = ar[i++];
		else
			sorted[k++] = ar[j++];
	}
	while (i <= mid)
		sorted[k++] = ar[i++];
	while (j <= end)
		sorted[k++] = ar[j++];
	i = -1;
	while (++i <= end)
		ar[i] = sorted[i];
}

static void	merge_sort(int *ar, int *sorted, int start, int end)
{
	int	mid;

	if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort(ar, sorted, start, mid);
        merge_sort(ar, sorted, mid + 1, end);
        merge(ar, sorted, start, end);
    }
}

int	*sort_arr(t_stack *a, int *ar)
{
	int	*sort;

	sort = (int *)malloc(sizeof(sort) * a->size);
	merge_sort(ar, sort, 0, a->size - 1);
	return (sort);
}
