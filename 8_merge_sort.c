/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_merge_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:04:43 by junyojeo          #+#    #+#             */
/*   Updated: 2022/11/29 11:49:17 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_max(t_stack *a, t_stack *b)
{
	if (sort_231)
		rra(a);
	else if (sort_213 || sort_312)
		sa(a);
	pb(a, b);
}

static void	_max(t_stack *a, t_stack *b)
{
	if (sort_132 || sort_231) // 132
		sa(a);
	else if (sort_213) // 213
		rra(a);
	pb(a, b);
}

static void	_sort(t_stack *a, t_stack *b, int *arr, int size)
{
	int i;
	int j;

	i = 0 - 1;
	while (arr[++i])
	{
		j = arr[i];
		if (arr[0])
		{
			while (--j)
				max(a, b);
		}
		else
			while (--j)
				min(a, b);
		merge_sort(a, b);
	}
}

void	merge_sort(t_stack *a, t_stack *b)
{
	int arr[2];
	int i;
	int j;

	i = 0 - 1;
	while (arr[++i])
		arr[i] = a->size / 3;
	if (a->size % 3 > 0)
		arr[1] += a->size % 3;
	sort(a, b, arr, a->size);
	/* |\ max부터
	if (sort_132 || sort_231) // 132
		sa(a);
	else if (sort_213) // 213
		rra(a);
	pb(a, b);
	*/
	/*|/ min부터
	if (sort_231)
		rra(a);
	else if (sort_213 || sort_312)
		sa(a);
	pb(a, b);
	*/
}

void	merge_sort(t_stack *a, t_stack *b, int *arr, int div)
{
	if (div < 6)
		return ;
	else
	{
		int i = 0;
		while (arr[i])
		{
			div = arr[i];
			while (--div)
			{

				div--;
			}
			merge_sort(a, b);
			i++;
		}
	}
}