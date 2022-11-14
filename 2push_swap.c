# include <stdlib.h>
# include <unistd.h>

typedef struct s_info
{
	struct s_info	*prev;
	struct s_info	*next;
	int				content;
}	t_info;

typedef struct s_stack
{
	t_info	*head;
	t_info	*tail;
	int		size;
}	t_stack;

int main(int ac, char **ar)
{
	t_info *tmp;
	t_info *elem;

	int i = 0;

	tmp = NULL;
	i = 2;
	while (i <= ac)
	{
		if (i == 2)
		{
			elem = (t_info *)malloc(sizeof(t_info));
			if (!elem)
				return (0);
			elem->content = ft_atoi(ar[i], tmp, 1);
				
		}
	}
	return (0);
}
