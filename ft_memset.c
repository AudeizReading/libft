#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p_b;
	unsigned char	cc;

	p_b = b;
	cc = c;
	if (!len)
		return ((void *)0);
	while (len--)
		*p_b++ = cc;
	return (b);
}
