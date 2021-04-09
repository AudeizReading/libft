/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntwds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:18:21 by alellouc          #+#    #+#             */
/*   Updated: 2021/04/09 22:39:51 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cntwds(char *str, int sep)
{
	int		nb;
	int		state;
	char	c_sep;

	enum e_state
	{
		OUTSIDE_WD,
		INSIDE_WD
	};
	nb = 0;
	c_sep = (char)sep;
	state = OUTSIDE_WD;
	while (*str)
	{
		if (ft_ischarset(*str, &c_sep))
			state = OUTSIDE_WD;
		else if (state == OUTSIDE_WD)
		{
			state = INSIDE_WD;
			nb++;
		}
		str++;
	}
	return (nb);
}
