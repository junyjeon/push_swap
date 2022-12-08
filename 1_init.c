/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:59 by junyojeo          #+#    #+#             */
/*   Updated: 2022/12/08 22:03:29 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_add(int val, t_stack *a)
{
	t_info *new;

	new = lstnew(val);
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
	new->index = a->size;
	a->size++;
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
		stack_add(ft_atoi_ll(res[i++]), a);
	printf("%zu, %d, %d \n", a->top->dir->index, a->top->dir->val, a->size);
	return (1);
}
