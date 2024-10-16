#include "libft.h"

void	ft_putchar(int c)
{
	char	ch;

	ch = (char) c;
	write(1, &ch, 1);
}
