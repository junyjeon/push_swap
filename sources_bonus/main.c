/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:41:34 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/20 08:18:04 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static int	is_sorted(t_stack *s, int size)
{
	t_info	*cur;
	int		i;

	i = 0;
	cur = s->top;
	while (++i < size && cur)
	{
		if (cur->val > cur->prev->val)
			return (0);
		cur = cur->prev;
	}
	return (1);
}

void	command(t_stack *a, t_stack *b, char *cmd)
{
	if (!ft_strcmp(cmd, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(cmd, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(cmd, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(cmd, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rrr(a, b, 0);
	else if (!ft_strcmp(cmd, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(cmd, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(cmd, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(cmd, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(cmd, "pb\n"))
		pb(a, b, 0);
	else
		print_error("Error\n", 1);
	return ;
}

static void	checker(t_stack *a, t_stack *b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		command(a, b, cmd);
		free(cmd);
		cmd = get_next_line(0);
	}
	if (cmd != NULL)
		free(cmd);
	if (!b->top && is_sorted(a, a->size))
		write(1, "OK\n", 3);
	else
		print_error("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		print_error("Error\n", 1);
	stack_init(&a, &b);
	parse(&a, argc, argv);
	checker(&a, &b);
	while (a.size--)
	{
		free(a.top);
		a.top = a.top->prev;
	}
	exit(0);
}
