/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:22:44 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/05 11:39:18 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(little) == 0)
		return ((char *) big);
	j = 0;
	while (big[j] && j < len)
	{
		i = 0;
		while (big[i + j] == little[i] && little[i] && i + j < len)
			i++;
		if (little[i] == '\0')
			return ((char *) &big[j]);
		j++;
	}
	return (NULL);
}
