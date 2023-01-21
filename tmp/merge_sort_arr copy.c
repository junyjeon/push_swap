/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_arr copy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:58:42 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/19 01:11:57 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge(int *arr, int *tmp, int start, int end)
{
	int	mid;
	int	mid2;
	int	i;
	int	j;
	int	k;
	int	l;
	
	mid = (start + end) / 3;
	mid2 = (start + end) / 3 * 2;
	i = start;
	j = mid + 1;
	k = mid2 + 1;
	l = start;
	while (i <= mid && j <= mid2 && k <= end)//start->mid mid->end까지 교환, 
	{
		if (arr[i] <= arr[j] && arr[j] <= arr[k] && arr[i] <= arr[k])
			tmp[l++] = arr[i++];
		else
			tmp[l++] = arr[j++];
	}
	while (i <= mid)//start->mid mid->end 남은 건 그대로 대입//
		tmp[l++] = arr[i++];
	while (j <= end)
		tmp[l++] = arr[j++];
	i = -1;
	while (++i <= end)//합친 것 ar에 대입
		arr[i] = tmp[i];
}

static void	merge_sort(int *arr, int *tmp, int start, int end)
{
	int	mid;
	int	mid2;

	if (start < end)
    {
        mid = (start + end) / 3; //2로 나누었을 때  0 이이면 start < end (x)
        merge_sort(arr, tmp, start, mid);
        mid2 = (start + end) / 3 * 2;
        merge_sort(arr, tmp, mid + 1, end);
        merge(arr, tmp, start, end);
    }
}

void	sort_arr(t_stack *a, int *arr)
{
	int	tmp[a->size];

	merge_sort(arr, tmp, 0, a->size - 1);
}
