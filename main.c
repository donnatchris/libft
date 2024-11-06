/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:50:11 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/06 12:07:10 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void	ft_new(void)
{
	printf("\n\n");
}

void	ft_test_size_t(size_t attended, size_t result)
{
	if (attended == result)
		printf("\033[32mOK  \033[0m");
	else
		printf("\033[31mNOK \033[0m");
}

void	ft_test_int(int attended, int result)
{
	if (attended == result)
		printf("\033[32mOK  \033[0m");
	else
		printf("\033[31mNOK \033[0m");
}

int	main(void)
{
	int		(*f_int)(int);
	char	*s1 = "Hello World!";
	char	*s2 = "Salut les loulous...";
	char	*s3 = "9";
	char	*s4 = "";
	char	c;
	int		n;
	int		res_int;
	size_t	res_size_t;

//	ISALPHA
	f_int = ft_isalpha;
	ft_new();
	printf("\033[33mISALPHA*************\033[0m\n");
	c = 'a';
	res_int = f_int(c);
	ft_test_int(1, res_int);
	printf("avec \033[33m%c\033[0m attendu 1 / resultat du test %d\n", c, res_int);
	c = 'Z';
	res_int = f_int(c);
	ft_test_int(1, res_int);
	printf("avec \033[33m%c\033[0m attendu 1 / resultat du test %d\n", c, res_int);
	c = '1';
	res_int = f_int(c);
	ft_test_int(0, res_int);
	printf("avec \033[33m%c\033[0m attendu 0 / resultat du test %d\n", c, res_int);
	c = '%';
	res_int = f_int(c);
	ft_test_int(0, res_int);
	printf("avec \033[33m%c\033[0m attendu 0 / resultat du test %d\n", c, res_int);

//	ISDIGIT
	f_int = ft_isdigit;
	ft_new();
	printf("\033[33mISDIGIT*************\033[0m\n");
	c = 'a';
	res_int = f_int(c);
	ft_test_int(0, res_int);
	printf("avec \033[33m%c\033[0m attendu 0 / resultat du test %d\n", c, res_int);
	c = 'Z';
	res_int = f_int(c);
	ft_test_int(0, res_int);
	printf("avec \033[33m%c\033[0m attendu 0 / resultat du test %d\n", c, res_int);
	c = '1';
	res_int = f_int(c);
	ft_test_int(1, res_int);
	printf("avec \033[33m%c\033[0m attendu 1 / resultat du test %d\n", c, res_int);
	c = '%';
	res_int = f_int(c);
	ft_test_int(0, res_int);
	printf("avec \033[33m%c\033[0m attendu 0 / resultat du test %d\n", c, res_int);

//	ISALNUM
	f_int = ft_isalnum;
	ft_new();
	printf("\033[33mISALNUM*************\033[0m\n");
	c = 'a';
	res_int = f_int(c);
	ft_test_int(1, res_int);
	printf("avec \033[33m%c\033[0m attendu 1 / resultat du test %d\n", c, res_int);
	c = 'Z';
	res_int = f_int(c);
	ft_test_int(1, res_int);
	printf("avec \033[33m%c\033[0m attendu 1 / resultat du test %d\n", c, res_int);
	c = '1';
	res_int = f_int(c);
	ft_test_int(1, res_int);
	printf("avec \033[33m%c\033[0m attendu 1 / resultat du test %d\n", c, res_int);
	c = '%';
	res_int = f_int(c);
	ft_test_int(0, res_int);
	printf("avec \033[33m%c\033[0m attendu 0 / resultat du test %d\n", c, res_int);

//	ISASCII
	f_int = ft_isascii;
	ft_new();
	printf("\033[33mISASCII*************\033[0m\n");
	n = 0;
	res_int = f_int(n);
	ft_test_int(1, res_int);
	printf("avec \033[33m%d\033[0m attendu 1 / resultat du test %d\n", n, res_int);
	n = 127;
	res_int = f_int(n);
	ft_test_int(1, res_int);
	printf("avec \033[33m%d\033[0m attendu 1 / resultat du test %d\n", n, res_int);
	n = 128;
	res_int = f_int(n);
	ft_test_int(0, res_int);
	printf("avec \033[33m%d\033[0m attendu 0 / resultat du test %d\n", n, res_int);
	n = -1;
	res_int = f_int(n);
	ft_test_int(0, res_int);
	printf("avec \033[33m%d\033[0m attendu 0 / resultat du test %d\n", n, res_int);

//	ISPRINT
	f_int = ft_isprint;
	ft_new();
	printf("\033[33mISPRINT*************\033[0m\n");
	n = 32;
	res_int = f_int(n);
	ft_test_int(1, res_int);
	printf("avec \033[33m%d\033[0m attendu 1 / resultat du test %d\n", n, res_int);
	n = 126;
	res_int = f_int(n);
	ft_test_int(1, res_int);
	printf("avec \033[33m%d\033[0m attendu 1 / resultat du test %d\n", n, res_int);
	n = 31;
	res_int = f_int(n);
	ft_test_int(0, res_int);
	printf("avec \033[33m%d\033[0m attendu 0 / resultat du test %d\n", n, res_int);
	n = 127;
	res_int = f_int(n);
	ft_test_int(0, res_int);
	printf("avec \033[33m%d\033[0m attendu 0 / resultat du test %d\n", n, res_int);

//	STRLEN
	ft_new();
	printf("\033[33mSTRLEN*************\033[0m\n");
	res_size_t = ft_strlen(s1);
	ft_test_size_t(strlen(s1), res_size_t);
	printf("avec \033[33m%s\033[0m attendu %lu / resultat du test %lu\n", s1, strlen(s1), res_size_t);
	res_size_t = ft_strlen(s2);
	ft_test_size_t(strlen(s2), res_size_t);
	printf("avec \033[33m%s\033[0m attendu %lu / resultat du test %lu\n", s2, strlen(s2), res_size_t);
	res_size_t = ft_strlen(s3);
	ft_test_size_t(strlen(s3), res_size_t);
	printf("avec \033[33m%s\033[0m attendu %lu / resultat du test %lu\n", s3, strlen(s3), res_size_t);
	res_size_t = ft_strlen(s4);
	ft_test_size_t(strlen(s4), res_size_t);
	printf("avec \033[33m%s\033[0m attendu %lu / resultat du test %lu\n", s4, strlen(s4), res_size_t);

//	MEMCPY
	printf("\033[33mMEMCPY*************\033[0m\n");

	

	return (1);
}
