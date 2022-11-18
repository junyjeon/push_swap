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

// void	*nodeFirst(int data, t_info *head)// head와 tail을 더미노드로 설정 123 head[1] [1] [2] [3] tail[3]
// {
// 	t_info	*node;

// 	node = (t_info *)malloc(sizeof(t_info));
// 	if (!node)
// 		return (0);
// 	node->data = data;
// 	if (!head->next)
// 	{
// 		node->prev = head;
// 		node->next = NULL;
// 		head->prev = NULL;
// 		head->data = 0;
// 		head->next = node;
// 	}
// 	else
// 	{
// 		node->prev = head;
// 		node->next = head->next;
// 		head->next->prev = node;
// 		head->next = node;
// 	}
// }

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

int	append(int data, t_stack *a)
{
	t_info *new;
	t_info *cur;

	new = (t_info *)malloc(sizeof(t_info));
	if (!new)
		return (0);
	new->data = data;
	if (!a->head->next)
	{
		new->prev = new;
		a->head->prev = NULL;
		a->head->data = 0;
		a->head->next = new;
		a->tail->prev = new;
		a->tail->data = 0;
		a->tail->next = NULL;
	}
	else
	{
		a->tail->prev = new;
		cur = a->head->next;
		while (cur)
			cur = cur->next;
		new->prev = cur;
	}
	new->next = NULL;
	return (1);
}

int init(t_stack *a, t_stack *b, char **ar, int ac)
{
	char	*str;
	char	**res;
	int		i;

	str = NULL;
	i = 1;
	while (i < ac)
		if (!(str = ft_strjoin(str, ar[i++], i)))
			return (0);
	if (!(res = ft_split(str, ' ')))
		return (0);
	i = 0;
	while (res[i])
	{
		if (!append(ft_atoi(res[i++]), a))
			return (0);
	}
	b->head = (t_info *)malloc(sizeof(t_info));
	b->tail = (t_info *)malloc(sizeof(t_info));
	b->head->prev = NULL;
	b->head->next = b->tail;
	b->tail->prev = b->head;
	b->tail->next = NULL;
	return (1);
}

int	main(int ac, char **ar)
{
	t_stack a;
	t_stack b;

	error_check();
	init(&a, &b, ar, ac);
	/*
		if (피벗 < 노드의 데이터)

	if (head < new->data)
	{
		a 나 b의 왼쪽(위쪽 상관없이 분리) 
	}
	*/
	return (0);
}
