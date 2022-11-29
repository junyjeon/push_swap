/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:24:57 by junyojeo          #+#    #+#             */
/*   Updated: 2022/10/29 13:24:57 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2, int index)
{
	char	*str;
	int		src_len;
	int		i;
	int		j;

	src_len = (ft_strlen(s1) + ft_strlen(s2));
	str = malloc(src_len + 2);
	if (str == NULL)
		return (0);
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
	if (!(index == 1))
		free(s1);
	return (str);
}
// char	*ft_strjoin(char *s1, char const *s2, int first)
// {
// 	char	*str;
// 	int		s_len;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	if (s1)
// 		while (s1[i])
// 			i++;
// 	j = 0;
// 	while (s2[j])
// 		j++;
// 	s_len = i + j;
// 	str = malloc(s_len + 1);
// 	if (str == NULL)
// 		return (0);
// 	i = 0;
// 	if (s1)
// 	{
// 		while (s1[i])
// 		{
// 			str[i] = s1[i];
// 			i++;
// 		}
// 	}
// 	j = 0;
// 	while (s2[j])
// 	{
// 		str[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	str[i] = ' ';
// 	str[i + 1] = '\0';
// 	if (!(first == 1))
// 		free(s1);
// 	return (str);
// }

void error_print(int type)
{
	if (type >= 1)
		write(2, "Error\n", 6);
	exit(1);
}

int	ft_atoi_ll(const char *str)
{
	long long	res;
	int			sign;
	int			chker;

	if (*str == '\0')
		return (0);
	sign = 1;
	res = 0;
	while (*str == ' ')
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
		chker++;
	}
	res *= sign;
	if (*str != '\0' || chker > 10 || res < -2147483648 || 2147483647 < res)
		error_print(1);
	return (res);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	if (dest == src)
		return (dest);
	s = (char *)src;
	d = (char *)dest;
	while (n-- > 0)
		*(d++) = *(s++);
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	size_t	s_len;
	char	*dst;

	s_len = ft_strlen(s1);
	dst = (char *)malloc(sizeof(char) * s_len + 1);
	if (!dst)
		return (0);
	ft_memcpy(dst, s1, s_len);
	dst[s_len] = '\0';
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

	i = 0;
	while (res[i])
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
				return (0);
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
		return (0);
	ft_division(s, c, res);
	res[word_cnt] = NULL;
	return (res);
}
