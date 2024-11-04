/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:51:12 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/04 16:25:29 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*calloc;
	size_t	i;

	if (size == 0 || nmemb == 0)
		return (NULL);
	if (size * nmemb > 2147483647)
		return (NULL);
	calloc = (char *) malloc(nmemb * size * sizeof(char));
	if (calloc == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		calloc[i] = 0;
		i++;
	}
	return (calloc);
}
/*

  The malloc() function allocates size bytes and returns a pointer to the allocated memory.  The memory is not initialized.  If size is 0,
       then malloc() returns either NULL, or a unique pointer value that can later be successfully passed to free().

       The free() function frees the memory space pointed to by ptr, which must have been returned by a previous call to malloc(), calloc(), or
       realloc().   Otherwise, or if free(ptr) has already been called before, undefined behavior occurs.  If ptr is NULL, no operation is per‐
       formed.

       The calloc() function allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated  memory.
       The  memory  is set to zero.  If nmemb or size is 0, then calloc() returns either NULL, or a unique pointer value that can later be suc‐
       cessfully passed to free().  If the multiplication of nmemb and size would result in integer overflow, then calloc() returns  an  error.
       By  contrast,  an  integer  overflow  would not be detected in the following call to malloc(), with the result that an incorrectly sized
       block of memory would be allocated:

           malloc(nmemb * size);
*/
