/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 01:18:35 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 21:10:16 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*x1;
	unsigned char	*x2;

	x1 = (unsigned char *)s1;
	x2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (x1[i] || x2[i]))
	{
		if (x1[i] != x2[i])
			return (x1[i] - x2[i]);
		i++;
	}
	return (0);
}
