/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:45:27 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/07 17:17:24 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	cmd(char *command, t_stack *a, t_stack *b, char s)
{
	int	len;
	
	len = ft_strlen(command);
	if (s == 'a')
	{
		if (!ft_strncmp(command, "sa", len))
			sa(a);
		else if (!ft_strncmp(command, "ra", len))
			ra(a);
		else if (!ft_strncmp(command, "rra", len))
			rra(a);
		else if (!ft_strncmp(command, "pa", len))
			pa(a, b);
	}
	else if (s == 'b')
	{
		if (!ft_strncmp(command, "sb", len))
			sb(b);
		else if (!ft_strncmp(command, "rb", len))
			rb(b);
		else if (!ft_strncmp(command, "rrb", len))
			rrb(b);
		else if (!ft_strncmp(command, "pb", len))
			pb(a, b);	
	}
	else if (s == 'c')
	{
		if (!ft_strncmp(command, "ss", len))
			ss(a, b);
		else if (!ft_strncmp(command, "rr", len))
			rr(a, b);
		else if (!ft_strncmp(command, "rrr", len))
			rrr(a, b);
	}
	else
		return (0);
	return (1);
}
