#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		backup_n;
	int		sign;
	size_t	str_len;
	size_t	i;

	sign = 0;
	if (n < 0)
		sign = 1;
	backup_n = n;
	str_len = 1;
	while (backup_n > 9)
	{
		backup_n = backup_n / 10;
		str_len++;
	}
	str = malloc((str_len + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		
		i++;
	}

}
