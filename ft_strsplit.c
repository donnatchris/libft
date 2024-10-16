#include "libft.h"

int	ft_is_split(char c1, char c2)
{
	return (c1 == c2);
}

int	ft_word_count(char const *s, char c)
{
	size_t	i;
	int		count;
	int		in_word;

	count = 0;
	i = 0;
	in_word = 0;
	while (s[i])
	{
		if (ft_is_split(s[i], c))
			in_word = 0;
		else
		{
			if (in_word == 0)
			{
				count++;
				in_word = 1;
			}
		}
		i++;
	}
	return (count);
}

void	ft_free_split(char **str_split, int words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		free(str_split[i]);
		i++;
	}
	free(str_split);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**str_split;
	int		words;
	size_t	i;
	size_t	j;
	size_t	backup_i;

	if (s == NULL)
		return (NULL);
	words = ft_word_count(s, c);
	str_split = malloc((words + 1) * sizeof(char *));
	if (str_split == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < words)
	{
		while (ft_is_split(s[i], c))
			i++;
		backup_i = i;
		while (!ft_is_split(s[i], c) && s[i])
			i++;
		str_split[j] = ft_strsub(s, (unsigned int) backup_i, i - backup_i);
		if (str_split[j] == NULL)
		{
			ft_free_split(str_split, j);
			return (NULL);
		}
		j++;
	}
	str_split[j] = NULL;
	return (str_split);
}
