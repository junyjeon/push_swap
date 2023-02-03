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

static void	in_B_sort_three(t_stack *s)
{
	if (sort_132 || sort_312 || sort_123)
	{
		if (sort_123)
		{
			rb(s);
			sb(s);
			rrb(s);
		}
		if (sort_132)
			sb(s);
		rb(s);
		sb(s);
		rrb(s);
	}
	else if (sort_231 || sort_213)
	{
		if (sort_213)
		{
			rb(s);
			sb(s);
			rrb(s);
		}
		sb(s);
	}
}

static void	in_A_sort_three(t_stack *s)
{
	if (sort_132 || sort_312)
	{
		if (sort_312)
			sa(s);
		ra(s);
		sa(s);
		rra(s);
	}
	else if (sort_231 || sort_213 || sort_321)
	{
		if (sort_321)
			sa(s);
		if (sort_231)
		{
			ra(s);
			sa(s);
			rra(s);
		}
		sa(s);
	}
}

static void	in_B(t_stack *s)
{
	if (sort_123)
	{
		sb(s);
		rrb(s);
	}
	else if (sort_132)
		rb(s);
	else if (sort_213)
	{
			rrb(s);
	}
	else if (sort_231)
		sb(s);
	else if (sort_312)
	{
		sb(s);
		rb(s);
	}
}

static void	in_A(t_stack *s)
{
	if (sort_132)
	{
		rra(s);
		sa(s);
	}
	else if (sort_213)
		sa(s);
	else if (sort_231)
		rra(s);
	else if (sort_312)
		ra(s);
	else if (sort_321)
	{
		ra(s);
		sa(s);
	}
}

void	hard_coding(t_stack *s, t_stack *s2, int size, char c)
{
	int	tmp;
	int cnt;
	int	pa_cnt;

	if (size == 1)
		return;
	else if (size == 2)
	{
		if (c == 'a' && first > second)
			sa(s);
		else if (c == 'b' && first < second)
			sb(s);
	}
	else if (size == 3)
	{
		if (s->size <= 3)
		{
			if (c == 'a')
				in_A(s);
			else if (c == 'b')
				in_B(s);
		}
		else
		{
			if (c == 'a')
				in_A_sort_three(s);
			else if (c == 'b')
				in_B_sort_three(s);
		}
	}
	else if (size == 4)
	{
		cnt = 0;
		if (c == 'a')
		{
			pb(s, s2);
			tmp = s2->top->val;
			hard_coding(s, s2, 3, 'a');
			if (tmp < first)
				pa(s, s2);
			else if (first < tmp && tmp < second)
			{
				pa(s, s2);
				sa(s);
			}
			else if (second < tmp && tmp < third)
			{
				ra(s);
				ra(s);
				pa(s, s2);
				rra(s);
				rra(s);
			}
			else
			{
				pa(s, s2);
				ra(s);
			}
		}
		else if (c == 'a')
		{
			pa(s2, s);
			tmp = s2->top->val;
			hard_coding(s2, s, 3, 'a');
			if (tmp > first)
				pb(s, s2);
			else if (first > tmp && tmp > second)
			{
				pb(s, s2);
				sb(s);
			}
			else if (second > tmp && tmp > third)
			{
				rb(s);
				rb(s);
				pb(s, s2);
				rrb(s);
				rrb(s);
			}
			else
			{
				pa(s, s2);
				ra(s);
			}
		}
		//else if (c == 'b')
		//{
		//	pa(s2, s);
		//	hard_coding(s2, s, 3, 'b');
		//	tmp = s2->top->rank;
		//	if (tmp > first)
		//		pb(s, s2);
		//	else if (first > tmp && tmp > second)
		//	{
		//		pb(s, s2);
		//		sb(s);
		//	}
		//	else if (second > tmp && tmp > third)
		//	{
		//		rb(s);
		//		rb(s);
		//		pb(s, s2);
		//		rrb(s);
		//		rrb(s);
		//	}
		//	else
		//	{
		//		pb(s, s2);
		//		rb(s);
		//	}
		//}
	}
	else if (size == 5)
	{
		pa_cnt = 0;
		cnt = 0;
		if (c == 'a')
		{
			pb(s, s2);
			pb(s, s2);
			hard_coding(s, s2, 3, 'a');
			
		}
		else if (c == 'b')
		{
			pa(s2, s);
			pa(s2, s);
			hard_coding(s2, s, 3, 'b');
			
		}
	}
}
