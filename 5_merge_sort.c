/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_merge_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:37:25 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/05 19:34:14 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge(int *arr, int *sorted, int start, int end)
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
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}
	while (i <= mid)
		sorted[k++] = arr[i++];
	while (j <= end)
		sorted[k++] = arr[j++];
	i = -1;
	while (++i <= end)
		arr[i] = sorted[i];
}

void	merge_sort(int *arr, int *sorted, int start, int end)
{
	int	mid;

	if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort(arr, sorted, start, mid);
        merge_sort(arr, sorted, mid + 1, end);
        merge(arr, sorted, start, end);
    }
}

int	*sorted(t_stack *a, int *arr)
{
	int	*sort;

	sort = (int *)malloc(sizeof(sort) * a->size);
	merge_sort(arr, sort, 0, a->size - 1);
	int *ranked;

	t_info *cur;
	cur = a->bottom;
	for (int i =0; i < a->size; ++i)
	{
		while (cur)
		{
			if (sort[i] == cur->val)
			cur = cur->next; 
		}
	}
	return (sort);
}
