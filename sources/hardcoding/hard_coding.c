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

#include "../../includes/push_swap.h"

void	hard_coding(t_stack *s, t_stack *s2, int size, char c)
{
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if (c == 'a' && first > second)
			sa(s);
		else if (c == 'b' && first < second)
			sb(s);
	}
	else if (size == 3)
		sort_three(s, c);
	else if (size == 4)
		sort_four(s, s2, c);
	else if (size == 5)
		sort_five(s, s2, c);
}
