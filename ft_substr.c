/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:01:57 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/07 09:56:45 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;
	size_t	cpy_len;

	if (start >= ft_strlen(s))
	{
		cpy = (char *) malloc(sizeof(char));
		cpy[0] = '\0';
		return (cpy);
	}
	if (ft_strlen(s) - start < len)
		cpy_len = ft_strlen(s) - start;
	else
		cpy_len = len;
	cpy = (char *) malloc((cpy_len + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		cpy[i] = s[i + start];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
