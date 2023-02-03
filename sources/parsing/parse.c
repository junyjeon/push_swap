/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:53:59 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 03:16:36 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	arr_sort(int *arr, int size, int swap_cnt)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				swap_cnt++;
			}
		}
	}
	if (swap_cnt == 0)
		print_error("It's aligned.\n");
}

static void	check_overlap(int *arr, int size)
{
	int	i;

	if (1 == size)
		print_error("Arguments vector is one.\n");
	arr_sort(arr, size, 0);
	i = -1;
	while (++i < size - 1)
		if (arr[i] == arr[i + 1])
			print_error("Duplicate!\n");
}

static int	*make_list(t_stack *a, char **split_str, int index)
{
	t_info	*new;
	int		*arr;
	
	arr = malloc(sizeof(int) * index);
	if (!arr)
		print_error("Memory allocation fail.\n");
	while (index--)
	{
		arr[index] = ft_atoi_ll(split_str[index]);
		new = ft_lstnew(arr[index]);
		push_back(a, new);
		free(split_str[index]);
	}
	return (arr);
}

int	*parse(t_stack *a, int argc, char **argv, int index)
{
	char	**split_str;
	char	*str;
	int		*arr;

	str = NULL;
	while (argc--)
		str = ft_strjoin(str, argv[argc]);//
	split_str = ft_split(str, ' ');
	index = 0;
	while (split_str[index])
		index++;
	arr = make_list(a, split_str, index);
	check_overlap(arr, a->size);
	free(split_str);
	return (arr);
}
