/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:13:24 by junyojeo          #+#    #+#             */
/*   Updated: 2022/11/23 18:51:45 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*lstnew(void *data)
{
	t_info	*elem;

	elem = malloc(sizeof(elem));
	if (!elem)
		return (0);
	elem->prev = NULL;
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void	push_front(t_stack *s, t_info *new)
{
	new->next = s->head->next;
	s->head->next = new;
	if (s->tail->prev == NULL)
		s->tail->prev = new;
	s->head->next->prev = new;
	s->head->next = new;
	s->size++;
}
//나는 무엇을 하고있는가.
void	push_back(t_stack *s, t_info *new)
{
	new->prev = s->tail->prev;
	s->tail->prev = new;
	if (s->head->next == NULL)
		s->head->next = new;
	s->tail->prev->next = new;
	s->tail->prev = new;
	s->size++;
}
//노드 뽑지 말말고  data좁기
t_info	*pop_front(t_stack *s)
{
	t_info	*front;

	front = s->head->next;
	if (s->head->next == NULL)
		return ;
	front->next = NULL;
	front->prev = NULL:
	s->head->next = s->head->next->next;
	s->head->next->prev = NULL;
	s->size--;
	return (front);
}
//그림그려보자. ㅁ->top,end<-ㅁ. pop ㅁ->null null<-ㅁ
t_info	*pop_back(t_stack *s)
{
	t_info	*back;

	back = s->tail->prev;
	if (s->tail->prev == NULL)
		return ;
	s->tail->prev = s->tail->prev->prev;
	s->tail->prev->next = NULL;
	s->size--;
	return (back);
}
