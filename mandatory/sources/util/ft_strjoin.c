/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 05:02:42 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/09 04:42:11 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		src_len;
	int		i;
	int		j;

	src_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(src_len + 2);
	if (!str)
		print_error("Memory allocation fail.\n");
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = ' ';
	str[i + 1] = '\0';
	free(s1);
	return (str);
}
