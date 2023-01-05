/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:59:16 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/05 23:02:50 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_array(t_stack *a, char **split_str)
{
	int *arr;
	int i;
	
	arr = (int *)malloc(sizeof(arr) * a->size);
	i = -1;
	while (split_str[++i])
	{
		arr[i] = ft_atoi_ll(split_str[i]);
		if (!arr[i])
			return (0);
	}
	return (arr);
}
