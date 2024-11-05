/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:45:58 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/05 09:53:32 by chdonnat         ###   ########.fr       */
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
//	Allocates (using malloc()) and returns a new link.
//		The content field in the new link is initialized with the value of the
//		content parameter.
//		The next field is initialized to NULL.
//	-> Returns the "fresh" link, or NULL if allocation fails.

void	ft_lstdelone(t_list *lst, void (*del)(void *));
//	Frees the memory of the element passed as parameter using the 'del'
//		function, then with free().
//	!! The memory of the next field is not freed.

void	ft_lstadd_front(t_list **lst, t_list *new);
//	Add the element new at the start of the list
//		(lst is the address of the pointer to the first element of the list,
//		and new is the address of the pointer to the element to be added).

int		ft_lstsize(t_list *lst);
//	Counts the number of elements of the list.
//		Lst is the start of the list.
//	-> Returns the count.

t_list	*ft_lstlast(t_list *lst);
//	Finds the last element of the list (where lst is the first element).
//	-> Returns the last element of the list.

void	ft_lstadd_back(t_list **lst, t_list *new);
//	Add the element new to the end of the list.
//		(lst is the adress of the pointer to  the first element of the list,
//		and new is the address of the pointer to the element to be added).

void	ft_lstclear(t_list **lst, void (*del)(void*));
//	Deletes and frees the memory of the element passed as parameter and of all
//		the following elements, using the del() function and free().
//		Sets the initial pointer to NULL.
//		(lst is the address to the pointer to an element and del is the adress
//		of the function that can suppress the content of an element).

void	ft_lstiter(t_list *lst, void (*f)(void *));
//	Iterates over the list lst and applies the function f() to the content
//		of each element (lst is the address of the pointer to an element and
//		f is the address of the function to apply).

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//	Iterates over the list lst and applies the function f() to the content
//		of each element.
//		Creates a new list resulting from the successive applications of
//		f().
//		The function del() is here to destroy the content of an element if
//		needed.
//	-> Returns the new list otr NULL if allocation fails.

#endif
