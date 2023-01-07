/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:37:25 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/07 20:47:36 by junyojeo         ###   ########.fr       */
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
	while (i <= mid && j <= end)//start->mid mid->end까지 교환, 
	{
		if (ar[i] <= ar[j])
			sorted[k++] = ar[i++];
		else
			sorted[k++] = ar[j++];
	}
	while (i <= mid)//start->mid mid->end 남은 건 그대로 대입//
		sorted[k++] = ar[i++];
	while (j <= end)
		sorted[k++] = ar[j++];
	i = -1;
	while (++i <= end)//합친 것 ar에 대입
		ar[i] = sorted[i];
}

static void	merge_sort(int *ar, int *sorted, int start, int end)
{
	int	mid;

	if (start < end)
    {
        mid = (start + end) / 2; //2로 나누었을 때  0 이이면 start < end (x)
        merge_sort(ar, sorted, start, mid);
        merge_sort(ar, sorted, mid + 1, end);
        merge(ar, sorted, start, end);
    }
}

int	*sort_arr(t_stack *a, int *ar)
{
	int	i;

	merge_sort(ar 0, a->size - 1);
	i = -1;
	while (++i < a->size - 1)
	{
		if (ar[i] == ar[i + 1])
			print_error("Overlap error\n");
	}
	return (ar);
}
