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

static void	in_b_sort_three(t_stack *s)
{
	if (sort_132)
	{
		sb(s);
		rb(s);
		sb(s);
		rrb(s);
	}
	else if (sort_231)
		sb(s);
	else if (sort_213)
	{
		rb(s);
		sb(s);
		rrb(s);
		sb(s);
	}
	else if (sort_312)
	{
		rb(s);
		sb(s);
		rrb(s);
	}
	else
	{
		sb(s);
		rb(s);
		sb(s);
		rrb(s);
		sb(s);
	}

}

static void	in_a_sort_three(t_stack *s)
{
	
	if (sort_132)
	{
		ra(s);
		sa(s);
		rra(s);
	}
	else if (sort_231)
	{
		ra(s);
		sa(s);
		rra(s);
		sa(s);
	}
	else if (sort_213)
		sa(s);
	else if (sort_312)
	{
		sa(s);
		ra(s);
		sa(s);
		rra(s);
	}
	else
	{
		ra(s);
		sa(s);
		rra(s);
	}
}

void	hard_coding(t_stack *s, int size, char c)
{
	if (1 == size)
		write(1, "Arguments vector is one.\n", 26);
	else if (2 == size)
	{
		if (first > second && c == 'a')
			sa(s);
		else if (first < second && c == 'b')
			sb(s);
	}
	else if (3 == size)
	{
		if (c == 'a')
			in_a_sort_three(s);
		else if (c == 'b')
			in_b_sort_three(s);
		else
			print_error("Sort_three error\n");
	}
	else
		return ;
	write(1, "OK\n", 3);
}
