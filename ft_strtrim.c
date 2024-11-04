/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:27:58 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/04 13:28:13 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_white_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static size_t	ft_trim_len(const char *s)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s);
	if (len == 0)
		return (0);
	i = 0;
	while (ft_is_white_space(s[i]))
		i++;
	if (i == len)
		return (0);
	j = 0;
	while (ft_is_white_space(s[len - j - 1]) && (len - j) > 0)
		j++;
	return (len - i - j);
}

char	*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	len;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	len = ft_trim_len(s);
	trim = (char *) malloc((len + 1) * sizeof(char));
	if (trim == NULL)
		return (NULL);
	i = 0;
	while (ft_is_white_space(s[i]))
		i++;
	j = 0;
	while (j < len)
	{
		trim[j] = s[i + j];
		j++;
	}
	trim[j] = '\0';
	return (trim);
}
