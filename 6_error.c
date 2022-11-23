/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:56:47 by junyojeo          #+#    #+#             */
/*   Updated: 2022/11/24 02:50:57 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_check(char *ar, int size)//정렬하면서 
{
	int i;
	int j;
	int tmp;
	int	chker;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1)
		{
			if (ar[j] > ar[j + 1])
			{
				tmp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = tmp;
				chker++;
			}
		}
		if (ar[i] == ar[i + 1])//정렬 후 숫자가 중복되어도 error
			error_print(1);
	}
	if (chker == 0)//끝에 chker가 0이면 정렬 되어있음
		error_print(-1);
	return (0);
}
