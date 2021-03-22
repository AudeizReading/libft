#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	c;

	c = n;
	if (c < 0)
	{
		ft_putchar_fd('-', fd);
		c = -c;
	}
	if (c >= 10)
		ft_putnbr_fd(c / 10, fd);
	ft_putchar_fd(c % 10 + '0', fd);
}
