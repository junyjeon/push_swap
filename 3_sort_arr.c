/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:37:25 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/07 22:20:33 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge(int *ar, int *tmp, int start, int end)
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
		if (ar[i] <= ar[j])
			tmp[k++] = ar[i++];
		else
			tmp[k++] = ar[j++];
	}
	while (i <= mid)//start->mid mid->end 남은 건 그대로 대입//
		tmp[k++] = ar[i++];
	while (j <= end)
		tmp[k++] = ar[j++];
	i = -1;
	while (++i <= end)//합친 것 ar에 대입
		ar[i] = tmp[i];
}

static void	merge_sort(int *ar, int *tmp, int start, int end)
{
	int	mid;

	if (start < end)
    {
        mid = (start + end) / 2; //2로 나누었을 때  0 이이면 start < end (x)
        merge_sort(ar, tmp, start, mid);
        merge_sort(ar, tmp, mid + 1, end);
        merge(ar, tmp, start, end);
    }
}

void	sort_arr(t_stack *a, int *ar)
{
	int	tmp[a->size];

	merge_sort(ar, tmp, 0, a->size - 1);
}
