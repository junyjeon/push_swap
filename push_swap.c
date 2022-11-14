// info
// 	content
// 	*next
// 	*prev

// stack
// 	size
// 	*head
// 	*tail
// //
// 	stack a;
// 	init();
// 	parsing();
// 	//스택 a는 완성 b 초기화부터 하면 됨..b는 했다 쳐 size 0 head 0 tail 0.
// 	...
// 	sa(s->tail);
	
// 	return (0);
// }

// int	sa(t_info *tail)
// {
// 	int	tmp;

// 	tmp = tail->content;
// 	tail->prev->content = s->tail->prev;
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:21:34 by junyojeo          #+#    #+#             */
/*   Updated: 2022/10/29 13:21:34 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = ' ';
	str[i + 1] = '\0';
	free(s1);
	return (str);
}

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;

	if (*str == '\0')
		return (0);
	sign = 1;
	res = 0;
	while (*str == 32 || *str == '\'' || *str == '\"')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (!(res <= 2147483647))
		return (0);
	return (res * sign);
}

t_info	*ft_lstnew(int content, t_info *tmp, int flag)
{
	t_info	*elem;

	elem = (t_info *)malloc(sizeof(t_info));
	if (!elem)
		return (0);
	elem->content = content;
	if (flag)
		elem->prev = tmp;
	else
		elem->prev = NULL;	
	return (elem);
}

int ft_init(t_stack *s, char **ar, int ac)
{
	t_info *tmp;
	char	*str;
	int		i;

	tmp = NULL;
	i = 1;
	while (i < ac - 1)
		str = ft_strjoin(str, ar[i]);
	
	tmp->next = NULL;
	s->tail = tmp;
	return (1);
}

int	main(int ac, char **ar)
{
	t_stack s;

	ft_init_passing(&s, ar, ac);
	oper();

	return (0);
}
