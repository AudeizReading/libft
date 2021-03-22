#include "libft.h"

int	ft_tolower(int c)
{
	int letter;

	if (c >= 'A' && c <= 'Z')
		letter = c + 32;
	return (letter);
}
