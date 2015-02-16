/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 14:10:36 by nschilli          #+#    #+#             */
/*   Updated: 2015/02/13 14:35:48 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libfts.h"

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <assert.h>

void	test_isdigit(void);
void	test_isalpha(void);
void	test_isalnum(void);
void	test_isascii(void);
void	test_isprint(void);
void	test_bzero(void);
void	test_toupper(void);
void	test_tolower(void);
void	test_puts(void);
void	test_strlen(void);
void	test_memcpy(void);
void	test_memset(void);
void	test_strdup(void);
void	test_cat(int argc, char **argv);

void	test_memchr(void);
void	test_strchr(void);
void	test_strncat(void);
void	test_islower(void);
void	test_isupper(void);

int  cat(int fd)
{
    char    buf[1020];
    int     ret;

    while (1)
    {
        if ((ret = read(fd, buf, 1020)) < 1)
            return (-1);
        if (write(1, buf, ret) < 1)
            return (-1);
    }
    return (0);
}


void	test_isdigit(void)
{
	printf("is digit [digit]: %d\n", ft_isdigit('5'));
	printf("is digit [alpha]: %d\n", ft_isdigit('a'));
}

void	test_isalpha(void)
{
	printf("is alpha [digit]: %d\n", ft_isalpha('5'));
	printf("is alpha [alpha]: %d\n", ft_isalpha('Z'));
}

void	test_isalnum(void)
{
	printf("is alnum [digit] : %d\n", ft_isalnum('5') );
	printf("is alnum [alpha] : %d\n", ft_isalnum('a') );
	printf("is alnum [special] : %d\n", ft_isalnum('-') );
}

void	test_isascii(void)
{
	printf("is ascii [digit] : %d\n", ft_isascii('5') );
	printf("is ascii [alpha] : %d\n", ft_isascii('Z') );
	printf("is ascii [special] : %d\n", ft_isascii('*') );
}

void	test_isprint(void)
{
	printf("is print [digit] : %d\n", ft_isprint('5') );
	printf("is print [alpha] : %d\n", ft_isprint('Z') );
	printf("is print [special] : %d\n", ft_isprint('*') );
	printf("is print [noprint] : %d\n", ft_isprint('\0') );
}

void	test_bzero(void)
{
	size_t	i;
	size_t	n;
	char *s = strdup("bonjour");

	n = ft_strlen(s);

	ft_bzero((void *)s, n);
	i = 0;
	while (i < n)
	{
		s[i] = s[i] + 48;
		i++;
	}
	printf("bzero : %s\n", s);
}

void	test_toupper(void)
{
	printf("toupper [digit] : %c\n", ft_toupper('5') );
	printf("toupper [alpha_min] : %c\n", ft_toupper('z') );
	printf("toupper [alpha_min] : %c\n", ft_toupper('l') );
	printf("toupper [alpha_min] : %c\n", ft_toupper('a') );
	printf("toupper [alpha_maj] : %c\n", ft_toupper('K') );
	printf("toupper [special] : %c\n", ft_toupper('+') );
	printf("toupper [noprint] : %c\n", ft_toupper('\0') );
}	

void	test_tolower(void)
{
	printf("tolower [digit] : %c\n", ft_tolower('5') );
	printf("tolower [alpha_maj] : %c\n", ft_tolower('Z') );
	printf("tolower [alpha_maj] : %c\n", ft_tolower('D') );
	printf("tolower [alpha_maj] : %c\n", ft_tolower('A') );
	printf("tolower [alpha_in] : %c\n", ft_tolower('k') );
	printf("tolower [special] : %c\n", ft_tolower('+') );
	printf("tolower [noprint] : %c\n", ft_tolower('\0') );
}	

void	test_puts(void)
{
	ft_puts("puts : bonjour");
	ft_puts(0);
}

void	test_strcat(void)
{
	char *s = ft_strdup("lol");

	printf("strcat : %s\n", ft_strcat(s, "bonjour"));
}

void	test_strlen(void)
{
	printf("strlen : %d\n", ft_strlen("lol") );
	printf("strlen : %d\n", ft_strlen("154jkndsjknsdjsfj") );
	printf("strlen : %d\n", ft_strlen("bonjour") );
}

void	test_memcpy(void)
{
	char *s = ft_strdup("lol");
	char *s2 = ft_strdup("bonjour");

	printf("memcpy : %s\n", (char*)(ft_memcpy( (void*)s, (void*)s2, 5)) );
}

void	test_memset(void)
{
	char *s = ft_strdup("lol");
	char c = 'a';
	printf("memset : %s\n", (char*)(ft_memset( (void*)s, c, 5)) );
}

void	test_strdup(void)
{
	char *s = ft_strdup("parfait");

	printf("strdup : %s\n", s);
}

void	test_cat(int argc, char **argv)
{
	int fd;

	fd = 0;
	if (argc > 1)
		fd = open (argv[1], O_RDONLY);

	printf("FD = %d\n", fd);

	ft_cat(fd);
	ft_cat(72682);

	close(fd);


	fd = open ("mytest", O_RDONLY);
	ft_cat(fd);

	close(fd);
}

void	test_memchr(void)
{
	int			i;
	char*		str = ft_strdup("bonjour");

	int			to_find;

	void		*res1;
	void		*res2;

	to_find = 'j';
	res1 = memchr(str, to_find, 7);
	res2 = ft_memchr(str, to_find, 7);
	printf("memchr [res1]: %s\n", (char*)res1);
	printf("memchr [res2]: %s\n", (char*)res2);
}

void	test_strchr(void)
{
	int		i;
	char	*str = ft_strdup("bonjour");

	int		to_find;
	char	*ret;

	char	*res1;
	char	*res2;

	to_find = 'n';
	str[2-1] = 0;
	res1 = strchr(str, to_find);
	res2 = ft_strchr(str, to_find);

	printf("strchr [res1]: %s\n", res1);
	printf("strchr [res2]: %s\n", res2);
}

void	test_strncat(void)
{
	char *s = ft_strdup("lol");

	printf("strncat : %s\n", ft_strncat(s, "bonjour", 5));
}

void	test_islower(void)
{
	printf("islower [digit] : %d\n", ft_islower('5') );
	printf("islower [alpha_maj] : %d\n", ft_islower('Z') );
	printf("islower [alpha_maj] : %d\n", ft_islower('D') );
	printf("islower [alpha_maj] : %d\n", ft_islower('A') );
	printf("islower [alpha_min] : %d\n", ft_islower('a') );
	printf("islower [alpha_min] : %d\n", ft_islower('k') );
	printf("islower [alpha_min] : %d\n", ft_islower('z') );
	printf("islower [special] : %d\n", ft_islower('+') );
	printf("islower [noprint] : %d\n", ft_islower('\0') );
}

void	test_isupper(void)
{
	printf("isupper [digit] : %d\n", ft_isupper('5') );
	printf("isupper [alpha_maj] : %d\n", ft_isupper('Z') );
	printf("isupper [alpha_maj] : %d\n", ft_isupper('D') );
	printf("isupper [alpha_maj] : %d\n", ft_isupper('A') );
	printf("isupper [alpha_min] : %d\n", ft_isupper('a') );
	printf("isupper [alpha_min] : %d\n", ft_isupper('k') );
	printf("isupper [alpha_min] : %d\n", ft_isupper('z') );
	printf("isupper [special] : %d\n", ft_isupper('+') );
	printf("isupper [noprint] : %d\n", ft_isupper('\0') );
}

int		main ( int argc, char **argv )
{
	test_bzero();
	test_isdigit();
	test_isalpha();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_toupper();
	test_tolower();
	test_puts();
	test_strcat();

	test_strlen();
	test_memcpy();
	test_memset();
	test_strdup();

	test_memchr();
	test_strchr();
	test_strncat();
	test_islower();
	test_isupper();

	test_cat(argc, argv);

	return 0;
}
