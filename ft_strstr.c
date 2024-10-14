#include "libft.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	if (ft_strlen(needle) == 0)
		return ((char *) haystack);
	while (*haystack)
	{
		i = 0;
		while (haystack[i] == needle[i] && needle[i])
			i++;
		if (needle[i] == '\0')
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}
