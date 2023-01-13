/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:08:07 by junyojeo          #+#    #+#             */
/*   Updated: 2023/01/13 20:31:11 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// For hardcoding
# define first		(a->bottom->val)
# define second		(a->bottom->next->val)
# define third		(a->bottom->next->next->val)
# define sort_132	(first < second && second > third && first < third)
# define sort_231	(first < second && second > third && first > third)
# define sort_213	(first > second && second < third && first < third)
# define sort_312	(first > second && second < third && first > third)

//node info
typedef struct s_info
{
	struct s_info	*prev;
	struct s_info	*next;
	int				rank;
	int				val;
}		t_info;

//stack info
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

size_t	ft_strlen(const char *str);
int		ft_atoi_ll(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char const *s2);
char	**ft_split(char *s, char c);
t_info	*ft_lstnew(int val);
void	push_front(t_stack *s, int val);
void	push_back(t_stack *s, int val);
int		pop_front(t_stack *s);
int		pop_back(t_stack *s);
int		cmd(t_stack *a, t_stack *b, char *command, char c);
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
void	print_error(char *str);
void	stack_init(t_stack *a, t_stack *b);
int		*parsing_stack_and_array(t_stack *a,  int argc, char **argv);
void	check_duplicate_and_sort(int *arr, int size);
void	ranked(t_stack *a, int *arr);
void	quick_sort(t_stack *a, t_stack *b, int size);
void	a_to_b(t_stack *a, t_stack *b, int size);
void	b_to_a(t_stack *a, t_stack *b, int size);
void	hard_coding(t_stack *a, t_stack *b, int size, char s);
int		main(int ac, char **ar);

#endif

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
