/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:59 by junyojeo          #+#    #+#             */
/*   Updated: 2022/12/05 17:12:14 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_stack(int val, t_stack *a)
{
	t_info *new;
	t_info *cur;

	new = (t_info *)malloc(sizeof(t_info));
	if (!new)
		return (0);
	new->val = val;
	if (!a->bottom)
	{
		a->bottom = malloc(sizeof(a->bottom));
		a->top = malloc(sizeof(a->top));
		new->prev = new;
		a->bottom->dir = new;
		a->top->dir = new;
		new->index = 1;
	}
	else
	{
		a->top->dir->next = new;
		new->prev = a->top->dir;
		a->top->dir = new;
		new->index = new->prev->index + 1;
	}
	new->next = NULL;
	return (1);
}

static void	stack_init(t_stack *s)
{
	s->bottom = NULL;
	s->top = NULL;
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
		add_stack(ft_atoi_ll(res[i++]), a);
	return (1);
}