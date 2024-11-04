/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:45:58 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/04 15:50:57 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*******************************************************************************
LIST MANIPULATION FUNCTIONS
******************************************************************************/

t_list	*ft_lstnew(void *content);
//	Allocates (using malloc()) and returns a "fresh" link.
//		The content field in the new link is initialized by copying the
//		function parameter.
//		The next field is initialized to NULL.
//	-> Returns the "fresh" link, or NULL if allocation fails.

void	ft_lstdelone(t_list *lst, void (*del)(void *));
//	Frees the memory of the element passed as parameter using the 'del'
//		function, then with free().
//	!! The memory of the next field is not freed.

void	ft_lstadd_front(t_list **lst, t_list *new);
//	Add the element new at the start of the list
//		(lst is the adress of the first element of the list,
//		and new is the adress of the pointer to the element to be added).

int		ft_lstsize(t_list *lst);
//	Counts the number of elements of the list.
//		Lst is the start of the list.
//	-> Returns the count.

#endif
