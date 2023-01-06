/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parsing_stack_and_array.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:59 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/06 15:41:36 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parsing_stack_and_array(t_stack *a, t_stack *b, char **argv, int ac)
{
	char		*str;
	char		**split_str; 
	long long	*ar;
	int			i;

	str = NULL;
	i = 0;
	while (++i < ac)
	{
		str = ft_strjoin(str, argv[i], i);
		if (!str)
			print_error("Memory allocation fail.\n");
	}
	split_str = ft_split(str, ' ');
	if (!split_str)
		print_error("Memory allocation fail.\n");
	i = 0;
	while (split_str[i])
		i++;
	ar = malloc(sizeof(ar) * i);
	if (!ar)
		print_error("Memory allocation fail.\n");
	i = -1;
	while (split_str[++i])
	{
		ar[i] = ft_atoi(split_str[i]);
		if (ar[i] < -2147483648 || 2147483647 < ar[i])
			print_error("Int range Error\n");
		if (!push_back(a, ar[i]))
			print_error("Memory allocation fail.\n");
	}
	return (ar);
}
