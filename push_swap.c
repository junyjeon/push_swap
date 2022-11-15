// info
// 	data
// 	*next
// 	*prev

// stack
// 	size
// 	*head
// 	*tail

// 	stack a;
// 	init();
// 	parsing(); -파싱은 ac의 개수가 맞지 않으니까 strjoin으로 하나의 문자열로 만든 후 공백 기준으로 나누고, atoi로 숫자만 찾아
// atoi에서 ', "가 있는 경우부터 
// 	//스택 a는 완성 b 초기화부터 하면 됨..b는 했다 쳐 size 0 head 0 tail 0.
// 	...
// 	sa(s->tail);
	
// 	return (0);
// }

// int	sa(t_info *tail)
// {
// 	int	tmp;

// 	tmp = tail->data;
// 	tail->prev->data = s->tail->prev;
// }
/* 에러 내뿜고 exit()하기 문자일때, 부호만 있을때//, 혹시 "발견 하면 인덱스 저장해두고 다시 발견하면 저장해둔 인덱스부터 공백기준 split, int범위 밖일 때, 부호 뒤에 숫자가 안나올때??
	./push_swap 1 2 3 4 -
	./push_swap "-"
	./push_swap "-one"
	./push_swap " 1 one  2 3  4 "
	./push_swap 1 "  2 3  4 " 1
	./push_swap 2 +3  4- " "
	./push_swap 2147483648 +3  4- " "
	./push_swap +2147483648 +3  4- " "
	./push_swap +2147483648 "++3"  4- " "
	./push_swap "++3" 4- " "
	./push_swap -2147483649 " "
	./push_swap " "
	./push_swap "" 33
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:21:34 by junyojeo          #+#    #+#             */
/*   Updated: 2022/10/29 13:21:34 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_info	*ft_lstnew(int data, t_stack *s)// head와 tail을 더미노드로 설정 123 head[1] [1] [2] [3] tail[3]
{
	t_info	*elem;

	elem = (t_info *)malloc(sizeof(t_info));
	if (!elem)
		return (0);
	elem->data = data;
	elem->prev = s->tail->prev;
	elem->next = s->tail;
	s->tail->prev->next = elem;
	s->tail->prev = elem;
	s->size++;
	return (elem);
}

int ft_init(t_stack *s, char **ar, int ac)
{
	t_info *tmp;
	char	*str;
	int		i;

	i = 1;
	while (i < ac)
		str = ft_strjoin(str, ar[i], i);
	ar = ft_split(str, ' ');
	i = 0;
	while (ar)
	{
		tmp = ft_lstnew(ft_atoi(ar[i]), s);
		// if (i == 1)
		// {
		// 	tmp = ft_lstnew(ft_atoi(ar[i]), tmp, 1);
		// }
		// else
		// {
		// 	tmp = ft_lstnew(ft_atoi(ar[i]), tmp, 0));
		// 	tmp->prev = s->tail;
		// 	tmp->next = s->tail;
		// 	tmp = ft_lstnew(ft_atoi(ar[i]), tmp);
		// }
		ar++;
	}
	tmp->next = NULL;
	return (1);
}

int	main(int ac, char **ar)
{
	t_stack s;

	ft_init_passing(&s, ar, ac);
	oper();

	return (0);
}
