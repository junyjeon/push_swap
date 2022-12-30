/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:44:50 by junyojeo          #+#    #+#             */
/*   Updated: 2022/10/06 18:06:26 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{	
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		s_len;
	char	*dst;

	if (!(*s1))
	{
		dst = (char *)malloc(1);
		return (dst);
	}
	s_len = ft_strlen(s1);
	dst = (char *)malloc(sizeof(char) * s_len + 1);
	if (!dst)
		return (0);
	dst[s_len] = '\0';
	while (s_len-- > 0)
		*(dst++) = *(s1++);
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				i;
	unsigned int	s_len;
	char			*str;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	str = (char *)malloc(s_len + 1);
	if (!str)
		return (0);
	i = 0;
	while (len-- && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		src_len;
	int		i;
	int		j;

	src_len = (ft_strlen(s1) + ft_strlen(s2));
	str = (char *)malloc(sizeof(char) * (src_len + 1));
	if (str == NULL)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = *(char *)&s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = *(char *)&s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
