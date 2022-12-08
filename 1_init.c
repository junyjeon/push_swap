/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:59 by junyojeo          #+#    #+#             */
/*   Updated: 2022/12/08 22:28:53 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_add(int val, t_stack *s)
{
	t_info *new;

	new = lstnew(val);
	ft_lstadd_front(&s->bottom, new);
	if (!s->bottom->val)
	{
		new->prev = new;
		s->bottom = new;
		s->top = new;
	}
	else
	{
		s->top->next = new;
		new->prev = s->top;
		s->top = new;
	}
	new->next = NULL;
	new->index = s->size;
	s->size++;
	return (1);
}

static void	stack_init(t_stack *s)
{
	s->bottom = malloc(sizeof(s->bottom));
	s->top = malloc(sizeof(s->top));
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
		push_front(ft_atoi_ll(res[i++]), a);
		//stack_add(ft_atoi_ll(res[i++]), a);
	printf("%zu, %d, %d \n", a->top->index, a->top->val, a->size);
	return (1);
}
