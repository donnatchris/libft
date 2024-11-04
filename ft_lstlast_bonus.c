#include "libft_bonus.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*actual_lst;

	if (lst == NULL)
		return (NULL);
	actual_lst = lst;
	while (actual_lst->next != NULL)
		actual_lst = actual_lst->next;
	return (actual_lst);
}
