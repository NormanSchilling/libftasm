/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 16:47:26 by nschilli          #+#    #+#             */
/*   Updated: 2015/02/13 14:36:22 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	ft_bzero(void *s, size_t n);
char*	ft_strcat(char * s1, const char * s2);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_puts(const char *s);
int		ft_strlen(char *s);
void*	ft_memcpy(void *s1, const void *s2, size_t n);
void*	ft_memset(void *b, int c, size_t len);
char*	ft_strdup(const char *s1);
void	ft_cat(int fd);


void*	ft_memchr(const void *s, int c, size_t n);
char*	ft_strchr(const char *s, int c);
char*	ft_strncat(char * s1, const char * s2, size_t n);
int		ft_islower(int c);
int		ft_isupper(int c);