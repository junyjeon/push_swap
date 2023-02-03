/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:08:07 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/04 04:48:06 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// Define For hardcoding
# define SORT_123	(1)
# define SORT_132	(2)
# define SORT_231	(3)
# define SORT_213	(4)
# define SORT_312	(5)
# define SORT_321	(6)

typedef struct s_info
{
	struct s_info	*prev;
	struct s_info	*next;
	int				rank;
	int				val;
}		t_info;

typedef struct s_stack
{
	t_info	*top;
	t_info	*bottom;
	int		size;
}		t_stack;

typedef struct s_cnt
{
	int	sa;
	int	sb;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	pa;
	int	pb;
}		t_cnt;

typedef struct s_pivot
{
	int	min;
	int	max;
}		t_pivot;

typedef struct s_compare
{
	int	first;
	int	second;
	int	third;
}		t_compare;

size_t	ft_strlen(const char *str);
int		ft_atoi_ll(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char const *s2);
char	**ft_split(char *s, char c);
t_info	*ft_lstnew(int val);

void	push_front(t_stack *s, t_info *new);
void	push_back(t_stack *s, t_info *new);
t_info	*pop_front(t_stack *s);
t_info	*pop_back(t_stack *s);

void	pa(t_stack *a, t_stack *b, int flag);
void	pb(t_stack *a, t_stack *b, int flag);
void	rra(t_stack *a, int flag);
void	rrb(t_stack *b, int flag);
void	rrr(t_stack *a, t_stack *b, int flag);
void	ra(t_stack *a, int flag);
void	rb(t_stack *b, int flag);
void	rr(t_stack *a, t_stack *b, int flag);
void	sa(t_stack *a, int flag);
void	sb(t_stack *b, int flag);
void	ss(t_stack *a, t_stack *b, int flag);

void	cnt_init(t_cnt *cnt);
void	pivot_init(t_pivot *pivot);
void	stack_init(t_stack *a, t_stack *b);
int		compare_init(t_stack *s, t_compare *c);

int		*parse(t_stack *a, int argc, char **argv);
void	ranked(t_stack *a, int *arr, int size);
void	print_error(char *str);

void	sort_three(t_stack *s, char ch);
void	sort_four(t_stack *s, t_stack *s2, char ch);
void	sort_five(t_stack *s, t_stack *s2, char ch);
void	hard_coding(t_stack *s, t_stack *s2, int size, char ch);

void	quick_sort_stack(t_stack *a, t_stack *b, int size, int is_first);
void	quick_sort_stack_b(t_stack *a, t_stack *b, int size);
void	find_pivot(t_stack *s, int size, t_pivot *pivot);
void	partition_when_first(t_stack *a, t_stack *b, t_cnt *cnt, int size);
void	partition(t_stack *a, t_stack *b, t_cnt *cnt, int size);
void	reverse_partition(t_stack *a, t_stack *b, t_cnt *cnt, int size);
void	rotation(t_stack *a, t_stack *b, t_cnt *cnt);

void	show(t_stack *a, t_stack *b);
int		main(int argc, char **argv);

#endif
