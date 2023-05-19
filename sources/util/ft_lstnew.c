/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:13:27 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/20 03:22:55 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_info	*ft_lstnew(int val)
{
	t_info	*elem;

	elem = malloc(sizeof(t_info));
	if (!elem)
		print_error("Memory allocation fail.\n", 1);
	elem->prev = NULL;
	elem->prev = NULL;
	elem->rank = 0;
	elem->val = val;
	return (elem);
}
