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

void	little_sort(t_stack *a, t_stack *b)
{
	int i;
	
	if (1 == first)
	{
		write(1, "Arguments vector is one\n", 24);
	}
	else if (2 == first)
	{
		if (first > second)
			sa(a);
	}
	else if (3 == first)
	{
		if (sort_132)
		{
			sa(a);
			ra(a);
		}
		else if (sort_231)
			rra(a);
		else if (sort_213)
			sa(a);
		else if (sort_312)
			ra(a);
		else
		{
			sa(a);
			rra(a);
		}
	}
	exit(1);
}
