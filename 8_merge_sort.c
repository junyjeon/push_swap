/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_merge_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:04:43 by junyojeo          #+#    #+#             */
/*   Updated: 2022/12/05 20:51:04 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_max(t_stack *a, t_stack *b)
{
	if (sort_231)
		rra(a);
	else if (sort_213 || sort_312)
		sa(a);
	pb(a, b);
}

static void	_max(t_stack *a, t_stack *b)
{
	if (sort_132 || sort_231) // 132
		sa(a);
	else if (sort_213) // 213
		rra(a);
	pb(a, b);
}

void	merge_sort(t_stack *a, t_stack *b)
{
	int arr[2];
	int i;
	int j;

	// if (n < 3)
	// {
	// 	if (direct)
	// 		arr[i] = 1;
	// 	else
	// 		arr[i] = -1;
	// }
	// else
	// {
	// 	if (direct)
	// 	{

	// 	}
	// 	else
	// 		배열 [][][]  a->size / 3, + a->size % 3
	// }
	/* |\ max부터
	if (sort_132 || sort_231) // 132
		sa(a);
	else if (sort_213) // 213
		rra(a);
	pb(a, b);
	*/
	/*|/ min부터
	if (sort_231)
		rra(a);
	else if (sort_213 || sort_312)
		sa(a);
	pb(a, b);
	*/
}

void	merge_sort(t_stack *a, t_stack *b, int *arr, int div)
{
	if (div < 6)
		return ;
	else
	{
		merge_sort(a, b, arr, div);
		int i = 0;
		while (arr[i])
		{
			div = arr[i];
			while (--div)
			{

				div--;
			}
			i++;
		}
	}
}

int	pow(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * pow(nb, power - 1));
}

int	calc_direction(size_t pow, size_t i)
{
	if (pow == 1)
		return (1);
	else if (i < pow / 3)
		return (calc_direction(pow / 3, i));
	else if (i < 2 * pow / 3)
		return (calc_direction(pow / 3, 2 * pow / 3 - 1 - i));
	else
		return (calc_direction(pow / 3, pow - 1 - i));
}

size_t	calc_amount(size_t pow, size_t i, size_t n)
{
	size_t	tmp;
	
	if (pow == 1)
		return (n);
	else if (i < pow / 3)
		return (calc_amount(pow / 3, i, n) / 3);
	else if (i < 2 * pow / 3)
	{
		tmp = calc_amount(pow / 3, 2 * pow / 3 - 1 - i, n);
		return (tmp / 3 + (tmp % 3 > 1));
	}
	else
	{
		tmp = calc_amount(pow / 3, pow - 1 - i , n);
		return (tmp / 3 + (tmp % 3 > 0));
	}
}

void	make_arr(t_stack *a, t_stack *b)
{	
	int	stack_size;
	int depth;
	int i;

	depth = 0;
	stack_size = a->size;
	while (stack_size > 6)
	{
		stack_size /= 3;
		depth++;
	}
	int arr_size = pow(3, depth);
	t_tri	map[arr_size];
	i = 0;
	while (i < arr_size)
	{
		map[i].size = calc_amount(a->size, i, depth);
		map[i].inc_or_dec = calc_direction(a->size, i);
		if (depth % 2 == 0)
			map[i].a_or_b = 1;
		else
			map[i].a_or_b = -1;
	}
	//들어갔다고 치고 안들어갔어..
	//
	//배열의 인덱스 arr[i + 1]과 arr[(arr_size / 3 ) * 2 - 1 - i] arr[(arr_size / 3) * 3 - 1 - i];
}
//배열을 만들 depth를 구함.
//그림을 그려 준영아!
