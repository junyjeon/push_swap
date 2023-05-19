/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:48:13 by marvin            #+#    #+#             */
/*   Updated: 2023/05/19 21:10:16 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

static int	word_len(char const *s, char c, size_t i)
{
	size_t	cnt;

	cnt = 0;
	while (s[i] != c)
	{
		if (!s[i])
			break ;
		cnt++;
		i++;
	}
	return (cnt);
}

static void	ft_free(char **res)
{
	size_t	i;

	i = -1;
	while (res[++i])
		free(res[i]);
	free(res);
}

static char	**ft_division(char *s, char c, char **res)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (s[i] == '\0')
				return (res);
			res[j] = ft_substr(s, i, word_len(s, c, i));
			if (!res[j])
			{
				ft_free(res);
				print_error("Memory allocation fail.\n", 1);
			}	
			i = i + word_len(s, c, i);
			j++;
		}
		else
			i++;
	}
	free(s);
	return (res);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	word_cnt;
	char	**res;

	word_cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word_cnt++;
		i++;
	}
	res = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!res)
		print_error("Memory allocation fail.\n", 1);
	ft_division(s, c, res);
	res[word_cnt] = NULL;
	return (res);
}
