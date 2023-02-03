/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:13:27 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 00:29:49 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_info	*ft_lstnew(int val)
{
	t_info	*elem;

	elem = malloc(sizeof(t_info));
	if (!elem)
		print_error("Memory allocation fail.\n");
	elem->prev = NULL;
	elem->prev = NULL;
	elem->rank = 0;
	elem->val = val;
	return (elem);
}
