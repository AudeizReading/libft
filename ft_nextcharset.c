/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextcharset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:26:30 by alellouc          #+#    #+#             */
/*   Updated: 2021/04/11 14:03:34 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nextcharset(char const **s, char const *c, int nb)
{
	if (nb > 1)
		while (!ft_ischarset(**s, c))
			(*s)++;
}
