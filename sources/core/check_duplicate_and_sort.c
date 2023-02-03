/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate_and_sort.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:37:25 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/03 22:49:09 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate_and_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	swap_cnt;
	int	tmp;

	if (1 == size)
		print_error("Arguments vector is one.\n");
	swap_cnt = 0;
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
	i = -1;
	while (++i < size - 1)
		if (arr[i] == arr[i + 1])
			print_error("Duplicate!\n");
	if (swap_cnt == 0)
		print_error("It's aligned.\n");
}
