/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parsing_stack_and_array.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:59 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/08 14:36:49 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parsing_stack_and_array(t_stack *a, char **argv, int ac)
{
	char	*str;
	char	**split_str;
	int		*arr;
	int		i;

	str = NULL;
	i = 0;
	while (++i < ac)
		str = ft_strjoin(str, argv[i], i);
	split_str = ft_split(str, ' ');
	i = 0;
	while (split_str[i])
		i++;
	arr = malloc(sizeof(arr) * i);
	if (!arr)
		print_error("Memory allocation fail.\n");
	i = -1;
	while (split_str[++i])
	{
		arr[i] = ft_atoi_ll(split_str[i]);
		push_back(a, arr[i]);
	}
	ft_free(split_str);
	return (arr);
}
