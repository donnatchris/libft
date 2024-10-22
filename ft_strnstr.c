#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(needle) == 0)
		return ((char *) haystack);
	j = 0;
	while (haystack[j] && j < len)
	{
		i = 0;
		while (haystack[i + j] == needle[i] && needle[i] && i + j < len)
			i++;
		if (needle[i] == '\0')
			return ((char *) &haystack[j]);
		j++;
	}
	return (NULL);
}
