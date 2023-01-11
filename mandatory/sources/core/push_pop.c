/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:19:43 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/09 11:02:14 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack *s, int val)
{
	t_info *new;
	t_info *cur;

	new = ft_lstnew(val);
	ft_lstadd_front(&s->bottom, new);
	new->index = 0;
	if (s->size == 0)
	{
		new->next = NULL;
		s->bottom = new;
		s->top = new;
	}
	else
	{
		new->next = s->bottom;
		s->bottom = new;
		cur = s->bottom->next;
		printf("OK %p | %p\n", cur, cur->next);
		while (cur)
		{
			cur->index++;
			cur = cur->next;
		}
	}
	new->prev = NULL;
	s->size++;
}

void	push_back(t_stack *s, int val)
{
	t_info	*new;
	
	new = ft_lstnew(val);
	ft_lstadd_back(&s->bottom, new);
	new->index = s->size;
	if (s->size == 0)
	{
		new->prev = NULL;
		s->bottom = new;
		s->top = new;
	}
	else
	{
		new->prev = s->top;
		s->top = new;
	}
	new->next = NULL;
	s->size++;
}

int	pop_front(t_stack *s)
{
	int		val;
	t_info	*tmp;

	if (!s->size)
		return (0);
	val = s->bottom->val;
	tmp = s->bottom;
	s->bottom = s->bottom->next;
	s->bottom->prev = NULL;
	s->size--;
	free(tmp);
	return (val);
}

int	pop_back(t_stack *s)
{
	int		val;
	t_info	*tmp;

	if (!s->size)
		return (0);
	val = s->top->val;
	tmp = s->top;
	s->top = s->top->prev;
	s->top->next = NULL;
	s->size--;
	free(tmp);
	return (val);
}
