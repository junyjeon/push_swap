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
	a->size++;
	return (1);
}

int init(t_stack *a, t_stack *b, char **ar, int ac)
{
	char	*str;
	char	**res;
	int		i;

	if (ac < 3)
		error_print(1);
	str = NULL;
	i = 1;
	while (i < ac)
		if (!(str = ft_strjoin(str, ar[i++], i)))
			return (0);
	if (!(res = ft_split(str, ' ')))
		return (0);
	i = 0;
	while (res[i])
		if (!append(ft_atoi_ll(res[i++]), a))
			return (0);
	b->head = (t_info *)malloc(sizeof(t_info));//왜 잃어버리지 ???? ???? ????
	b->tail = (t_info *)malloc(sizeof(t_info));
	b->head->prev = NULL;
	b->head->data = 0;
	b->head->next = NULL;
	b->tail->prev = NULL;
	b->tail->data = 0;
	b->tail->next = NULL;
	b->size = 0;
	return (1);
}
/*
1. 정수가 아닌 값이 들어왔을 때 'Error' 출력

2. 정수가 중복해서 들어왔을 때 'Error' 출력

3. MAXINT 보다 큰 값 혹은 MININT보다 작은 값이 들어왔을때 'Error' 출력

4. 인자 없이, 혹은 인자가 하나밖에 없거나 이미 정렬된 채로 실행되면 아무것도 출력하지 않고 종료
*/
//스택이 정렬 되어 있는지,

int	error_check(char *ar, int size)
{
	int i;
	int j;
	int tmp;
	int	chker;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1)
		{
			if (ar[j] > ar[j + 1])
			{
				tmp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = tmp;
				chker++;
			}
		}
		if (ar[i] == ar[i + 1])//정렬 후 숫자가 중복되어도 error
			error_print(1);
	}
	if (chker == 0)//끝에 chker가 0이면 정렬 되어있음
		error_print(-1);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}

void	rrb(t_stack *b)
{
	t_info	*tmp;

	tmp = pop_back(b);
	push_front(b, tmp);
}

void	rra(t_stack *a)
{
	t_info	*tmp;
	
	tmp = pop_back(a);
	push_front(a, tmp);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rb(t_stack *b)
{
	t_info	*tmp;

	if (b->size <= 1)
		return ;
	tmp = b->head->next;
	b->head->next = b->head->next->next;
	b->head->next->prev = NULL;
	b->tail->prev->next = tmp;
	tmp->prev = b->tail->prev;
	b->tail->prev = tmp;
	b->tail->prev->next = NULL;
	write(1, "rb\n", 3);
}

void	ra(t_stack *a)
{
	t_info	*tmp;

	if (a->size < 2)
		return ;
	tmp = a->head->next;
	a->head->next = a->head->next->next;
	a->head->next->prev = NULL;
	a->tail->prev->next = tmp;
	tmp->prev = a->tail->prev;
	a->tail->prev = tmp;
	a->tail->prev->next = NULL;
	write(1, "ra\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_info	*tmp;

	if (!a->size)
		return ;
	tmp = a->head->next;
	if (a->size > 1)
	{
		a->head->next = a->head->next->next;
		a->head->next->prev = NULL;
	}
	if (b->size == 0)
	{
		tmp->next = NULL;
		b->head->next = tmp;
		b->tail->prev = tmp;
	}
	else
	{
		tmp->next = b->head->next;
		b->head->next->prev = tmp;
		b->head->next = tmp;
	}
	b->size--;
	a->size++;
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)//b의 front를 a의 front로 이동
{
	t_info	*tmp;

	if (!b->size)
		return ;
	tmp = pop_front(b);
	tmp = b->head->next;
	if (b->size > 1)
	{
		b->head->next = b->head->next->next;
		b->head->next->prev = NULL;
	}
	if (a->size == 0)
	{
		tmp->next = NULL;
		a->head->next = tmp;
		a->tail->prev = tmp;
	}
	else
	{
		tmp->next = a->head->next;
		a->head->next->prev = tmp;
		a->head->next = tmp;
	}
	a->size++;
	b->size--;
	write(1, "pa\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	sb(t_stack *b)
{
	int	tmp;

	if (!b->size)
		return ;
	tmp = b->head->next->data;
	b->head->next->data = b->head->next->next->data;
	b->head->next->next->data = tmp;
	write(1, "sb\n", 3);
}

void	sa(t_stack *a)
{
	int	tmp;

	if (!a->size)
		return ;
	tmp = a->head->next->data;
	a->head->next->data = a->head->next->next->data;
	a->head->next->next->data = tmp;
	write(1, "sa\n", 3);
}

int	main(int ac, char **ar)
{
	t_stack a;
	t_stack b;

	if (!init(&a, &b, ar, ac))
		return (-1);
	if (!error_check(ac, a.size))
		return (-1);
	
	/*
		if (피벗 < 노드의 데이터)

	if (head < new->data)
	{
		a 나 b의 왼쪽(위쪽 상관없이 분리) 
	}
	*/
	return (0);
}
