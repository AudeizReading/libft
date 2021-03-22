/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:41:48 by alellouc          #+#    #+#             */
/*   Updated: 2021/03/22 16:08:35 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_toupper(int c);
int	ft_tolower(int c);
/*void	*ft_memset(void *b, int c, size_t len);
void	bzero(void *s, size_t n);
void	*memcpy(void *dst, const void *src, size_t n);
void	*memccpy(void *dst, const void *src, int c, size_t n);
void	*memmove(void *dst, const void *src, size_t len);
void	*memchr(const void *s, int c, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);*/
char	*ft_join(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr(int n, int fd);
#endif
