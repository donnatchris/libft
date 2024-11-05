/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:03:53 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/05 15:11:30 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
