/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:56:09 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 21:10:16 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	rotation(t_stack *a, t_stack *b, t_cnt *cnt)
{
	int	i;

	i = 0;
	while (i < cnt->ra && i < cnt->rb)
	{
		rrr(a, b, 1);
		i++;
	}
	while (i < cnt->ra)
	{
		rra(a, 1);
		i++;
	}
	while (i < cnt->rb)
	{
		rrb(b, 1);
		i++;
	}
}
