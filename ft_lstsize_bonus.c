#include "libft_bonus.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*lst_actual;

	lst_actual = lst;
	size = 0;
	while (lst_actual != NULL)
	{
		size++;
		lst_actual = lst_actual->next;
	}
	return (size);
}
