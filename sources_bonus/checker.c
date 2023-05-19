/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:41:34 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/20 02:32:05 by junyojeo         ###   ########.fr       */
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
		if (cur->rank > cur->prev->rank)
			print_error("KO\n", 1);
		cur = cur->prev;
	}
	return (1);
}

void	command(t_stack *a, t_stack *b, char *cmd)
{
	if (ft_strcmp(cmd, "sa"))
		return ;
}

void	checker(t_stack *a, t_stack *b)
{
	char *cmd;

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
	int		*arr;

	if (argc < 2)
		print_error("Argment count is zero.\n", 1);
	stack_init(&a, &b);
	arr = parse(&a, argc, argv);
	ranked(&a, arr, a.size);
	checker(&a, &b);
	return (0);
}
// is_sorted? and stack_b == null?