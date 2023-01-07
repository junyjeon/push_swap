/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_little_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:11:40 by junyojeo          #+#    #+#             */
/*   Updated: 2022/11/29 11:11:40 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *a, t_stack *b, char c)
{
	if (sort_132)
	{
		cmd(a, b, "r", c);
		cmd(a, b, "s", c);
		cmd(a, b, "rr", c);
	}
	else if (sort_231)
	{
		cmd(a, b, "r", c);
		cmd(a, b, "s", c);
		cmd(a, b, "rr", c);
		cmd(a, b, "s", c);
	}
	else if (sort_213)
		cmd(a, b, "s", c);
	else if (sort_312)
	{
		cmd(a, b, "s", c);
		cmd(a, b, "r", c);
		cmd(a, b, "s", c);
		cmd(a, b, "rr", c);
	}
	else if (sort_321)
	{
		cmd(a, b, "r", c);
		cmd(a, b, "s", c);
		cmd(a, b, "rr", c);
	}
	else
		print_error("sort_three error\n");
}
void	hard_coding(t_stack *a, t_stack *b, int size, char c)
{
	if (1 == size)
		write(1, "Arguments vector is one\n", 24);
	else if (2 == size)
	{
		if (first > second)
			cmd(a, b, "s", c);
	}
	else if (3 == size)
		sort_three(a, b, c);
	else
	{
		print_error("Hard coding error\n");
		return ;
	}
	write(1, "OK\n", 3);
	exit(1);
}
