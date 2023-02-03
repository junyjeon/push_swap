/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:56:09 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 00:10:56 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotation(t_stack *a, t_stack *b, t_cnt *cnt)
{
	int	i;

	i = 0;
	while (i < cnt->ra && i < cnt->rb)
	{
		rrr(a, b);
		i++;
	}
	while (i < cnt->ra)
	{
		rra(a);
		i++;
	}
	while (i < cnt->rb)
	{
		rrb(b);
		i++;
	}
}
