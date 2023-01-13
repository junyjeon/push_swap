/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:13:27 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/13 19:50:00 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*ft_lstnew(int val)
{
	t_info	*elem;

	elem = malloc(sizeof(t_info));
	if (!elem)
		print_error("Memory allocation fail.\n");
	elem->prev = NULL;
	elem->next = NULL;
	elem->rank = 0;
	elem->val = val;
	return (elem);
}
