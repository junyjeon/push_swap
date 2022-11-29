/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_merge_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:04:43 by junyojeo          #+#    #+#             */
/*   Updated: 2022/11/30 02:51:59 by junyojeo         ###   ########.fr       */
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

void	merge_sort(t_stack *a, t_stack *b)
{
	int arr[2];
	int i;
	int j;

	// if (n < 3)
	// {
	// 	if (direct)
	// 		arr[i] = 1;
	// 	else
	// 		arr[i] = -1;
	// }
	// else
	// {
	// 	if (direct)
	// 	{

	// 	}
	// 	else
	// 		배열 [][][]  a->size / 3, + a->size % 3
	// }
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
		merge_sort(a, b, arr, div);
		int i = 0;
		while (arr[i])
		{
			div = arr[i];
			while (--div)
			{

				div--;
			}
			i++;
		}
	}
}
