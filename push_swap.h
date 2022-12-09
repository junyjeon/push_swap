/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:08:07 by junyojeo          #+#    #+#             */
/*   Updated: 2022/12/09 21:46:27 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// For little sorting
# define first		(a->top->val)
# define second		(a->top->prev->val)
# define third		(a->top->prev->prev->val)
# define fourth		(a->top->prev->prev->prev->val)
# define last		(a->bottom->val)
# define sort_132	(first < second && second > last && first < last)
# define sort_231	(first < second && second > last && first > last)
# define sort_213	(first > second && second < last && first < last)
# define sort_312	(first > second && second < last && first > last)
# define sort_2134	(second < first && first < third)
# define sort_3124	(third < first && first < fourth)
# define sort_41235	(fourth < first && first < last)


// For struct triangle
# define MAX		(1)
# define MIN		(0)
# define INC		(1)
# define DEC		(-1)
# define IN_A		(1)
# define IN_B		(-1)

//node info
typedef struct s_info
{
	struct s_info	*prev;
	struct s_info	*next;
	size_t			index;
	int				val;
}	t_info;

//size and descending or ascending and stack a or b
typedef struct s_triangle
{
	int	size;
	int	inc_or_dec;
	int	a_or_b;
}	t_tri;

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

/*struct 구조체이름 {
	반환값자료형 (*함수포인터명)(매개변수자료형1, 매개변수자료형2);
};
*/
// typedef struct s_command
// {
// 	int		(*fp[10])(void, void)={&sa, &sb, &ss, &pa, &pb, &ra, &rb, &rr, &rra, &rrb, &rrr};
// }	t_command;

size_t	ft_strlen(const char *str);
int	ft_atoi_ll(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char const *s2, int index);
char	**ft_split(char *s, char c);
t_info	*lstnew(int val);
t_info	*ft_lstlast(t_info *lst);
void	ft_lstadd_front(t_info **lst, t_info *new);
void	ft_lstadd_back(t_info **lst, t_info *new);
void	rrr(t_stack *a, t_stack *b);
void	rrb(t_stack *b);
void	rra(t_stack *a);
void	rr(t_stack *a, t_stack *b);
void	rb(t_stack *b);
void	ra(t_stack *a);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	sb(t_stack *b);
void	sa(t_stack *a);
int	push_front(t_stack *s, int val);
int	push_back(t_stack *s, int val);
int	pop_front(t_stack *s);
int	pop_back(t_stack *s);
int	init(t_stack *a, t_stack *b, char **ar, int ac);
void	check_error(t_stack *a);
void	print_error(char *ar);
void	little_sort(t_stack *a, t_stack *b);
int	main(int ac, char **ar);

#endif
