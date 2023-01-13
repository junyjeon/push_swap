/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:19:43 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/13 23:58:16 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack *s, int val)
{
	t_info *new;

	new = ft_lstnew(val);
	if (s->size == 0)
	{
		s->top = new;
		s->bottom = new;
	}
	else
	{
		s->bottom->prev = new;
		new->next = s->bottom;
	}
	s->bottom = new;
	s->size++;
}

void	push_back(t_stack *s, int val)
{
	t_info	*new;
	
	new = ft_lstnew(val);
	if (s->size == 0)
	{
		s->top = new;
		s->bottom = new;
	}
	else
	{
		s->top->next = new;
		new->prev = s->top;
	}
	s->top = new;
	s->size++;
}

t_info	*pop_front(t_stack *s)
{
	t_info	*tmp;

	if (!s->size)
		return (0);
	tmp = s->bottom;
	s->bottom = s->bottom->next;
	s->bottom->prev = NULL;
	tmp->next = NULL;
	s->size--;
	return (tmp);
}

t_info	*pop_back(t_stack *s)
{
	t_info	*tmp;

	if (!s->size)
		return (0);
	tmp = s->top;
	s->top = s->top->prev;
	s->top->next = NULL;
	tmp->prev = NULL;
	s->size--;
	return (tmp);
}
