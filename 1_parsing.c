/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:59 by junyojeo          #+#    #+#             */
/*   Updated: 2022/11/24 03:53:49 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	append(int val, t_stack *a)
{
	t_info *new;
	t_info *cur;

	new = (t_info *)malloc(sizeof(t_info));
	if (!new)
		return (0);
	new->val = val;
	new->index = a->size;
	if (!a->bottom)
	{
		a->bottom = malloc(sizeof(a->bottom));
		a->top = malloc(sizeof(a->top));
		new->prev = new;
		a->bottom->dir = new;
		a->top->dir = new;
	}
	else
	{
		a->top->dir->next = new;
		new->prev = a->top->dir;
		a->top->dir = new;
	}
	new->next = NULL;
	a->size++;
	return (1);
}

static void	stack_init(t_stack *a, t_stack *b)
{
	a->bottom = NULL;
	a->top = NULL;
	a->size = 0;
	b->bottom = NULL;
	b->top = NULL;
	b->size = 0;
}

int init(t_stack *a, t_stack *b, char **ar, int ac)
{
	char	*str;
	char	**res;
	int		i;

	if (ac <= 1)
		error_print(1);
	stack_init(a, b);
	str = NULL;
	i = 0;
	while (++i < ac)
		str = ft_strjoin(str, ar[i], i);
	res = ft_split(str, ' ');
	i = 0;
	while (res[i])
		append(ft_atoi_ll(res[i++]), a);
	return (1);
}
