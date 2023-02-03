/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:20:25 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/03 21:06:09 by junyojeo         ###   ########.fr       */
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
		if (!ft_strncmp("sa", line, 2))
			sa(&a);
		else if (!ft_strncmp("sb", line, 2))
			sb(&b);
		else if (!ft_strncmp("ss", line, 2))
			ss(&a, &b);
		else if (!ft_strncmp("ra", line, 2))
			ra(&a);
		else if (!ft_strncmp("rb", line, 2))
			rb(&b);
		else if (!ft_strncmp("rr", line, 2))
			rr(&a, &b);
		else if (!ft_strncmp("rra", line, 3))
			rra(&a);
		else if (!ft_strncmp("rrb", line, 3))
			rrb(&b);
		else if (!ft_strncmp("rrr", line, 3))
			rrr(&a, &b);
		else if (!ft_strncmp("pa", line, 2))
			pa(&a, &b);
		else if (!ft_strncmp("pb", line, 2))
			pb(&a, &b);
		else
			print_error("...................Error\n");
		if (is_sorted(a, a.size, 'a') && b.size == 0)
		{
			write(1, "Error\n", 6);
			break;
		}
	}
	return (0);
}
