/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:27:37 by aybouras          #+#    #+#             */
/*   Updated: 2020/01/16 15:36:26 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);
char	*ft_strstr(const char *haystack, const char *needle);
int		ft_atoi(const char *str);
int		ft_isspace(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memset(void *b, int c, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
int		ft_strdel(char **as);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_isdigit(int c);
void	ft_putstr(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *s1, const char *s2);
int		is_number(char *str);

#endif
