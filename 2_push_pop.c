#include "push_swap.h"

t_info	*lstnew(int val)
{
	t_info	*elem;

	elem = malloc(sizeof(elem));
	if (!elem)
		return (0);
	elem->prev = NULL;
	elem->val = val;
	elem->next = NULL;
	return (elem);
}

void	push_front(t_stack *s, int val)
{
	t_info *new;

	new = lstnew(val);
	if (!s->size)
	{
		s->bottom->dir = new;
		s->top->dir = new;
		new->next = NULL;
	}
	else 
	{
		s->bottom->dir->prev = new;
		new->next = s->bottom->dir;
		s->bottom->dir = new;
	}
	s->size++;
}

void	push_back(t_stack *s, int val)
{
	t_info *new;

	new = lstnew(val);
	s->top->dir->next = new;
	new->prev = s->top->dir;
	s->top->dir = new;
	s->size++;
}

int	pop_front(t_stack *s)
{
	int		front_val;
	t_info	*tmp;

	front_val = s->bottom->dir->val;
	if (!s->size)
		return (0);
	tmp = s->bottom->dir;
	s->bottom->dir = s->bottom->dir->next;
	s->bottom->dir->prev = NULL;
	s->size--;
	free(tmp);
	return (front_val);
}

int	pop_back(t_stack *s)
{
	int		back_val;
	t_info	*tmp;

	back_val = s->top->dir->val;
	if (!s->size)
		return (0);
	tmp = s->top->dir;
	s->top->dir = s->top->dir->prev;
	s->top->dir->next = NULL;
	s->size--;
	free(tmp);
	return (back_val);
}
