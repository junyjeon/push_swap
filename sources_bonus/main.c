/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:41:34 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/20 07:07:50 by junyojeo         ###   ########.fr       */
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
	if (!ft_strncmp(cmd, "sa", 2))
		sa(a, 0);
	else if (!ft_strncmp(cmd, "sb", 2))
		sb(b, 0);
	else if (!ft_strncmp(cmd, "ss", 2))
		ss(a, b, 0);
	else if (!ft_strncmp(cmd, "ra", 2))
		ra(a, 0);
	else if (!ft_strncmp(cmd, "rb", 2))
		rb(b, 0);
	else if (!ft_strncmp(cmd, "rr", 2))
		rr(a, b, 0);
	else if (!ft_strncmp(cmd, "rra", 3))
		rra(a, 0);
	else if (!ft_strncmp(cmd, "rrb", 3))
		rrb(b, 0);
	else if (!ft_strncmp(cmd, "rrr", 3))
		rrr(a, b, 0);
	else if (!ft_strncmp(cmd, "pa", 2))
		pa(a, b, 0);
	else if (!ft_strncmp(cmd, "pb", 2))
		pb(a, b, 0);
	else
		print_error("Error: command invalid\n", 1);
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
		print_error("OK\n", 1);
	else
		print_error("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		print_error("Argment count is zero.\n", 1);
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
