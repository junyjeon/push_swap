/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_make_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:04:43 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/03 20:23:33 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"

//static void	ascending(t_stack *a, t_stack *b)
//{
//	if (sort_231)
//		rra(a);
//	else if (sort_213 || sort_312)
//		sa(a);
//	pb(a, b);
//}

//static void	descending(t_stack *a, t_stack *b)
//{
//	if (sort_132 || sort_231)
//		sa(a);
//	else if (sort_213)
//		rra(a);
//	pb(a, b);
//}

//int	ft_pow(int nb, int power)
//{
//	if (power < 0)
//		return (0);
//	if (power == 0)
//		return (1);
//	if (power == 1)
//		return (nb);
//	return (nb * ft_pow(nb, power - 1));
//}

//int	calc_direction(size_t pow, size_t i)//i번째 삼각형의 방향
//{
//	if (pow == 1)
//		return (1);
//	else if (i < pow / 3)
//		return (calc_direction(pow / 3, i));
//	else if (i < 2 * pow / 3)
//		return (calc_direction(pow / 3, 2 * pow / 3 - 1 - i));
//	else
//		return (calc_direction(pow / 3, pow - 1 - i));
//}

//size_t	calc_amount(size_t pow, size_t i, size_t n)//i번째 삼각형의 크기(데이터의 개수)
//{
//	size_t	tmp;
	
//	if (pow == 1)
//		return (n);
//	else if (i < pow / 3)
//		return (calc_amount(pow / 3, i, n) / 3);
//	else if (i < 2 * pow / 3)
//	{
//		tmp = calc_amount(pow / 3, 2 * pow / 3 - 1 - i, n);
//		return (tmp / 3 + (tmp % 3 > 1));
//	}
//	else
//	{
//		tmp = calc_amount(pow / 3, pow - 1 - i , n);
//		return (tmp / 3 + (tmp % 3 > 0));
//	}
//}

//[0] [1] [2] [3] [4] [5] [6] [7] [8] [9] [10] [11] [12]
//stack_size = 34;
//depth = 1;
//arr_size = ft_pow(3, depth);//== 3
//map[arr_size] = [size, inc_or_dec, a_or_b] [] []

//void	make_array(t_stack *a, t_stack *b)
//{	
//	int	stack_size;
//	int	array_size;
//	int depth;
//	int i;

//	depth = 0;
//	stack_size = a->size;
//	while (stack_size > 6)
//		stack_size /= 3; depth++;
//	array_size = ft_pow(3, depth);
//	t_tri	map[stack_size];
//	i = -1;
//	while (++i < stack_size)
//	{
//		map[i].size = calc_amount(a->size, i, depth);
//		map[i].inc_or_dec = calc_direction(a->size, i);
//		map[i].a_or_b = IN_A;
//	}
//	while (depth)
//	{
//		int j = ft_pow(3, depth--);
//		int k = 3;
		
//		map[j];
//		depth--;
//	}
//}
