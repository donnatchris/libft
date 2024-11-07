/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:01:57 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/07 11:24:26 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cpy_len(char const *s, unsigned int start, size_t len)
{
	size_t	cpy_len;

	if (start + len > ft_strlen(s))
		cpy_len = ft_strlen(s) - start;
	else
		cpy_len = len;
	return (cpy_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;
	size_t	cpy_len;

	if (start >= ft_strlen(s))
	{
		cpy = (char *) malloc(sizeof(char));
		if (cpy == NULL)
			return (NULL);
		cpy[0] = '\0';
		return (cpy);
	}
	cpy_len = ft_cpy_len(s, start, len);
	cpy = (char *) malloc((cpy_len + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (i < cpy_len)
	{
		cpy[i] = s[i + start];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
