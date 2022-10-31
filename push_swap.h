/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:32:56 by junyojeo          #+#    #+#             */
/*   Updated: 2022/10/29 12:32:56 by junyojeo         ###   ########.fr       */
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
	int				content;
}	t_info;

typedef struct s_stack
{
	t_info	*head;
	t_info	*tail;
	int		size;
}	t_stack;

int	ft_atoi(const char *str);
t_info	*ft_lstnew(int content, t_info *tmp, int flag);
int ft_init(t_stack *s, char **ar, int ac);
int	main(int ac, char **ar);


#endif