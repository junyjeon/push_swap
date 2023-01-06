/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_check_overlap_and_sorted.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:56:47 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/06 17:11:08 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_overlap_and_sorted(int *arr, int size)
{
	int i;
	int j;
	int tmp;
	int swap_cnt;

	swap_cnt = 0;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				swap_cnt++;
			}
		}
		if (arr[i] == arr[i + 1])
			print_error("Argument is duplicated.\n");
	}
	if (swap_cnt == 0)
		print_error("It's already sorted.\n");
}
