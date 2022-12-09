/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 04:41:52 by junyojeo          #+#    #+#             */
/*   Updated: 2022/12/09 20:50:20 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi_ll(const char *str)
{
	long long	res;
	int			sign;

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
	}
	res *= sign;
	if (res < -2147483648 || 2147483647 < res)
		print_error("int");
	return (res);
}
