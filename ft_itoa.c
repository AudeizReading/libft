/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 22:28:41 by alellouc          #+#    #+#             */
/*   Updated: 2021/04/02 22:18:22 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static int	ft_isneg(int n)
{
	if ((long int)n < 0)
		return (1);
	return (0);
}*/

char	*ft_itoa(int n)
{
	size_t		len;
	char		*itoa;
	long int	c;

	c = n;
	len = ft_intlen(c);
	if (ft_isneg(c))
		len++;
	itoa = (char *)malloc((len + 1) * sizeof(*itoa));
	if (itoa == NULL)
		return (NULL);
	itoa[len] = 0;
	if (ft_isneg(c))
	{
		itoa[0] = '-';
		c = -c;
	}
	if (c == 0)
		itoa[len - 1] = '0';
	while (len-- && c > 0)
	{
		itoa[len] = c % 10 + '0' ;
		c /= 10;
	}
	return (itoa);
}
