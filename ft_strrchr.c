/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:29:53 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/04 12:30:32 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	i = ft_strlen(s);
	uc = (unsigned char) c;
	while (i > 0)
	{
		if ((unsigned char) s[i] == uc)
			return ((char *) &s[i]);
		i--;
	}
	if ((unsigned char) s[0] == uc)
		return ((char *) &s[0]);
	return (NULL);
}
