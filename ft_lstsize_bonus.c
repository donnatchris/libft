/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:51:21 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/05 08:51:22 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
