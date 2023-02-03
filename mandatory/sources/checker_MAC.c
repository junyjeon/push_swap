/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_MAC.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:20:25 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/03 14:51:50 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*line;
	int		*arr;
	stack_init(&a, &b);
	arr = parsing_stack_and_array(&a, argc, argv);
	check_duplicate_and_sort(arr, a.size);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		line = get_next_line(STDIN_FILENO);
		ft_strncmp("sa", line,ft_strlen(line));
		// cmd 처리
		// cmd 예외처리
	}
		// stack a check후 stack a가 정렬이면 끝
	return (0);	
}
