#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *) malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memset(str, '\0', size + 1);
	return (str);
}
