#include <stdio.h>

# define MAX		(1)
# define MIN		(0)
# define INC		(1)
# define DEC		(-1)
# define IN_A		(1)
# define IN_B		(-1)

typedef struct s_triangle
{
	int	size;
	int	inc_or_dec;
	int	a_or_b;
}	t_tri;

void	make_arr()
{	
	int	stack_size;
	int depth;
	int i;

	depth = 0;
	stack_size = 10;
	while (stack_size > 6)
	{
		stack_size /= 3;
		depth++;
	}
	int arr_size = _pow(3, depth);
	t_tri	map[arr_size];
	i = 0;
	while (i < arr_size)
	{
		map[i].size = calc_amount(a->size, i, depth);
		map[i].inc_or_dec = calc_direction(a->size, i);
		map[i].a_or_b = IN_A;
		i++;
	}
	//merge_div();
	i = pow(3, depth);
	int j = pow(3, depth + 1);
	while (i < j)
	{
		if (map[i].inc_or_dec == 1)
			max(a, b);
		else
			min(a, b);
		map[i].a_or_b = IN_B;
		i++;
	}
	i = 0;
	while (map[i])
	{
		printf ("%d, size: %d inc_or_dec: %d a_or_b: %d", i, map[i].size, map[i], map[i].inc_or_dec, map[i].a_or_b);
		i++;
	}
	//배열의 인덱스 arr[i + 1]과 arr[(arr_size / 3 ) * 2 - 1 - i] arr[(arr_size / 3) * 3 - 1 - i];
}

int main()
{
	
	make_arr(a, b);
	return (0);
}
