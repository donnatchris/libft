#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*******************************************************************************
PRINT AND WRITE FUNCTIONS
*******************************************************************************/

void	ft_putchar(int c);
//	Prints the character c to the standard output.

void	ft_putstr(char const *s);
//	Prints the string s to the standard output.

void	ft_putendl(char const *s);
//	Prints the string s followed by '\n' to the standard output.

void	ft_putnbr(int n);
//	Prints the integer n to the standard output.

void	ft_putchar_fd(char c, int fd);
//	Writes the character c to the file descriptor fd.

void	ft_putstr_fd(char const *s, int fd);
//	Writes the string s to the file descriptor fd.

void	ft_putendl_fd(char const *s, int fd);
//	Writes the string s followed by '\n' to the file descriptor fd.

void	ft_putnbr_fd(int n, int fd);
//	Writes the integer n to the fils descriptor fd.

/*******************************************************************************
CHARACTER MANIPULATION FUNCTIONS
*******************************************************************************/

int		ft_isalpha(int c);
//	Tests if c character is a letter (the value of the argument must be
//		representable as an unsigned char or the value of EOF),
//		which is any character between 65 and 90 or 97 and 122.
//	-> Returns zero if the character tests false
//		and returns non-zero if the character tests true.

int		ft_isdigit(int c);
//	Tests for a decimal digit character (the value of the argument must be
//		representable as an unsigned char or the value of EOF),
//		which is any charactyer between 48 and 57.
//	-> Returns 0 if the character tests false, or 1 if the character tests true.

int		ft_isalnum(int c);
//	Tests for any character for which ft_isalpha() or ft_isdigit() is true (the
//		value of the argument must be representable as an unsigned char or the
//		value of EOF),
//		which is any character between 65 and 90, 97 and 122, 48 and 57.
//	-> Returns 0 if the character tests false, or 1 if the character tests true.

int		ft_isascii(int c);
//	Tests for an ASCII character,
//		which is any character between 0 and 127.
//	-> Returns 0 if the character tests false, or 1 if the character tests true.

int		ft_isprint(int c);
//	Tests for any printing character, including space (‘ ’) (the value of the
//		argument must be representable as an unsigned char or the value of EOF),
//		which is any character between 32 and 126.
//	-> Returns 0 if the character tests false or 1 if the character tests true.

int		ft_toupper(int c);
//	Converts a lower-case letter to the corresponding upper-case letter (the
//		argument must be representable as an unsigned char or the value of EOF).
//	-> If the argument is a lower-case letter, the function returns the
//	corresponding upper-case letter if there is one,
//	otherwise, the argument is returned unchanged.

int		ft_tolower(int c);
//	Converts an upper-case letter to the corresponding lower-case letter (the
//		argument must be representable as an unsigned char or the value of EOF).
//	-> If the argument is an upper-case letter, the function returns the
//		corresponding lower-case letter if there is one;
//		otherwise, the argument is returned unchanged.

/*******************************************************************************
STRING MANIPULATION FUNCTIONS
*******************************************************************************/

size_t	ft_strlen(const char *s);
//	Computes the length of the string s.
//	-> Returns the number of characters that precede the terminating NULL
//		character.

int		ft_strcmp(const char *s1, const char *s2);
//	Lexicographically compare the null-terminated strings s1 and s2
//		(using unsigned characters).
//	-> Return an integer greater than, equal to, or less than 0, according as
//		the string s1 is greater than, equal to, or less than the string s2.

int		ft_strncmp(const char *s1, const char *s2, size_t n);
//	Like ft_strcmp() but ft_strncmp() compares not more than n characters.
//	-> Return an integer greater than, equal to, or less than 0, according as
//		the string s1 is greater than, equal to, or less than the string s2.

int		ft_atoi(const char *str);
//	Converts the initial portion of the string pointed to by str to int
//		representation, ignoring leading spaces and stopping conversion at
//		first non-numeric character.
//	-> Returns the integer represented by the initial numeric characters of
//		the string str.

int		ft_strequ(char const *s1, char const *s2);
//	Compares strings s1 and s2 lexicographically.
//	-> Returns 1 if the two strings are equal, otherwise 0.

int		ft_strnequ(char const *s1, char const *s2, size_t n);
//	Compares strings s1 and s2 lexicographically
//		up to a maximum of n charactrers or until a '\0' is encountered.
//	-> Returns 1 if the two strings are equal, otherwise 0.

char	*ft_strcpy(char *dst, const char *src);
//	Copies the string src to dst (including the terminating ‘\0’ character.)
//	!! The source and destination strings should not overlap,
//		as the behavior is undefined.
//	-> Returns dst.

char	*ft_strncpy(char *dst, const char *src, size_t len);
//	Like ft_strcpy() but copies at most len characters from src into dst
//		(if src is less than len characters long, the remainder of dst is
//		filled with ‘\0’ character; otherwise, dst is not terminated.
//	!! The source and destination strings should not overlap,
//		as the behavior is undefined.
//	-> Returns dst.

char	*ft_strcat(char *s1, const char *s2);
//	Appends a copy of the null-terminated string s2 to the end of the
//		null-terminated string s1, then add a terminating ‘\0’
//		(the string s1 must have sufficient space to hold the result)
//		(the source and destination strings should not overlap,
//		as the behavior is undefined).
//	!! ft_strcat() is easily misused in a manner which enables malicious users
//		to arbitrarily change a running program's functionality through a
//		buffer overflow attack.
//	-> Returns the pointer s1.

char	*ft_strncat(char *s1, const char *s2, size_t n);
//	Like ft_strcat() but appends not more than n characters from s2,
//		and then adds a terminating ‘\0’
//		(the string s1 must have sufficient space to hold the result)
//		(the source and destination strings should not overlap,
//		as the behavior is undefined).
//	-> Returns the pointer s1.

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
//	Appends string src to the end of string dst
//		(it will append at most dstsize - strlen(dst) - 1 characters),
//		it will then null-terminate,
//		unless dstsize is 0 or the original dst string was longer than dstsize.
//		!! If the src and dst strings overlap, the behavior is undefined.
//	-> Returns the total length of the string it tried to create
//		(that means the initial length of dst plus the length of src).
//	!! If the return value is >= dstsize, the output string has been truncated.

char	*ft_strstr(const char *haystack, const char *needle);
//	Locates the first occurrence of the null-terminated string needle in
//		the null-terminated string haystack.
//	-> If needle is an empty string, haystack is returned,
//		if needle occurs nowhere in haystack, NULL is returned,
//		otherwise a pointer to the first character
//		of the first occurrence of needle is returned.

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
//	Locates the first occurrence of the null-terminated string needle in the
//		string haystack, where not more than len characters are searched
//		(characters that appear after a ‘\0’ character are not searched).
//	-> If needle is an empty string, haystack is returned,
//		if needle occurs nowhere in haystack, NULL is returned,
//		otherwise a pointer to the first character of the first occurrence
//		of needle is returned.

char	*ft_strchr(const char *s, int c);
//	Locates the first occurrence of c (converted to a char) in the string
//		pointed to by s (the terminating null character is considered
//		to be part of the string, therefore if c is ‘\0’,
//		the functions locate the terminating ‘\0’).
//	-> Returns a pointer to the located character,
//		or NULL if the character does not appear in the string.

char	*ft_strrchr(const char *s, int c);
//	Like ft_strchr() except it locates the last occurrence of c.
//	-> Returns a pointer to the located character,
//		or NULL if the character does not appear in the string.

char	*ft_strdup(const char *s1);
//	Allocates sufficient memory for a copy of the string s1 ande does the copy.
//	-> Returns a pointer to the copy (the pointer may subsequently be used as
//		an argument to the function free())
//		(if insufficient memory is available, NULL is returned).

char	*ft_strnew(size_t size);
//	Allocates with malloc() and creates a string of size "size" terminated by
//		'\0' (each character in the string is initialized to '\0').
//	-> Returns the newly created string, or NULL if allocation fails.

char	*ft_strsub(char const *s, unsigned int start, size_t len);
//	Allocates with malloc() and copies a substring of string s
//		(the substring begins at at index start and has a lenght of len).
//	!! If start and len do not specify a valid substring, behavior is undefined.
//	-> Returns the newly created copy, or NULL if allocation fails.

char	*ft_strjoin(char const *s1, char const *s2);
//	Allocates with malloc() and creates a new string resulting from the
//		concatenation of s1 (prefix string) and s2 (sufix string).
//	-> Returns the newly created string, or NULL if allocation fails.

char	*ft_strtrim(char const *s);
//	Allocates with malloc() and creates a copy of string s
//		without the leading and trailing whitespace characters
//		(whitespaces characters are considerated to be ' ', '\n', and '\t').
//	-> Returns the newly created string (if s contains no leading or trailing
//		whitespace, returns a copy of s), or NULL if allocation fails.

char	*ft_itoa(int n);
//	Allocates with malloc() and creates a new null-terminated string
//		representing the integer n.
//	-> Returns the newly created string, or NULL if allocation fails.

char	**ft_strsplit(char const *s, char c);
//	Allocates with malloc() and creates an array of null-terminated strings
//		resulting from splitting the string s according to the character c.
//	-> Returns the newly created array of strings, or NULL if allocation fails.

void	ft_strclr(char *s);
//	Assign the value '\0' to all characters of the string passed as a parameter.

void	ft_strdel(char **as);
//	Takes as a parameter the adress of the string as which must be freed with
//		free(), and sets its pointer to NULL.

void	ft_bzero(void *s, size_t n);
//	Writes n zeroed bytes to the string s.
//		If n is zero, ft_bzero() does nothing.

/*******************************************************************************
MEMORY MANIPULATION FUNCTIONS
*******************************************************************************/

void	ft_memdel(void **ap);
//	Takes as a parameter the adress of the pointer ap whose pointed area must
//		be freed with free(), then the pointer is set to NULL.

void	*ft_memset(void *b, int c, size_t len);
//	Writes len bytes of value c (converted to an unsigned char) to the string b.
//	-> Returns its first argument.

int		ft_memcmp(const void *s1, const void *s2, size_t n);
//	Compares byte string s1 against byte string s2
//		(both strings are assumed to be n bytes long).
//	-> Returns zero if the two strings are identical, otherwise returns the
//		difference between the first two differing bytes treated as
//		unsigned char values (zero-length strings are always identical).

void	*ft_memcpy(void *dst, const void *src, size_t n);
//	Copies n bytes from memory area src to memory area dst.
//	!! If dst and src overlap, behavior is undefined.
//	-> Returns the original value of dst.

void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
//	Copies bytes from string src to string dst.
//		If the character c (as converted to an unsigned char) occurs in the
//		string src, the copy stops and a pointer to the byte after the copy of c
//		in the string dst is returned. Otherwise, n bytes are copied, and a
//		NULL pointer is returned.
//	!! The source and destination strings should not overlap,
//		as the behavior is undefined.
//	-> Returns a pointer to the byte after the copy of c in the string.
//		Otherwise (if it didn't find c), n bytes are copied,
//		and a NULL pointer is returned.

void	*ft_memmove(void *dst, const void *src, size_t len);
//	Copies len bytes from string src to string dst. The two strings may
//		overlap; the copy is always done in a non-destructive manner.
//	-> Returns the original value of dst.

void	*ft_memchr(const void *s, int c, size_t n);
//	Locates the first occurrence of c (converted to an unsigned char)
//		in string s.
//	-> Returns a pointer to the byte located,
//		or NULL if no such byte exists within n bytes.

void	*ft_memalloc(size_t size);
//	Allocates (with malloc()) and returns a fresh memory area.
//		The allocated memory is initialized to 0.
//	-> Returns the allocated memory area, or NULL if allocation fails.

/*******************************************************************************
CALLBACK FUNCTIONS
*******************************************************************************/

void	ft_striter(char *s, void (*f)(char *));
//	Applies the function f to each character of the string s.

void	ft_striteri(char *s, void (*f)(unsigned int, char *));
//	Applies the function f to each character of the string s,
//		specifying its index as the first argument.

char	*ft_strmap(char const *s, char (*f)(char));
//	Applies the function f to each character of the string s
//		to create a new string allocated with malloc()
//		resulting from the successive applications of f.
//	-> Returns the new created string.

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));	
//	Applies the function f to each character of the string s,
//		specifying the characters's index, to create a new string
//		allocated with malloc() resulting from the successive applications of f.
//	-> Returns the new created string.

/*******************************************************************************
LIST MANIPULATION FUNCTIONS
*******************************************************************************/

t_list	*ft_lstnew(void const *content, size_t content_size);
//	Allocates (using malloc()) and returns a "fresh" link. The content and
//		content_size fields in the new link are initialized by copying the
//		function parameters.
//		If content is NULL, the content field is set to NULL and content_size
//		to 0.
//		The next fiels is initialized to NULL.
//	-> Returns the "fresh" link, or NULL if allocation fails.

#endif
