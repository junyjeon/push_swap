/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:59 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/05 23:00:08 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parsing(t_stack *a, t_stack *b, char **ar, int ac)
{
	char		*str;
	char		**split_str;
	long long	res;
	int			*arr;
	int			i;

	str = NULL;
	i = 0;
	while (++i < ac)
	{
		str = ft_strjoin(str, ar[i], i);
		if (!str)
			print_error("Memory allocation fail.\n");
	}
	split_str = ft_split(str, ' ');
	if (!split_str)
		print_error("Memory allocation fail.\n");
	i = -1;
	while (split_str[++i])
	{
		res = ft_atoi(split_str[i]);
		if (res < -2147483648 || 2147483647 < res)
			print_error("Int range Error\n");
		if (!push_back(a, res))
			print_error("Memory allocation fail.\n");
	}
	return (0);
}
