#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lstnew;

	lstnew = (t_list *) malloc (sizeof t_list);
	if (lstnew == NULL)
		return (NULL);
	if (content == NULL)
	{
		lstnew->content = NULL;
		lstnew->content_size = 0;
		return (lstnew);
	}
	lstnew->content = (void *) malloc (content_size);
	if (lstnew->content == NULL)
	{
		free (lstnew);
		return (NULL);
	}
	ft_memcpy(lstnew->content, content, content_size);
	lstnew->content_size = content_size;
	lstnew->next = NULL;
	return (lstnew);
}
