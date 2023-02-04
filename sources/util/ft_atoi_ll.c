/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 04:41:52 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/05 01:04:48 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "stdio.h"

int	ft_atoi_ll(const char *str)
{
	int	res;
	int	sign;

	if (*str == '\0')
		return (0);
	sign = 1;
	res = 0;
	while (*str == ' ')
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
	{
		if (*(str + 1) == ' ' || *(str + 1) == '\0')
			print_error("Is not integer\n", 1);
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	printf("sign: %d, str: %c\n", sign, *str);
	if (*str && ((*str < '0' || '9' < *str)))
		print_error("Is not integer\n", 1);
	if (2147483647 < res)
		print_error("It's out of range\n", 1);
	res *= sign;
	return (res);
}
