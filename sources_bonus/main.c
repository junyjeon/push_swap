/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:41:34 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/20 05:08:38 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

// 에러처리

// 파싱
// 초기화

// gnl 

// a 6 1 4 3 2 
// command();

// is_sorted()
// 	OK

// 	KO

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
	if (ft_strcmp(cmd, "sa"))
		sa(a, 1);
	else if (ft_strcmp(cmd, "sb"))
		sb(b, 1);
	else if (ft_strcmp(cmd, "ss"))
		ss(a, b, 1);
	else if (ft_strcmp(cmd, "ra"))
		ra(a, 1);
	else if (ft_strcmp(cmd, "rb"))
		ra(b, 1);
	else if (ft_strcmp(cmd, "rr"))
		rr(a, b, 1);
	else if (ft_strcmp(cmd, "rra"))
		rra(a, 1);
	else if (ft_strcmp(cmd, "rrb"))
		rrb(b, 1);
	else if (ft_strcmp(cmd, "rrr"))
		rrr(a, b, 1);
	else if (ft_strcmp(cmd, "pa"))
		pa(a, b, 1);
	else if (ft_strcmp(cmd, "pb"))
		pb(a, b, 1);
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
		cmd = get_next_line(0);
	}
	if (!b->top && is_sorted(a, a->size))
		print_error("OK\n", 0);
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
	printf("aa\n");
	exit(0);
}
// is_sorted? and stack_b == null?