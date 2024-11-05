/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:53:52 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/05 17:04:32 by chdonnat         ###   ########.fr       */
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_lst;

	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{
		current_lst = *lst;
		while (current_lst->next != NULL)
			current_lst = current_lst->next;
		current_lst->next = new;
		new->next = NULL;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	t_list	*current;

	if (!lst || !f || !del)
		return (NULL);
	first = NULL;
	first = f(ft_lstnew(lst->content));
	current = lst->next;
	while (current != NULL)
	{
		new = f(ft_lstnew(current->content));
		ft_lstadd_back(&first, new);
		current = current->next;
	}
	return (first);
}
