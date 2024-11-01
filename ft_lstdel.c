#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;

	if (!alst || !(*alst) || !del)
		return ;
	while (*alst)
	{
		current = *alst;
		*alst = current->next;
		del(current->content, current->content_size);
		free(current);
	}
	*alst = NULL;
}
