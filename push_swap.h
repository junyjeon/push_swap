/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:08:07 by junyojeo          #+#    #+#             */
/*   Updated: 2022/11/23 00:42:23 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_info
{
	struct s_info	*prev;
	struct s_info	*next;
	int				data;
}	t_info;

typedef struct s_stack
{
	t_info	*head;
	t_info	*tail;
	int		size;
}	t_stack;

typedef struct s_command
{
	char	sa;
	char	sb;
	char	ss;
	char	pa;
	char	pb;
	char	ra;
	char	rb;
	char	rr;
	char	rra;
	char	rrb;
	char	rrr;
}


int	ft_atoi(const char *str);
t_info	*ft_lstnew(int data, t_stack *s);
int ft_init(t_stack *s, char **ar, int ac);
int	main(int ac, char **ar);


#endif
