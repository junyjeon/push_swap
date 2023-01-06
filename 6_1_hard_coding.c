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

//static int sort_five(t_stack *a)
//{
//	if (sort_2134)
//		sa(a);
//	else if (sort_3124)
//	{
//		sa(a);
//		ra(a);
//		sa(a);
//		rra(a);
//	}
//	else if (sort_41235)
//	{
//		rra(a);
//		sa(a);
//		ra(a);
//		ra(a);
//	}
//	else if (fifth < first)
//		ra(a);
//	return (1);
//}

//static int sort_four(t_stack *a)
//{
//	if (sort_2134)
//		sa(a);
//	else if (sort_3124)
//	{
//		rra(a);
//		sa(a);
//		ra(a);
//		ra(a);
//	}
//	else if (fifth < first)
//		ra(a);
//}

static void	sort_three(t_stack *a, t_stack *b, char s)
{
	if (sort_132)
	{
		cmd("ra", a, b, s);
		cmd("sa", a, b, s);
		cmd("rra", a, b, s);
	}
	else if (sort_231)
	{
		cmd("ra", a, b, s);
		cmd("sa", a, b, s);
		cmd("rra", a, b, s);
		cmd("sa", a, b, s);
	}
	else if (sort_213)
		cmd("sa", a, b, s);
	else if (sort_312)
	{
		cmd("sa", a, b, s);
		cmd("ra", a, b, s);
		cmd("sa", a, b, s);
		cmd("rra", a, b, s);
	}
	else
	{
		cmd("ra", a, b, s);
		cmd("sa", a, b, s);
		cmd("rra", a, b, s);
	}
}
//cmd(sa);
//cmd(sb);
//cmd(ss);
//cmd(ra);
//cmd(rb);
//cmd(rr);
//cmd(rra);
//cmd(rrb);
//cmd(rrr);
void	hard_coding(t_stack *a, t_stack *b, int size, char s)
{
	if (1 == size)
		write(1, "Arguments vector is one\n", 24);
	else if (2 == size)
	{
		if (first > second)
			cmd("sa", a, b, s);
	}
	else if (3 == size)
		sort_three(a, b, s);
	else
		return ;
	//else if (4 == size)
	//{
	//	pb(a, b);
	//	sort_three(a);
	//	pa(a, b);
	//	sort_four(a);
	//}
	//else if (5 == size)
	//{
	//	pb(a, b);
	//	pb(a, b);
	//	sort_three(a);
	//	pa(a, b);
	//	sort_four(a);
	//	pa(a, b);
	//	sort_five(a);
	//}
	write(1, "OK\n", 3);
	exit(1);
}
