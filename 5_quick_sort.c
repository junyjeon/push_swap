/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_quick_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:24:40 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/05 22:15:08 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack *a, t_stack *b, int *arr, int size)
{
	int	i;
	int	j;
	int	pivot_min;
	int	pivot_max;

	pivot_min = size / 3;
	pivot_max = size / 3 * 2;
	if (size < 6)
	{
		if (is_sorted())
			hard_coding(a, b, 0);
		return ;
	}
	i = -1;
	while (++i < size)
		if (arr[i] < pivot_max)
			pb(a, b);
	i = -1;
	while (++i < pivot_max)
		if (arr[i] < pivot_min)
			rb(b);
	a_to_b(a, b, arr, pivot_min);
	b_to_a(a, b, arr, pivot_min);
	b_to_a(a, b, arr, pivot_min);
}

a에서 pivot_max 보다 작은 것만 pb, size <= 5이면 hard_codin()만
b에서 pivot_max 개수만큼 ra
b에서 (new)pivot_min보다 큰 것만 pa

b_to_a()


void	b_to_a(t_stack *a, t_stack *b, int *arr, int size)
{
	int	pivot_min;
	int	pivot_max;
	
	
	b_to_a(a, b, arr, size);
	
}

int	quick_sort(t_stack *a, t_stack *b, int *arr, int size)
{
	
	a_to_b(a, b, arr, size);
	
}


