#include <stdio.h>

typedef struct s_node
{
	struct	s_node	*next;
	int				data;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*top_next;
	t_node	*end;
	int		cnt;
}	t_stack;

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;

	if (*str == '\0')
		return (0);
	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\"')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (2147483647 < res)
		return (-1);
	return (res * sign);
}

// int	stack_swap(char *ar, t_stack *a, t_stack *b, int elem)
// {
// 	int tmp;

// 	if ((a->end))
// 	{
// 		if (ar == "sa")
// 		{
// 			tmp = a->end->data;
// 			a->end->data = a->prev->data;
// 			a->prev->data = tmp;
// 		}
// 		if (ar == "sb")
// 	}

// }

// int	add_stack(char **ar, t_stack *a)
// {
// 	t_node	*tmp;
// 	int i;

// 	tmp = (t_node *)malloc(sizeof(t_node));
// 	i = 0;
// 	while (*ar[i])
// 	{
// 		tmp->data = ft_atoi(*ar[i]);
// 		tmp->next = a->end;
// 		tmp->
// 		a->end = tmp;
		
// 	}
// }

void	init_stack(t_stack *a, t_stack *b)
{
	a->top = 0;
	a->top_next = 0;
	a->end = 0;
	b->top = 0;
	b->top_next = 0;
	b->end = 0;
}

int main(int ac, char **ar)
{
	t_stack a;
	t_stack b;
	int		i;

	if (ac < 2)
	{
		write(1, "Error\n", 7);
		return (0);
	}
	init_stack(&a, &b);
	i = 0;
	while (*ar[i])
	{
		a->top = 0;
		i++;
	}

	// stack_swap(**ar, &a, &b, elem);
	return (0);
}
