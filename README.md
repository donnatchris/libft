# PROJECT LIBFT FOR 42
By chdonnat (Christophe Donnat from 42 Perpignan, France)

## AIM OF THE PROJECT:
You will create your own function library, which you will use throughout the rest of your curriculum.

### BONUS
You must code linked list functions.

## SOME COMMANDS YOU CAN USE:

compile the libft library to get the libft.a file:
	
 	make
 
compile the library with the linked list functions:

	make bonus
 
remove all .o files:

	make clean
 
remove all .o files and executable files generated by the make command:

	make fclean

 remove all .o files and executable files generated by the make command, and the compile the library again:

	re

# THE LIBRARY

## PRINT AND WRITE FUNCTIONS

### ft_putchar

`void ft_putchar_fd(char c, int fd);`

> Writes the character c to the file descriptor fd.

### ft_putstr

`void ft_putstr_fd(char *s, int fd);`

> Writes the string s to the file descriptor fd.

### ft_putendl

`void ft_putendl_fd(char *s, int fd);`

> Writes the string s followed by '\n' to the file descriptor fd.

### ft_putnbr

`void ft_putnbr_fd(int n, int fd);`

> Writes the integer n to the file descriptor fd.

---

## CHARACTER MANIPULATION FUNCTIONS

### ft_isalpha

`int ft_isalpha(int c);`

> Tests if `c` is a letter (the value of the argument must be representable as an unsigned char or the value of EOF), which is any character between 65 and 90 or 97 and 122.  
> -> Returns zero if the character tests false and returns non-zero if the character tests true.

### ft_isdigit

`int ft_isdigit(int c);`

> Tests for a decimal digit character (the value of the argument must be representable as an unsigned char or the value of EOF), which is any character between 48 and 57.  
> -> Returns 0 if the character tests false, or 1 if the character tests true.

### ft_isalnum

`int ft_isalnum(int c);`

> Tests for any character for which `ft_isalpha()` or `ft_isdigit()` is true (the value of the argument must be representable as an unsigned char or the value of EOF), which is any character between 65 and 90, 97 and 122, 48 and 57.  
> -> Returns 0 if the character tests false, or 1 if the character tests true.

### ft_isascii

`int ft_isascii(int c);`

> Tests for an ASCII character, which is any character between 0 and 127.  
> -> Returns 0 if the character tests false, or 1 if the character tests true.

### ft_isprint

`int ft_isprint(int c);`

> Tests for any printing character, including space (‘ ’) (the value of the argument must be representable as an unsigned char or the value of EOF), which is any character between 32 and 126.  
> -> Returns 0 if the character tests false or 1 if the character tests true.

### ft_toupper

`int ft_toupper(int c);`

> Converts a lower-case letter to the corresponding upper-case letter (the argument must be representable as an unsigned char or the value of EOF).  
> -> If the argument is a lower-case letter, the function returns the corresponding upper-case letter if there is one, otherwise, the argument is returned unchanged.

### ft_tolower

`int ft_tolower(int c);`

> Converts an upper-case letter to the corresponding lower-case letter (the argument must be representable as an unsigned char or the value of EOF).  
> -> If the argument is an upper-case letter, the function returns the corresponding lower-case letter if there is one; otherwise, the argument is returned unchanged.

---

## STRING MANIPULATION FUNCTIONS

### ft_strlen

`size_t ft_strlen(const char *s);`

> Computes the length of the string s.  
> -> Returns the number of characters that precede the terminating NULL character.

### ft_strncmp

`int ft_strncmp(const char *s1, const char *s2, size_t n);`

> Like `ft_strcmp()` but `ft_strncmp()` compares not more than n characters.  
> -> Return an integer greater than, equal to, or less than 0, according as the string s1 is greater than, equal to, or less than the string s2.

### ft_atoi

`int ft_atoi(const char *nptr);`

> Converts the initial portion of the string pointed to by nptr to an integer representation, ignoring leading spaces and stopping conversion at the first non-numeric character.  
> -> Returns the integer represented by the initial numeric characters of the string nptr.

### ft_strlcat

`size_t ft_strlcat(char *dst, const char *src, size_t size);`

> Appends string `src` to the end of string `dst` (it will append at most size - strlen(dst) - 1 characters), and it will then null-terminate, unless size is 0 or the original `dst` string was longer than dstsize.  
> -> Returns the total length of the string it tried to create (that means the initial length of `dst` plus the length of `src`).  
> !! If the return value is >= `dstsize`, the output string has been truncated.

### ft_strlcpy

`size_t ft_strlcpy(char *dst, const char *src, size_t size);`

> Copies up to size - 1 characters from the NUL-terminated string `src` to `dst`, NUL-terminating the result.  
> -> Returns the length of `src` (makes truncation detection easier).

### ft_strnstr

`char *ft_strnstr(const char *big, const char *little, size_t len);`

> Locates the first occurrence of the null-terminated string `little` in the string `big`, where not more than `len` characters are searched (characters that appear after a ‘\0’ character are not searched).  
> -> If `little` is an empty string, `big` is returned; if `little` occurs nowhere in `big`, NULL is returned; otherwise, a pointer to the first character of the first occurrence of `little` is returned.

---

## MEMORY MANIPULATION FUNCTIONS

### ft_bzero

`void ft_bzero(void *s, size_t n);`

> Writes n zeroed bytes to the string `s`. If n is zero, `ft_bzero()` does nothing.

### ft_calloc

`void *ft_calloc(size_t nmemb, size_t size);`

> Allocates memory for an array of nmemb elements of size bytes each. The memory is set to zero.  
> -> Returns a pointer to the allocated memory. If nmemb or size is zero, returns a unique pointer value that can be passed to `free()`. If the multiplication of `nmemb * size` would result in integer overflow, `calloc()` returns NULL.

### ft_memset

`void *ft_memset(void *s, int c, size_t n);`

> Writes n bytes of value c (converted to an unsigned char) to the string `s`.  
> -> Returns its first argument.

---

## CALLBACK FUNCTIONS

### ft_striteri

`void ft_striteri(char *s, void (*f)(unsigned int, char *));`

> Applies the function f to each character of the string `s`, specifying its index as the first argument.

### ft_strmapi

`char *ft_strmapi(char const *s, char (*f)(unsigned int, char));`

> Applies the function f to each character of the string `s`, specifying the character's index, to create a new string allocated with `malloc()` resulting from the successive applications of f.  
> -> Returns the newly created string.

---

## LIST MANIPULATION FUNCTIONS

### ft_lstnew

` t_list *ft_lstnew(void *content);`

> Allocates (using malloc()) and returns a new link. The content field in the new link is initialized with the value of the content parameter. The next field is initialized to NULL.  
> **Returns**: The "fresh" link, or NULL if allocation fails.

### ft_lstdelone

`void ft_lstdelone(t_list *lst, void (*del)(void *));`

> Frees the memory of the element passed as parameter using the `del` function, then with `free()`.  
> **Note**: The memory of the next field is not freed.

### ft_lstadd_front

`void ft_lstadd_front(t_list **lst, t_list *new);`

> Adds the element `new` at the start of the list.  
> **Parameters**:  
> - `lst` is the address of the pointer to the first element of the list.  
> - `new` is the address of the pointer to the element to be added.

### ft_lstsize

`int ft_lstsize(t_list *lst);`

> Counts the number of elements in the list.  
> **Parameters**:  
> - `lst` is the start of the list.  
> **Returns**: The count of elements in the list.

### ft_lstlast

`t_list *ft_lstlast(t_list *lst);`

> Finds the last element of the list.  
> **Parameters**:  
> - `lst` is the first element of the list.  
> **Returns**: The last element of the list.

### ft_lstadd_back

`void ft_lstadd_back(t_list **lst, t_list *new);`

> Adds the element `new` to the end of the list.  
> **Parameters**:  
> - `lst` is the address of the pointer to the first element of the list.  
> - `new` is the address of the pointer to the element to be added.

### ft_lstclear

`void ft_lstclear(t_list **lst, void (*del)(void *));`

> Deletes and frees the memory of the element passed as parameter and of all the following elements, using the `del()` function and `free()`. Sets the initial pointer to NULL.  
> **Parameters**:  
> - `lst` is the address to the pointer to an element.  
> - `del` is the address of the function that can suppress the content of an element.

### ft_lstiter

`void ft_lstiter(t_list *lst, void (*f)(void *));`

> Iterates over the list `lst` and applies the function `f()` to the content of each element.  
> **Parameters**:  
> - `lst` is the address of the pointer to an element.  
> - `f` is the address of the function to apply.

### ft_lstmap

`t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));`

> Iterates over the list `lst` and applies the function `f()` to the content of each element. Creates a new list resulting from the successive applications of `f()`. The function `del()` is here to destroy the content of an element if needed.  
> **Returns**: The new list or NULL if allocation fails.
