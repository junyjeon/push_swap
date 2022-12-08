/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:59 by junyojeo          #+#    #+#             */
/*   Updated: 2022/12/08 22:44:39 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_init(t_stack *s)
{
	s->bottom = malloc(sizeof(s->bottom));
	s->top = malloc(sizeof(s->top));
	s->bottom->index = -1;
	s->size = 0;
}
int init(t_stack *a, t_stack *b, char **ar, int ac)
{
	char	*str;
	char	**res;
	int		i;

	if (ac <= 1)
		error_print(1);
	stack_init(a);
	stack_init(b);
	str = NULL;
	i = 0;
	while (++i < ac)
		str = ft_strjoin(str, ar[i], i);
	res = ft_split(str, ' ');
	i = 0;
	while (res[i])
	{
		if (!push_back(ft_atoi_ll(res[i++]), a))
			return (-1);
	}
	printf("%zu, %d, %d \n", a->top->index, a->top->val, a->size);
	return (1);
}
