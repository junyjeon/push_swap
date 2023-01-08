/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:13:27 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/09 01:20:39 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*lstnew(int val)
{
	t_info	*elem;

	elem = malloc(sizeof(elem));
	if (!elem)
		return (0);
	elem->prev = NULL;
	elem->val = val;
	elem->next = NULL;
	return (elem);
}
