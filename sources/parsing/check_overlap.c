/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate_and_sort.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:37:25 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 02:07:32 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	arr_sort(int *arr, int size, int swap_cnt)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				swap_cnt++;
			}
		}
	}
	if (swap_cnt == 0)
		print_error("It's aligned.\n");
}

void	check_overlap(int *arr, int size)
{
	int	i;

	if (1 == size)
		print_error("Arguments vector is one.\n");
	arr_sort(arr, size, 0);
	i = -1;
	while (++i < size - 1)
		if (arr[i] == arr[i + 1])
			print_error("Duplicate!\n");
}
