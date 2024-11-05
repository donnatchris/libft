/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:51:12 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/05 14:44:07 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*calloc;
	size_t	i;
	size_t	total;

	total = nmemb * size;
	if (total / nmemb != size)
		return (NULL);
	calloc = (char *) malloc(nmemb * size);
	if (calloc == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		calloc[i] = 0;
		i++;
	}
	return ((void *) calloc);
}
