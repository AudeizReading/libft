/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 09:51:26 by alellouc          #+#    #+#             */
/*   Updated: 2021/03/27 20:13:48 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			sign;
	int			minus;
	long int	atoi;

	sign = 1;
	minus = 0;
	atoi = 0;
	while (ft_isspace(*nptr))
		nptr++;
	while (*nptr == 45)
	{
		nptr++;
		minus++;
		sign = -1;
	}
	if (minus > 1)
		return (0);
	while (ft_isdigit(*nptr))
	{
		atoi = atoi * 10 + *nptr - '0';
		nptr++;
	}
	atoi *= sign;
	return ((int)atoi);
}
