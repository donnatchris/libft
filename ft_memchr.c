#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*src;

	src = (const unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (src[i] == (unsigned char) c)
			return ((void *) &src[i]);
		i++;
	}
	return (NULL);
}
