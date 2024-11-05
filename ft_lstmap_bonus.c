/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:53:52 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/05 10:41:34 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*current_lst;
	t_list	*current_new_lst;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = (void *) malloc(ft_lstsize(lst) * sizeof(t_list));
	if (new_lst == NULL)
		return (NULL);
	current_lst = lst;
	current_new_lst = new_lst;
	while (current_lst != NULL)
	{
		current_new_lst = ft_lstnew(current_lst->content);
		current_new_lst->next = current_new_lst + 1;
		current_lst = current_lst->next;
		current_new_lst = current_new_lst->next;
	}
	return (new_lst);
}
