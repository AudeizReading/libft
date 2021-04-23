/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:27:54 by alellouc          #+#    #+#             */
/*   Updated: 2021/04/23 23:33:05 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static int	ft_wdscnt(char const *s, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			nb++;
		i++;
	}
	return (nb);
}*/

/*static int	ft_wdlen(int *offset_i, int *offset_s, char const *s, char c)
{
	static int	i = 0;

	if ((size_t)i > (ft_strlen(s) - 2))
		i = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		if (s[i - 1] == c || i - 1 < 0)
			*offset_i = i;
		if (s[i + 1] == c || s[i + 1] == 0)
			*offset_s = i;
		i++;
	}
	while (s[i] == c)
		i++;
	return (*offset_s - *offset_i + 1);
}*/

static int	ft_isfree(char **tab, int index)
{
	if (!tab[index])
	{
		while (--index >= 0)
			free(tab[index]);
		free(tab);
		return (1);
	}
	return (0);
}

/*char	**ft_split(char const *s, char c)
{
	char **dst;
	int i;
	int offset_i;
	int offset_s;
	int nb;

	if (!s)
		return (NULL);
	i = 0;
	offset_i = 0;
	offset_s = 0;
	nb = ft_wdscnt(s, c);
	dst = (char **)ft_calloc(sizeof(*dst), (nb + 1));
	if (!dst)
		return (NULL);
	while (i < nb)
	{
		dst[i] = (char *)ft_calloc(sizeof(**dst), (ft_wdlen(&offset_i, &offset_s, s, c) + 1));
		if (ft_isfree(dst, i))
			return (NULL);
		ft_memmove(dst[i++], s + offset_i, offset_s - offset_i + 1);
	}
	return (dst);
}*/
/*static int    is_delimiter(char c, char sep)
{
    if (c == sep)
        return (1);
    return (0);
}*/

/*static void    libere(char **str, int i)
{
    while (--i > -1)
        free(str[i]);
    free(str);
}

static int    words_count(char const *s, char sep, int *x, int *y)
{
    int    i;
    int    count;

    i = 0;
    count = 0;
    *x = -1;
    *y = 0;
    while (s[i])
    {
        if (!is_delimiter(s[i], sep))
        {
            while (s[i] && !is_delimiter(s[i], sep))
                i++;
            count++;
        }
        while (s[i] && is_delimiter(s[i], sep))
            i++;
    }
    return (count);
}*/

/*static char    *ft_strdup_custom(char const *s, char c, int *j)
{
    int        i;
    int        k;
    char    *st;

    i = 0;
    k = 0;
    while (!is_delimiter(s[i], c) && s[i])
        i++;
    st = (char *)ft_calloc(i + 1, sizeof(char));
    if (!st)
        return (NULL);
    while (k < i)
    {
        st[k] = s[k];
        k++;
    }
    st[k] = '\0';
    while (is_delimiter(s[i], c) && s[i])
        i++;
    *j += i;
    return (st);
}*/

/*static char    *ft_strdup_custom(char const *s, char c, int *j)*/
static char    *ft_slice(char const *s, char c, int *j)
{
    int        i;
    char    *dst;

    i = 0;
    while (s[i] && s[i] != c)
        i++;
    dst = ft_substr(s, 0, i);
    if (!dst)
        return (NULL);
    while (s[i] && s[i] == c)
        i++;
    *j += i;
    return (dst);
}


/*char    **ft_split(char const *s, char c)
{
    char    **str;
    int        count;
    int        i;
    int        j;

    if (!s)
        return (0);
    count = words_count(s, c, &i, &j);
    str = (char **)ft_calloc(count + 1, sizeof(char *));
    if (!str)
        return (NULL);
    while (is_delimiter(s[j], c) && s[j])
        j++;
    while (++i < count && s[j])
    {
        str[i] = ft_strdup_custom(&s[j], c, &j);
        if (!str[i])
        {
            libere(str, i);
            return (NULL);
        }
    }
    str[i] = 0;
    return (str);
}*/

char    **ft_split(char const *s, char c)
{
    char    **dst;
    int        nb;
    int        i;
    int        j;

    if (!s)
        return (0);
    i = -1;
    j = 0;
    nb = ft_cntwds((char *)s, (char)c);
    /*nb = ft_wdscnt(s, c);*/
    dst = (char **)ft_calloc(nb + 1, sizeof(char *));
    if (!dst)
        return (NULL);
    while (s[j] && s[j] == c)
        j++;
    while (++i < nb)
    {
        dst[i] = ft_slice((s + j), c, &j);
        if (ft_isfree(dst, i))
            return (NULL);
    }
    return (dst);
}

/*static char *ft_strtotab(char **tab, int i, char const *s, char c)
{
    tab[i] = ft_strshift(s, (char const *)&c);
    if (!tab[i])
    {
        while (--i >= 0)
            free(tab[i]);
        free(tab);
        return (NULL);
    }
    return (*(tab + i));
}

char    **ft_split(char const *s, char c)
{
    char    **tab;
    int     nb_wds;
    int     i;

    i = 0;
    if (!s)
        return (NULL);
    nb_wds = ft_cntwds((char *)s, (char)c);
    tab = (char **)ft_calloc(nb_wds + 1, sizeof(*tab));
    if (!tab)
        return (NULL);
    ft_nextstr(&s, (char const *)&c, nb_wds);
    while (i < nb_wds)
    {
        tab[i] = ft_strtotab(tab, i, s, c);
        if (tab[i] == NULL)
            return (NULL);
        ft_nextcharset(&s, (char const *)&c, nb_wds);
        ft_nextstr(&s, (char const *)&c, nb_wds);
        i++;
    }
    tab[i] = NULL;
    return (tab);
}*/

/*int		main(void)
{
	char	**tab;
	char	*str = "U_N_D_E_U_X_T_R_O_I_S_";
	char	sep = '_';
	int		nb_wds = ft_wdscnt(str, sep);
	int		i = 0;

	tab = ft_split(str, sep);
	while (i < nb_wds)
		ft_putendl_fd(tab[i++], 1);
	if (tab[i] == NULL)
		ft_putendl_fd("tab[i] = NULL", 1);
	while (--i >= 0)
		free(tab[i]);
	free(tab);
	return (0);
}*/
/*#include <stdio.h>
void  test(void)
{
	char	*s = "U_N_D_E_U_X_T_R_O_I_S";
	char	c = '_';
	int		nb_w = 0;
	char	**split = ft_split(s, c);
	while (split[nb_w])
	{
		printf("%s\n", split[nb_w]);
		free(split[nb_w++]);
	}
	free(split);
}
int main(void)
{
	test();
	return (0);
}*/
