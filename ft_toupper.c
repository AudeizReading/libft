#include "libft.h"

int	ft_toupper(int c)
{
	int	letter;

	if (c >= 'a' && c <= 'z')
		letter = c - 32;
	return (letter);
}
