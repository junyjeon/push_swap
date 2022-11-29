/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:08:07 by junyojeo          #+#    #+#             */
/*   Updated: 2022/11/29 11:10:41 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define first		(a->top->dir->val)
# define second		(a->top->dir->next->val)
# define last		(a->bottom->dir->val)
# define sort_132	(first < second && second > last && first < last)
# define sort_231	(first < second && second > last && first > last)
# define sort_213	(first > second && second < last && first < last)
# define sort_312	(first > second && second < last && first > last)

typedef struct s_info
{
	struct s_info	*prev;
	struct s_info	*next;
	size_t			index;
	int				val;
}	t_info;

typedef struct s_direction
{
	t_info	*dir;
}	t_direction;

typedef struct s_stack
{
	t_direction	*top;
	t_direction	*bottom;
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
char	*ft_strjoin(char *s1, char const *s2, int first_val);
int	ft_atoi_ll(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
static int	word_len(char const *s, char c, size_t i);
static void	ft_free(char **res);
static char	**ft_division(char *s, char c, char **res);
char	**ft_split(char *s, char c);
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
void	push_front(t_stack *s, int val);
void	push_back(t_stack *s, int val);
int	pop_front(t_stack *s);
int	pop_back(t_stack *s);
void	error_print(int type);
int	error_check(char *ar, int size);
int	init(t_stack *a, t_stack *b, char **ar, int ac);
void	merge_sort(t_stack *a, t_stack *b);
void	little_sort(t_stack *a, t_stack *b)
int	main(int ac, char **ar);


#endif
