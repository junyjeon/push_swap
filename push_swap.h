/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:08:07 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/07 22:20:39 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// For hardcoding
# define first		(a->top->val)
# define second		(a->top->prev->val)
# define third		(a->top->prev->prev->val)
# define fourth		(a->top->prev->prev->prev->val)
# define fifth		(a->top->prev->prev->prev->prev->val)
# define sort_132	(first < second && second > third && first < third)
# define sort_231	(first < second && second > third && first > third)
# define sort_213	(first > second && second < third && first < third)
# define sort_312	(first > second && second < third && first > third)
# define sort_321	(first > second && second > third && first > third)
# define sort_2134	(second < first && first < third)
# define sort_3124	(third < first && first < fourth)
# define sort_41235	(fourth < first && first < fifth)

// For struct triangle
//# define MAX		(1)
//# define MIN		(0)
//# define INC		(1)
//# define DEC		(-1)
//# define IN_A		(1)
//# define IN_B		(-1)

/*struct 구조체이름 {
	반환값자료형 (*함수포인터명)(매개변수자료형1, 매개변수자료형2);
};
*/
// typedef struct s_command
// {
// 	int		(*fp[10])(void, void)={&sa, &sb, &ss, &pa, &pb, &ra, &rb, &rr, &rra, &rrb, &rrr};
// }	t_command;

//node info
typedef struct s_info
{
	struct s_info	*prev;
	struct s_info	*next;
	size_t			index;
	int				rank;
	int				val;
}	t_info;

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
}	t_cnt;

//size and descending or ascending and stack a or b
//typedef struct s_triangle_map
//{
//	int	size;
//	int	inc_or_dec;
//	int	a_or_b;
//}	t_tri_map;

/* NOTE
 * ------------------------
 *                        |
 *       INC =    *       |
 *               /|       |
 *              / |       |
 *             /__|       |
 *                        |
 * ------------------------
 *                        |
 *       DEC = ____       |
 *             \  |       |
 *              \ |       |
 *               \|       |
 *                *       |
 * ------------------------
 * */

//stack info
typedef struct s_stack
{
	t_info	*top;
	t_info	*bottom;
	int			size;
}	t_stack;

size_t	ft_strlen(const char *str);
long long	ft_atoi(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char const *s2, int index);
char	**ft_split(char *s, char c);
t_info	*lstnew(int val);
t_info	*ft_lstlast(t_info *lst);
void	ft_lstadd_front(t_info **lst, t_info *new);
void	ft_lstadd_back(t_info **lst, t_info *new);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	cmd(t_stack *a, t_stack *b, char *command, char c);
int	push_front(t_stack *s, int val);
int	push_back(t_stack *s, int val);
int	pop_front(t_stack *s);
int	pop_back(t_stack *s);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	print_error(char *ar);
int	stack_init(t_stack *a, t_stack *b);
int	*parsing_stack_and_array(t_stack *a, char **argv, int ac);
void	sort_arr(t_stack *a, int *ar);
void	ranked(t_stack *a, int *arr);
void	quick_sort(t_stack *a, t_stack *b, int size);
void	a_to_b(t_stack *a, t_stack *b, int size);
void	b_to_a(t_stack *a, t_stack *b, int size);
void	hard_coding(t_stack *a, t_stack *b, int size, char s);
int	main(int ac, char **ar);

#endif
