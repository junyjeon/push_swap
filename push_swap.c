// info
// 	val
// 	*next
// 	*prev

// stack
// 	size
// 	*bottom
// 	*top

// 	stack a;
// 	init();
// 	parsing(); -파싱은 ac의 개수가 맞지 않으니까 strjoin으로 하나의 문자열로 만든 후 공백 기준으로 나누고, atoi로 숫자만 찾아
// atoi에서 ', "가 있는 경우부터 
// 	//스택 a는 완성 b 초기화부터 하면 됨..b는 했다 쳐 size 0 bottom 0 top 0.
// 	...
// 	sa(s->top);
	
// 	return (0);
// }

// int	sa(t_info *top)
// {
// 	int	tmp;

// void	*nodeFirst(int val, t_info *bottom)// head와 tail을 더미노드로 설정 123 bottom[1] [1] [2] [3] top[3]
// {
// 	t_info	*node;

// 	node = (t_info *)malloc(sizeof(t_info));
// 	if (!node)
// 		return (0);
// 	node->val = val;
// 	if (!bottom->dir)
// 	{
// 		node->prev = bottom;
// 		node->next = NULL;
// 		bottom->prev = NULL;
// 		bottom->val = 0;
// 		bottom->dir = node;
// 	}
// 	else
// 	{
// 		node->prev = bottom;
// 		node->next = bottom->dir;
// 		bottom->dir->prev = node;
// 		bottom->dir = node;
// 	}
// }

// 	tmp = top->val;
// 	top->dir->val = s->top->dir;
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
	./push_swap "1 3 4" 5 2
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

/*
1. 정수가 아닌 값이 들어왔을 때 'Error' 출력

2. 정수가 중복해서 들어왔을 때 'Error' 출력

3. MAXINT 보다 큰 값 혹은 MININT보다 작은 값이 들어왔을때 'Error' 출력

4. 인자 없이, 혹은 인자가 하나밖에 없거나 이미 정렬된 채로 실행되면 아무것도 출력하지 않고 종료
*/
//스택이 정렬 되어 있는지,

// void	ra(t_stack *a)//a의 top을 tail로 이동
// {
// 	t_info	*tmp;

// 	if (a->size < 2)
// 		return ;
// 	tmp = a->bottom->dir;
// 	a->bottom->dir = a->bottom->dir->next;
// 	a->bottom->dir->prev = NULL;
// 	a->top->dir->next = tmp;
// 	tmp->prev = a->top->dir;
// 	a->top->dir = tmp;
// 	a->top->dir->next = NULL;
// 	write(1, "ra\n", 3);
// }

// void	pa(t_stack *a, t_stack *b)
// {
// 	t_info	*tmp;

// 	if (!b->size)
// 		return ;
// 	tmp = pop_front(b);
// 	tmp = b->bottom->dir;
// 	if (b->size > 1)
// 	{
// 		b->bottom->dir = b->bottom->dir->next;
// 		b->bottom->dir->prev = NULL;
// 	}
// 	if (a->size == 0)
// 	{
// 		tmp->next = NULL;
// 		a->bottom->dir = tmp;
// 		a->top->dir = tmp;
// 	}
// 	else
// 	{
// 		tmp->next = a->bottom->dir;
// 		a->bottom->dir->prev = tmp;
// 		a->bottom->dir = tmp;
// 	}
// 	a->size++;
// 	b->size--;
// 	write(1, "pa\n", 3);
// }
//if sa다음 sb오면 ss로 바꾸기

#include "push_swap.h"

void	hard_coding(t_stack *a, t_stack *b)
{
	int	first;
	int	second;
	int	last;
	int i;
	
	if (1 == a->top->dir->index)
	{
		write(1, "Arguments vector is one\n", 24);
		exit(1);
	}
	first = a->bottom->dir->val;
	if (2 == a->top->dir->index)
	{
		second = a->bottom->dir->next->val;
		if (first > second)
			sa(a);
		exit(1);
	}
	if (3 == a->top->dir->index)
	{
		second = a->bottom->dir->next->val;
		last = a->top->dir->val;
		if (first < second && second > last && first < last)//132
		{
			sa(a);
			ra(a);
		}
		else if (first < second && second > last && first > last)//231
			rra(a);
		else if (first > second && second < last && first < last)//213
			sa(a);
		else if (first > second && second < last && first > last)//312
			ra(a);
		else//321
		{
			sa(a);
			rra(a);
		}
		exit(1);
	}
}

// void	merge_sort(t_stack *a, t_info *left, t_info *right)
// {
// 	t_info	*cur;
// 	t_info	*midlst;

// 	if (left->index < right->index)
// 	{
// 		cur = a->bottom->dir;
// 		while (cur)
// 		{
// 			if (cur->index = (left->index + right->index) / 2)//Divide
// 			{
// 				midlst = cur;
// 				break;
// 			}
// 			printf("%d", cur->index);
// 			cur = cur->next;
// 		}
// 		merge_sort(&a, left, midlst);
// 		merge_sort(&a, midlst->next, right);
// 		merge(&a, left, midlst, right);
// 	}
// }
#include "stdio.h"
int	main(int ac, char **ar)
{
	t_stack a;
	t_stack b;

	init(&a, &b, ar, ac);
	hard_coding(&a, &b);
	// SplitList(a.bottom->dir, a.bottom->dir, a.top->dir);
	merge_sort(&a, &b);
	// error_check(ar, ac, a.size);
	t_info *cura = a.bottom->dir;
	t_info *curb = b.bottom->dir;
	while (cura || curb)
	{
		printf("a:     %d,     b: %d\n", cura->val, curb->val);
		cura = cura->next;
		curb = curb->next;
	}
	return (0);
}
