#include "push_swap.h"

int	push_front(t_stack *s, int val)
{
	t_info *new;
	t_info *cur;

	new = lstnew(val);
	if (!new)
		return (0);
	ft_lstadd_front(&s->bottom, new);
	if (!s->size)
	{
		new->next = NULL;
		s->bottom = new;
		s->top = new;
	}
	else
	{
		new->prev = s->bottom;
		s->bottom = new;
	}
	new->prev = NULL;
	new->index = s->size;
	s->size++;
	return (1);
	cur = s->bottom;
	while (cur)
	{
		printf("%zu\n", cur->index);
		cur = cur->next;
		cur->index++;
	}
}


int	push_back(t_stack *s, int val)
{
	t_info *new;

	new = lstnew(val);
	if (!new)
		return (0);
	ft_lstadd_back(&s->bottom, new);
	if (!s->size)
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
	new->index = s->size;
	s->size++;
	return (1);
}

int	pop_front(t_stack *s)
{
	int		front_val;
	t_info	*tmp;

	if (!s->size)
		return (0);
	front_val = s->bottom->val;
	tmp = s->bottom;
	s->bottom = s->bottom->next;
	s->bottom->prev = NULL;
	s->size--;
	free(tmp);
	return (front_val);
}

int	pop_back(t_stack *s)
{
	int		back_val;
	t_info	*tmp;

	back_val = s->top->val;
	if (!s->size)
		return (0);
	tmp = s->top;
	s->top = s->top->prev;
	s->top->next = NULL;
	s->size--;
	free(tmp);
	return (back_val);
}
