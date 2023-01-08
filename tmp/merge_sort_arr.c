/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:58:42 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/08 14:59:02 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge(int *arr, int *tmp, int start, int end)
{
	int	mid;
	int	i;
	int	j;
	int	k;
	
	mid = (start + end) / 2;
	i = start;
	j = mid + 1;
	k = start;
	while (i <= mid && j <= end)//start->mid mid->end까지 교환, 
	{
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	while (i <= mid)//start->mid mid->end 남은 건 그대로 대입//
		tmp[k++] = arr[i++];
	while (j <= end)
		tmp[k++] = arr[j++];
	i = -1;
	while (++i <= end)//합친 것 ar에 대입
		arr[i] = tmp[i];
}

static void	merge_sort(int *arr, int *tmp, int start, int end)
{
	int	mid;

	if (start < end)
    {
        mid = (start + end) / 2; //2로 나누었을 때  0 이이면 start < end (x)
        merge_sort(arr, tmp, start, mid);
        merge_sort(arr, tmp, mid + 1, end);
        merge(arr, tmp, start, end);
    }
}

void	sort_arr(t_stack *a, int *arr)
{
	int	tmp[a->size];

	merge_sort(arr, tmp, 0, a->size - 1);
}
