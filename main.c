#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include <stddef.h>
/*
size_t strlcpy(char *dst, const char *src, size_t dstsize) {
    size_t srclen = 0;
    while (src[srclen] != '\0') srclen++;

    if (dstsize > 0) {
        size_t i;
        for (i = 0; i < dstsize - 1 && src[i] != '\0'; i++) {
            dst[i] = src[i];
        }
        dst[i] = '\0';
    }

    return srclen;
}

size_t strlcat(char *dst, const char *src, size_t dstsize) {
    size_t dstlen = 0;
    while (dstlen < dstsize && dst[dstlen] != '\0') dstlen++;
    size_t srclen = 0;
    while (src[srclen] != '\0') srclen++;

    if (dstlen == dstsize) return dstsize + srclen;

    size_t i;
    for (i = 0; i < dstsize - dstlen - 1 && src[i] != '\0'; i++) {
        dst[dstlen + i] = src[i];
    }
    dst[dstlen + i] = '\0';

    return dstlen + srclen;
}

char *strnstr(const char *haystack, const char *needle, size_t len) {
    size_t i, j;
    if (*needle == '\0') return (char *)haystack;

    for (i = 0; haystack[i] != '\0' && i < len; i++) {
        for (j = 0; needle[j] != '\0' && haystack[i + j] == needle[j] && (i + j) < len; j++);
        if (needle[j] == '\0') return (char *)(haystack + i);
    }
    return NULL;
}
*/

void	del(void *content)
{
	free(content);
}

void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *) lst->content);
		lst = lst->next;
	}
}

void	ft_ok(int n)
{
	if (n == 1)
		printf("\033[32mOK\n\033[0m");
	else
		printf("\033[31mNOK\n\033[0m");
}

int		ft_int_cmp(int n1, int n2)
{
	if (n1 == n2)
		return (1);
	else
		return (0);
}

int		ft_bool_cmp(int n1, int n2)
{
	if (n1 == 0 && n2 == 0)
		return (1);
	if (n1 != 0 && n2 != 0)
		return (1);
	else
		return (0);
}

int		ft_str_cmp(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (1);
	if ((!s1 && s2) || (!s2 && s1))
		return (0);
	if (strcmp(s1, s2) == 0)
		return (1);
	else
		return (0);
}

int		ft_ad_cmp(void *ptr1, void *ptr2)
{
	if (ptr1 == ptr2)
		return (1);
	else
		return (0);
}

int		ft_mem_cmp(void *ptr1, void *ptr2, size_t len)
{
	size_t	i;
	char	*s1;
	char	*s2;

	s1 = (char *) ptr1;
	s2 = (char *) ptr2;
	i = 0;
	while (i < len)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_memory(void *ptr, size_t len)
{
	size_t	i;
	char	*s;

	s = (char *) ptr;
	i = 0;
	while (i < len)
	{
		if (s[i] == '\0')
			printf("\033[34m0\033[0m");
		else
			printf("\033[33m%c\033[0m", s[i]);
		i++;
	}
}

char	ft_low(unsigned int i, char c)
{
	(void) i;
	return (tolower(c));
}

void	ft_lowptr(unsigned int i, char *c)
{
	(void) i;
	if (c)
		*c = tolower(*c);
}

void	ft_lowlst(void *ptr)
{
	char	*c;
	size_t	i;

	i = 0;
	c = (char *) ptr;
	while (c[i])
	{
		c[i] = toupper(c[i]);
		i++;
	}
}

void	*ft_lowlstptr(void *ptr)
{
	char	*c;
	size_t	i;

	i = 0;
	c = (char *) ptr;
	while (c[i])
	{
		c[i] = tolower(c[i]);
		i++;
	}
	return (c);
}

int		main(void)
{
//	ISALPHA
	printf("\033[33m\n********************\nft_isalpha\n\033[0m");
	char	c1;
	c1 = 'a';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isalpha(c1), ft_isalpha(c1));
	ft_ok(ft_bool_cmp(isalpha(c1), ft_isalpha(c1)));
	c1 = 'Z';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isalpha(c1), ft_isalpha(c1));
	ft_ok(ft_bool_cmp(isalpha(c1), ft_isalpha(c1)));
	c1 = '4';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isalpha(c1), ft_isalpha(c1));
	ft_ok(ft_bool_cmp(isdigit(c1), ft_isdigit(c1)));
	c1 = '#';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isalpha(c1), ft_isalpha(c1));
	ft_ok(ft_bool_cmp(isalpha(c1), ft_isalpha(c1)));

//	ISDIGIT
	printf("\033[33m\n********************\nft_isdigit\n\033[0m");
	c1 = '0';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isdigit(c1), ft_isdigit(c1));
	ft_ok(ft_bool_cmp(isdigit(c1), ft_isdigit(c1)));
	c1 = '9';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isdigit(c1), ft_isdigit(c1));
	ft_ok(ft_bool_cmp(isdigit(c1), ft_isdigit(c1)));
	c1 = 'r';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isdigit(c1), ft_isdigit(c1));
	ft_ok(ft_bool_cmp(isdigit(c1), ft_isdigit(c1)));
	c1 = '&';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isdigit(c1), ft_isdigit(c1));
	ft_ok(ft_bool_cmp(isdigit(c1), ft_isdigit(c1)));


//	ISALNUM
	printf("\033[33m\n********************\nft_isalnum\n\033[0m");
	c1 = '3';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isalnum(c1), ft_isalnum(c1));
	ft_ok(ft_bool_cmp(isalnum(c1), ft_isalnum(c1)));
	c1 = 'q';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isalnum(c1), ft_isalnum(c1));
	ft_ok(ft_bool_cmp(isalnum(c1), ft_isalnum(c1)));
	c1 = 'W';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isalnum(c1), ft_isalnum(c1));
	ft_ok(ft_bool_cmp(isalnum(c1), ft_isalnum(c1)));
	c1 = '@';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isalnum(c1), ft_isalnum(c1));
	ft_ok(ft_bool_cmp(isalnum(c1), ft_isalnum(c1)));

//	ISASCII
	printf("\033[33m\n********************\nft_isascii\n\033[0m");
	c1 = '0';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isascii(c1), ft_isascii(c1));
	ft_ok(ft_bool_cmp(isascii(c1), ft_isascii(c1)));
	c1 = 'e';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isascii(c1), ft_isascii(c1));
	ft_ok(ft_bool_cmp(isascii(c1), ft_isascii(c1)));
	c1 = '*';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isascii(c1), ft_isascii(c1));
	ft_ok(ft_bool_cmp(isascii(c1), ft_isascii(c1)));
	int n1 = 325;
	printf("Avec %d ", n1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isascii(n1), ft_isascii(n1));
	ft_ok(ft_bool_cmp(isascii(n1), ft_isascii(n1)));

//	ISPRINT
	printf("\033[33m\n********************\nft_isprint\n\033[0m");
	c1 = 'p';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isprint(c1), ft_isprint(c1));
	ft_ok(ft_bool_cmp(isprint(c1), ft_isprint(c1)));
	c1 = '\t';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isprint(c1), ft_isprint(c1));
	ft_ok(ft_bool_cmp(isprint(c1), ft_isprint(c1)));
	n1 = 31;
	printf("Avec %d ", n1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isprint(n1), ft_isprint(n1));
	ft_ok(ft_bool_cmp(isprint(n1), ft_isprint(n1)));
	n1 = 127;
	printf("Avec %d ", n1);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", isprint(n1), ft_isprint(n1));
	ft_ok(ft_bool_cmp(isprint(n1), ft_isprint(n1)));

//	STRLEN
	printf("\033[33m\n********************\nft_strlen\n\033[0m");
	char	s1[] = "Hello World!";
	printf("Avec %s ", s1);
	printf("attendu : \033[33m%zu\033[0m obtenu : \033[33m%zu\033[0m\n", strlen(s1), ft_strlen(s1));
	ft_ok(ft_int_cmp(strlen(s1), ft_strlen(s1)));
	char	s2[] = "";
	printf("Avec %s ", s2);
	printf("attendu : \033[33m%zu\033[0m obtenu : \033[33m%zu\033[0m\n", strlen(s2), ft_strlen(s2));
	ft_ok(ft_int_cmp(strlen(s2), ft_strlen(s2)));

//	MEMSET
	printf("\033[33m\n********************\nft_memset\n\033[0m");
	char	s3[] = "Hello World!";
	char	s4[] = "Hello World!";
	char	s5[] = "Hello World!";
	char	s6[] = "Hello World!";
	printf("Avec %s, 'a' et 0  ", s3);
	memset(s3, 'a', 0);
	ft_memset(s4, 'a', 0);
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", s3, s4);
	ft_ok(ft_mem_cmp(s3, s4, 12));
	printf("Avec %s, 'a' et 5  ", s5);
	memset(s5, 'a', 0);
	ft_memset(s6, 'a', 0);
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", s5, s6);
	ft_ok(ft_mem_cmp(s5, s6, 12));

//	BZERO
	printf("\033[33m\n********************\nft_bzero\n\033[0m");
	char	s8[] = "Hello World!";
	char	s9[] = "Hello World!";
	char	s10[] = "Hello World!";
	char	s11[] = "Hello World!";
	printf("Avec %s et 0 ", s8);
	bzero(s8, 0);
	ft_bzero(s9, 0);
	printf("attendu : ");
	ft_print_memory(s8, 12);
	printf(" obtenu : ");
	ft_print_memory(s9, 12);
	printf("\n");
	ft_ok(ft_mem_cmp(s8, s9, 12));
	printf("Avec %s et 5 ", s10);
	bzero(s10, 5);
	ft_bzero(s11, 5);
	printf("attendu : ");
	ft_print_memory(s10, 12);
	printf(" obtenu : ");
	ft_print_memory(s11, 12);
	printf("\n");
	ft_ok(ft_mem_cmp(s10, s11, 12));

//	MEMCPY
	printf("\033[33m\n********************\nft_memcpy\n\033[0m");
	char	s13[] = "A ecraser mais pas la fin";
	char	s14[] = "A copier ";
	char	s15[] = "A ecraser mais pas la fin";
	char	s16[] = "A copier ";
	printf("Avec %s et %s et 9 ", s13, s14);
	memcpy(s13, s14, 9);
	ft_memcpy(s15, s16, 9);
	printf("attendu : ");
	ft_print_memory(s13, 25);
	printf(" obtenu : ");
	ft_print_memory(s15, 25);
	printf("\n");
	ft_ok(ft_mem_cmp(s13, s15, 25));

//	MEMMOVE
	printf("\033[33m\n********************\nft_memmove\n\033[0m");
	char	s17[] = "1234567890";
	char	s18[] = "1234567890";
	printf("Avec la chaine \"1234567890\" en copiant 5 caracteres a partir de l indice zero sur l indice 3 ");
	memmove(&s17[3], s17, 5);
	ft_memmove(&s18[3], s18, 5);
	printf("attendu : ");
	ft_print_memory(s17, 10);
	printf(" obtenu : ");
	ft_print_memory(s18, 10);
	printf("\n");
	ft_ok(ft_mem_cmp(s17, s18, 10));

//	STRLCPY
	printf("\033[33m\n********************\nft_strlcpy\n\033[0m");
	char	s19[20];
	char	s20[20];
	char	s21[] = "a copier";
	printf("Avec %s en copiant 9 caracteres\n", s21);
	size_t	t1 = strlcpy(s19, s21, 9);
	size_t	t2 = ft_strlcpy(s20, s21, 9);
	printf("retour attendu : \033[33m%zu\033[0m obtenu : \033[33m%zu\033[0m\n", t1, t2);
	ft_ok(ft_int_cmp(t1, t2));
	printf("chaine attendue : \033[33m%s\033[0m obtenue : \033[33m%s\033[0m\n", s19, s20);
	ft_ok(ft_str_cmp(s19, s20));

//	STRLCAT
	printf("\033[33m\n********************\nft_strlcat\n\033[0m");
	char	s22[50] = "Cette phrase ";
	char	s23[50] = "Cette phrase ";
	char	s24[] = "sera complete apres concatenation";
	printf("Avec %s et %s et destsize = 50\n", s22, s24);
	t1 = strlcat(s22, s24, 50);
	t2 = ft_strlcat(s23, s24, 50);
	printf("retour attendu : \033[33m%zu\033[0m obtenu : \033[33m%zu\033[0m\n", t1, t2);
	ft_ok(ft_int_cmp(t1, t2));
	printf("chaine attendue : \033[33m%s\033[0m obtenue : \033[33m%s\033[0m\n", s22, s23);
	ft_ok(ft_str_cmp(s22, s23));
	
	char	s25[20] = "Cette phrase ";
	char	s26[20] = "Cette phrase ";
	printf("Avec %s et %s et destsize = 20\n", s25, s24);
	t1 = strlcat(s25, s24, 20);
	t2 = ft_strlcat(s26, s24, 20);
	printf("retour attendu : \033[33m%zu\033[0m obtenu : \033[33m%zu\033[0m\n", t1, t2);
	ft_ok(ft_int_cmp(t1, t2));
	printf("chaine attendue : \033[33m%s\033[0m obtenue : \033[33m%s\033[0m\n", s25, s26);
	ft_ok(ft_str_cmp(s22, s23));
	
//	TOUPPER
	printf("\033[33m\n********************\nft_toupper\n\033[0m");
	c1 = 'a';
	char	c2 = 'a';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%c\033[0m obtenu : \033[33m%c\033[0m\n", toupper(c1), ft_toupper(c2));
	ft_ok(ft_int_cmp(c1, c2));
	c1 = 'z';
	c2 = 'z';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%c\033[0m obtenu : \033[33m%c\033[0m\n", toupper(c1), ft_toupper(c2));
	ft_ok(ft_int_cmp(c1, c2));
	c1 = '5';
	c2 = '5';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%c\033[0m obtenu : \033[33m%c\033[0m\n", toupper(c1), ft_toupper(c2));
	ft_ok(ft_int_cmp(c1, c2));

//	TOLOWER
	printf("\033[33m\n********************\nft_tolower\n\033[0m");
	c1 = 'A';
	c2 = 'A';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%c\033[0m obtenu : \033[33m%c\033[0m\n", tolower(c1), ft_tolower(c2));
	ft_ok(ft_int_cmp(c1, c2));
	c1 = 'q';
	c2 = 'q';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%c\033[0m obtenu : \033[33m%c\033[0m\n", tolower(c1), ft_tolower(c2));
	ft_ok(ft_int_cmp(c1, c2));
	c1 = '3';
	c2 = '3';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%c\033[0m obtenu : \033[33m%c\033[0m\n", tolower(c1), ft_tolower(c2));
	ft_ok(ft_int_cmp(c1, c2));

//	STRCHR
	printf("\033[33m\n********************\nft_strchr\n\033[0m");
	char	s27[] = "Que cherches tu?";
	printf("Avec %s et e ", s27);
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", strchr(s27, 'e'), ft_strchr(s27, 'e'));
	ft_ok(ft_str_cmp(strchr(s27, 'e'), ft_strchr(s27, 'e')));
	char	s28[] = "Ce que tu cherches n est pas ici";
	printf("Avec %s et z ", s28);
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", strchr(s28, 'z'), ft_strchr(s28, 'z'));
	ft_ok(ft_str_cmp(strchr(s28, 'z'), ft_strchr(s28, 'z')));

//	STRRCHR
	printf("\033[33m\n********************\nft_strrchr\n\033[0m");
	printf("Avec %s et e ", s27);
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", strrchr(s27, 'e'), ft_strrchr(s27, 'e'));
	ft_ok(ft_str_cmp(strrchr(s27, 'e'), ft_strrchr(s27, 'e')));
	printf("Avec %s et e ", s28);
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", strrchr(s28, 'z'), ft_strrchr(s28, 'z'));
	ft_ok(ft_str_cmp(strrchr(s28, 'z'), ft_strrchr(s28, 'z')));

//	STRNCMP
	printf("\033[33m\n********************\nft_strncmp\n\033[0m");
	char	s29[] = "identiques au debut mais pas a la fin";
	char	s30[] = "identiques au debut, differentes a la fin";
	printf("Avec %s et %s et 19 ", s29, s30);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", strncmp(s29, s30, 19), ft_strncmp(s29, s30, 19));
	ft_ok(ft_int_cmp(strncmp(s29, s30, 19), ft_strncmp(s29, s30, 19)));
	printf("Avec %s et %s et 30 ", s29, s30);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", strncmp(s29, s30, 30), ft_strncmp(s29, s30, 30));
	ft_ok(ft_int_cmp(strncmp(s29, s30, 30), ft_strncmp(s29, s30, 30)));

//	MEMCHR
	printf("\033[33m\n********************\nft_memchr\n\033[0m");
	printf("Avec %s et t et 15 ", s27);
	printf("attendu : \033[33m%p\033[0m obtenu : \033[33m%p\033[0m\n", memchr(s27, 't', 15), ft_memchr(s27, 't', 15));
	ft_ok(ft_ad_cmp(memchr(s27, 't', 15), ft_memchr(s27, 't', 15)));
	printf("Avec %s et z et 33 ", s28);
	printf("attendu : \033[33m%p\033[0m obtenu : \033[33m%p\033[0m\n", memchr(s28, 'z', 33), ft_memchr(s28, 'z', 33));
	ft_ok(ft_ad_cmp(memchr(s28, 'z', 33), ft_memchr(s28, 'z', 33)));
	
//	MEMCMP
	printf("\033[33m\n********************\nft_memcmp\n\033[0m");
	printf("Avec %s et %s et 19 ", s29, s30);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", memcmp(s29, s30, 19), ft_memcmp(s29, s30, 19));
	ft_ok(ft_int_cmp(memcmp(s29, s30, 19), ft_memcmp(s29, s30, 19)));
	printf("Avec %s et %s et 30 ", s29, s30);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", memcmp(s29, s30, 30), ft_memcmp(s29, s30, 30));
	ft_ok(ft_int_cmp(memcmp(s29, s30, 30), ft_memcmp(s29, s30, 30)));
	char	s31[] = "";
	printf("Avec %s et %s et 30 ", s29, s31);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", memcmp(s29, s31, 30), ft_memcmp(s29, s31, 30));
	ft_ok(ft_int_cmp(memcmp(s29, s31, 30), ft_memcmp(s29, s31, 30)));

//	STRNSTR
	printf("\033[33m\n********************\nft_strnstr\n\033[0m");
	char	s32[] = "Ou est Charlie?";
	char	s33[] = "Charlie";
	printf("Avec %s et %s et 8 ", s32, s33);
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", strnstr(s32, s33, 8), ft_strnstr(s32, s33, 8));
	ft_ok(ft_str_cmp(strnstr(s32, s33, 8), ft_strnstr(s32, s33, 8)));
	printf("Avec %s et %s et 50 ", s32, s33);
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", strnstr(s32, s33, 50), ft_strnstr(s32, s33, 50));
	ft_ok(ft_str_cmp(strnstr(s32, s33, 50), ft_strnstr(s32, s33, 50)));

//	ATOI
	printf("\033[33m\n********************\nft_atoi\n\033[0m");
	char	s34[] = " \t486";
	printf("Avec %s ", s34);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", atoi(s34), ft_atoi(s34));
	ft_ok(ft_int_cmp(atoi(s34), ft_atoi(s34)));
	char	s35[] = "-2147483648";
	printf("Avec %s ", s35);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", atoi(s35), ft_atoi(s35));
	ft_ok(ft_int_cmp(atoi(s35), ft_atoi(s35)));
	char	s36[] = "-489 456";
	printf("Avec %s ", s36);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", atoi(s36), ft_atoi(s36));
	ft_ok(ft_int_cmp(atoi(s36), ft_atoi(s36)));
	char	s37[] = "+-+43";
	printf("Avec %s ", s37);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%d\033[0m\n", atoi(s37), ft_atoi(s37));
	ft_ok(ft_int_cmp(atoi(s37), ft_atoi(s37)));

//	CALLOC
	printf("\033[33m\n********************\nft_calloc\n\033[0m");
	void	*ptr1;
	void	*ptr2;
	printf("Avec 8 et 1 ");
	ptr1 = calloc(8, 1);
	ptr2 = ft_calloc(8, 1);
	printf("attendu : ");
	ft_print_memory(ptr1, 8);
	printf(" obtenu : ");
	ft_print_memory(ptr2, 8);
	printf("\n");
	ft_ok(ft_mem_cmp(ptr1, ptr2, 8));
	free(ptr1);
	free(ptr2);

//	STRDUP
	printf("\033[33m\n********************\nft_strdup\n\033[0m");
	printf("Avec %s ", s32);
	ptr1 = strdup(s32);
	ptr2 = ft_strdup(s32);
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", (char *) ptr1, (char *) ptr2);
	ft_ok(ft_str_cmp((char *) ptr1, (char *) ptr2));
	free(ptr1);
	free(ptr2);
	char	s38[] = "";
	printf("Avec %s ", s38);
	ptr1 = strdup(s38);
	ptr2 = ft_strdup(s38);
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", (char *) ptr1, (char *) ptr2);
	ft_ok(ft_str_cmp((char *) ptr1, (char *) ptr2));
	free(ptr1);
	free(ptr2);

//	SUBSTR
	printf("\033[33m\n********************\nft_substr\n\033[0m");
	char	s39[] = "il faut extraire CE MORCEAU uniquement";
	printf("Avec %s et 17 et 10 ", s39);
	ptr1 = ft_substr(s39,17, 10);
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", "CE MORCEAU", (char *) ptr1);
	ft_ok(ft_str_cmp("CE MORCEAU", (char *) ptr1));
	free(ptr1);
	printf("Avec %s et 50 et 10 ", s39);
	ptr1 = ft_substr(s39,50, 10);
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", "\0", (char *) ptr1);
	ft_ok(ft_str_cmp("", (char *) ptr1));
	free(ptr1);

//	STRJOIN
	printf("\033[33m\n********************\nft_strjoin\n\033[0m");
	char	s40[] = "ceci est le debut ";
	char	s41[] = "et cela est la fin";
	printf("Avec %s et %s ", s40, s41);
	ptr1 = ft_strjoin(s40, s41);
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", "ceci est le debut et cela est la fin", (char *) ptr1);
	ft_ok(ft_str_cmp("ceci est le debut et cela est la fin", (char *) ptr1));
	free(ptr1);

//	STRTRIM
	printf("\033[33m\n********************\nft_strtrim\n\033[0m");
	char	s42[] = "z555##zcette phrase ne veut rien dire55zzz###55zz#";
	char	s43[] = "z#5";
	printf("Avec %s et %s ", s42, s43);
	ptr1 = ft_strtrim(s42, s43);
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", "cette phrase ne veut rien dire", (char *) ptr1);
	ft_ok(ft_str_cmp("cette phrase ne veut rien dire", (char *) ptr1));
	free(ptr1);

//	SPLIT
	printf("\033[33m\n********************\nft_split\n\033[0m");
	char	s44[] = "-cette chaine -doit etre --coupee en trois chaines-";
	char	**split;
	printf("Avec %s et - \n", s44);
	split = ft_split(s44, '-');
	printf("attendu : \033[33m%s\033[0m / \033[33m%s\033[0m / \033[33m%s\033[0m /   \n", "cette chaine ", "doit etre ", "coupee en trois chaines");
	printf("obtenu : ");
	size_t	i = 0;
	while (split[i])
	{
		printf("\033[33m%s\033[0m ", split[i]);
		printf(" / ");
		i++;
	}
	printf("\n");
	printf("Nombre de chaines: ");
	ft_ok(ft_int_cmp(i, 3));
	printf("Chaine 1: ");
	ft_ok(ft_str_cmp(split[0], "cette chaine "));
	printf("Chaine 2: ");
	ft_ok(ft_str_cmp(split[1], "doit etre "));
	printf("Chaine 3: ");
	ft_ok(ft_str_cmp(split[2], "coupee en trois chaines"));
	free(split);
	
//	ITOA
	printf("\033[33m\n********************\nft_itoa\n\033[0m");
	int	n;
	n = 2147483647;
	printf("Avec %d ", n);
	ptr1 = ft_itoa(n);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%s\033[0m\n", n, (char *) ptr1);
	ft_ok(ft_str_cmp("2147483647", (char *) ptr1));
	free(ptr1);
	n = -2147483648;
	printf("Avec %d ", n);
	ptr1 = ft_itoa(n);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%s\033[0m\n", n, (char *) ptr1);
	ft_ok(ft_str_cmp("-2147483648", (char *) ptr1));
	free(ptr1);
	n = 0;
	printf("Avec %d ", n);
	ptr1 = ft_itoa(n);
	printf("attendu : \033[33m%d\033[0m obtenu : \033[33m%s\033[0m\n", n, (char *) ptr1);
	ft_ok(ft_str_cmp("0", (char *) ptr1));
	free(ptr1);

//	STRMAPI
	printf("\033[33m\n********************\nft_strmapi\n\033[0m");
	char	s45[] = "A PASSER EN MINUSCULE";
	ptr1 = ft_strmapi(s45, &ft_low);
	printf("Avec %s ", s45);
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", "a passer en minuscule", (char *) ptr1);
	ft_ok(ft_str_cmp("a passer en minuscule", (char *) ptr1));
	free(ptr1);

//	STRITERI
	printf("\033[33m\n********************\nft_striteri\n\033[0m");
	char	s46[] = "A PASSER EN MINUSCULE";
	printf("Avec %s ", s46);
	ft_striteri(s46, ft_lowptr);
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", "a passer en minuscule", s46);
	ft_ok(ft_str_cmp("a passer en minuscule", s46));

//	PUTCHAR_FD
	printf("\033[33m\n********************\nft_putchar_fd\n\033[0m");
	c1 = 'w';
	printf("Avec %c ", c1);
	printf("attendu : \033[33m%c\033[0m obtenu : \n", c1);
	ft_putchar_fd(c1, 1);
	printf("\n");
	printf("\033[33m\nft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd pas testes\n\033[0m");
	
//	PUTSTR_FD
	printf("\033[33m\n********************\nft_putstr_fd\n\033[0m");
	char	s47[] = "test de putstr";
	printf("Avec %s ", s47);
	printf("attendu : \033[33m%s\033[0m obtenu : \n", s47);
	ft_putstr_fd(s47, 1);
	printf("\n");

//	PUTENDL_FD
	printf("\033[33m\n********************\nft_putendl_fd\n\033[0m");
	char	s48[] = "test de putendl";
	printf("Avec %s ", s48);
	printf("attendu : \033[33m%s\033[0m obtenu : \n", s48);
	ft_putstr_fd(s48, 1);
	printf("\n");

//	PUTNBR_FD
	printf("\033[33m\n********************\nft_putnbr_fd\n\033[0m");
	n1 = 0;
	printf("Avec %d ", n1);
	printf("attendu : \033[33m%d\033[0m obtenu : \n", n1);
	ft_putnbr_fd(n1, 1);
	printf("\n");
	n1 = 2147483647;
	printf("Avec %d ", n1);
	printf("attendu : \033[33m%d\033[0m obtenu : \n", n1);
	ft_putnbr_fd(n1, 1);
	printf("\n");
	n1 = -2147483648;
	printf("Avec %d ", n1);
	printf("attendu : \033[33m%d\033[0m obtenu : \n", n1);
	ft_putnbr_fd(n1, 1);
	printf("\n");


//	BONUS

//	LSTNEW
	printf("\033[33m\n********************\nft_lstnew\n\033[0m");
	t_list	*lst1 = ft_lstnew(ft_strdup("element"));
	printf("Avec element ");
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", "element", (char *) lst1->content);
	ft_ok(ft_str_cmp("element", (char *) lst1->content));

//	LSTADD_FRONT
	printf("\033[33m\n********************\nft_lstadd_back\n\033[0m");
	t_list	*lst2 = ft_lstnew(ft_strdup("nouveau premier element"));
	ft_lstadd_front(&lst1, lst2);
	printf("Avec nouveau premier element ");
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", "nouveau premier element", (char *) lst1->content);
	ft_ok(ft_str_cmp("nouveau premier element", (char *) lst1->content));

//	LSTSIZE
	printf("\033[33m\n********************\nft_lstsize\n\033[0m");
	printf("Avec une liste de 2 elements ");
	printf("attendu : \033[33m2\033[0m obtenu : \033[33m%d\033[0m\n", ft_lstsize(lst1));
	ft_ok(ft_int_cmp(2, ft_lstsize(lst1)));

//	LSTLAST
	printf("\033[33m\n********************\nft_lstlast\n\033[0m");
	printf("Avec la liste precedente ");
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", "element", (char *) ft_lstlast(lst1)->content);
	ft_ok(ft_str_cmp("element", (char *) ft_lstlast(lst1)->content));

//	LSTADD_BACK
	printf("\033[33m\n********************\nft_lstadd_back\n\033[0m");
	printf("Avec dernier element ");
	t_list	*lst3 = ft_lstnew(ft_strdup("dernier element"));
	ft_lstadd_back(&lst1, lst3);
	t_list	*last = lst1;
	while (last && last->next)
		last = last->next;
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", "dernier element", (char *) last->content);
	ft_ok(ft_str_cmp("dernier element", (char *) last->content));
/*
//	LSTADELONE
	printf("\033[33m\n********************\nft_lstdelone\n\033[0m");
	printf("En supprimant le dernier element ajoute: ");
	ft_lstdelone(lst3, &del);
	last = lst1;
	while (last && last->next)
		last = last->next;
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", "element", (char *) lst3->content);
	ft_ok(ft_str_cmp("element", (char *) last->content));
*/
//	LSTITER
	printf("\033[33m\n********************\nft_lstiter\n\033[0m");
	printf("En passant la liste en majuscule ");
	ft_lstiter(lst1, &ft_lowlst);
	last = lst1;
	while (last && last->next)
		last = last->next;
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", "DERNIER ELEMENT", (char *) last->content);
	ft_ok(ft_str_cmp("DERNIER ELEMENT", (char *) last->content));

//	LSTMAP
	printf("\033[33m\n********************\nft_lstmap\n\033[0m");
	printf("En creant une nouvelle liste en minuscule ");
	t_list	*map;
	map = ft_lstmap(lst1, &ft_lowlstptr, &del);
	last = map;
	while (last && last->next)
		last = last->next;
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", "dernier element", (char *) last->content);
	ft_ok(ft_str_cmp("dernier element", (char *) last->content));




/*
//	LSTCLEAR
	printf("\033[33m\n********************\nft_lstclear\n\033[0m");
	ft_lstclear(&lst1, del);
	printf("En supprimant la liste ");
	printf("attendu : \033[33m%s\033[0m obtenu : \033[33m%s\033[0m\n", "(null)", (char *) lst1);
	ft_ok(ft_str_cmp(NULL, (char *) lst1));
*/


	ft_print_list(lst1);
}
