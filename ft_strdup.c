#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*dup;

	dup = (char *) malloc (sizeof(*dup) * (ft_strlen(s1) + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
