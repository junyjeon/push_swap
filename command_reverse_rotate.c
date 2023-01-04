#include "push_swap.h"

void	revers_rotate(t_stack *s)
{
	if (s->size <= 1)
		return ;
	s->top->next = s->bottom;
	s->bottom->prev = s->top;
	s->top = s->bottom;
	s->bottom = s->bottom->next;
	s->top->next = NULL;
	s->bottom->prev = NULL;
}

void	rrr(t_stack *a, t_stack *b)
{
	revers_rotate(a);
	revers_rotate(b);
	write(1, "rrr\n", 4);
}

void	rrb(t_stack *b)
{
	revers_rotate(b);
	write(1, "rrb\n", 4);
}

void	rra(t_stack *a)
{
	revers_rotate(a);
	write(1, "rra\n", 4);
}
