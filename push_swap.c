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

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;

	if (*str == '\0')
		return (0);
	sign = 1;
	res = 0;
	while (*str == 32)
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
	if (res <= 2147483647)
		return (res * sign);
	return (0);
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
	int 	i;

	tmp = NULL;
	i = 2;
	while (i <= ac)
	{
		if (i == 2)
		{
			tmp = ft_lstnew(ft_atoi(ar[i]), tmp, 0);
			if (!tmp)
				return (0);
			s->head = tmp;
		}
		else
		{
			tmp->next = ft_lstnew(ft_atoi(ar[i]), tmp, 1);
			if (!tmp)
				return (0);
			tmp = tmp->next;
		}
		s->size++;
	}
	tmp->next = NULL;
	s->tail = tmp;
	return (1);
}

int	main(int ac, char **ar)
{
	t_stack s;

	ft_init(&s, ar, ac);
	return (0);
}