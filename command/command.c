/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:45:27 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/07 17:39:53 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	cmd(t_stack *a, t_stack *b, char *command, char c)
{
	int	len;
	
	len = ft_strlen(command);
	if (c == 'a')
	{
		if (!ft_strncmp(command, "s", len))
			sa(a);
		else if (!ft_strncmp(command, "r", len))
			ra(a);
		else if (!ft_strncmp(command, "rr", len))
			rra(a);
		else if (!ft_strncmp(command, "p", len))
			pa(a, b);
	}
	else if (c == 'b')
	{
		if (!ft_strncmp(command, "s", len))
			sb(b);
		else if (!ft_strncmp(command, "r", len))
			rb(b);
		else if (!ft_strncmp(command, "rr", len))
			rrb(b);
		else if (!ft_strncmp(command, "p", len))
			pb(a, b);	
	}
	else if (c == 'c')
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
