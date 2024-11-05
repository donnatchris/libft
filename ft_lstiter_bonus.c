/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:28:19 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/05 15:11:50 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current_lst;

	if (lst && f)
	{
		current_lst = lst;
		while (current_lst != NULL)
		{
			f(current_lst->content);
			current_lst = current_lst->next;
		}
	}
}
