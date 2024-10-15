#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = (char *) dst;
	s = (const char *) src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char) c)
			return ((void *) &d[i + 1]);
		i++;
	}
	return (NULL);
}
