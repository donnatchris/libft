/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:53:52 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/05 15:12:10 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew;

	lstnew = (t_list *) malloc(sizeof(t_list));
	if (lstnew == NULL)
		return (NULL);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}


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

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_lst;
	t_list	*temp_lst;

	if (*lst && del)
	{
		current_lst = *lst;
		while (current_lst != NULL)
		{
			temp_lst = current_lst;
			current_lst = temp_lst->next;
			del(temp_lst->content);
			free(temp_lst);
		}
		*lst = NULL;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*current_lst;
	t_list	*current_new_lst;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = (void *) malloc(ft_lstsize(lst));
	if (new_lst == NULL)
		return (NULL);
	current_lst = lst;
	current_new_lst = new_lst;
	while (current_lst != NULL)
	{
		current_new_lst = ft_lstnew(current_lst->content);
		if (current_new_lst == NULL)
		{
			ft_lstclear(&new_lst, del);
			free(new_lst);
			return (NULL);
		}
		current_new_lst->next = current_new_lst + 1;
		current_lst = current_lst->next;
		current_new_lst = current_new_lst->next;
	}
	return (new_lst);
}
