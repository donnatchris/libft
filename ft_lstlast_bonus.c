/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:51:05 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/05 08:51:08 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
