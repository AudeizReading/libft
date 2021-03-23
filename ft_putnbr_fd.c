/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 08:34:22 by alellouc          #+#    #+#             */
/*   Updated: 2021/03/23 08:34:53 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
