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
	{
		cmd(a, b, "s", c);
	}
	else if (sort_312)
	{
		cmd(a, b, "s", c);
		cmd(a, b, "r", c);
		cmd(a, b, "s", c);
		cmd(a, b, "rr", c);
	}
	else
	{
		cmd(a, b, "r", c);
		cmd(a, b, "s", c);
		cmd(a, b, "rr", c);
	}
}

void	hard_coding(t_stack *a, t_stack *b, int size, char c)
{
	if (1 == size)
		print_error("Arguments vector is one.\n");
	else if (2 == size)
	{
		if (first > second)
			cmd(a, b, "s", c);
	}
	else if (3 == size)
		sort_three(a, b, c);
	write(1, "OK\n", 3);
}
