/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ll_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 04:41:52 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/19 21:10:16 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

static void	range_check(long long *res, int sign)
{
	*res *= sign;
	if (*res < -2147483648 || 2147483647 < *res)
		print_error("It's out of range\n", 1);
}

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
	if (*str == '\0' || *str == ' ')
		print_error("Is not integer\n", 1);
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (*str && (*str < '0' || '9' < *str))
		print_error("Is not integer\n", 1);
	range_check(&res, sign);
	return ((int)res);
}
