/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:00:55 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 01:48:10 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>

# include <errno.h>

# define BUFFER_SIZE 1024

/*
**	LINKED LIST 
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* Absract syntax trees (ast)\
	@NOTE:
		- content of the node is a void pointer to be able to store any data type.
			and to be as generic as possible. generic code means quality code.
				just look at American Propoganda's success.			
*/

typedef struct s_AST
{
	char			*sym;
	void			*content;
	struct s_AST	*left;
	struct s_AST	*right;
	struct s_AST	*prev;
}	t_ast;

t_ast				*ft_ast_new_node(char *sym, void *content);
t_ast				*ft_ast_add_noder(t_ast *ast, char *sym, void *content);
t_ast				*ft_ast_add_nodel(t_ast *ast, char *sym, void *content);
t_ast				*ft_ast_add_nodelri(t_ast *ast, char *sym, \
										void *content, int ri);
t_ast				*ft_ast_add_noderli(t_ast *ast, char *sym, \
						void *content, size_t i);
void				ft_free_ast(t_ast *ast);
void				ft_print_ast(t_ast *ast);
t_ast				*ft_ast_add_nodei(t_ast *root, char *sym, \
						void *content, char *where);

/*
** String manipulation
*/

size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s, const char *set);
char				**ft_split(char const *s, char c);
// char 				**ft_splitq(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strnstr(const char *haystack, \
						const char *needle, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strstr(const char *heystack, const char *needle);
bool				ft_isspace(char c);
int					*ft_stcount(const char *s, char c);
char				*ft_getnextS(char *s);
char				*ft_lineinsert(char *line, char *content, \
													size_t start, size_t end);
char				*ft_lindetach(char *line, size_t start, size_t end);
char				**ft_strsplit(char const *s, char *delim);
bool				ft_sisspace(char *s);
bool				ft_isempty(char *str);
bool				ft_strofonly(char *str, char *charset);
bool				ft_isnumber(char *str);

/*
** MEMORY MANIIPULATION
*/

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_realloc(void *ptr, size_t size);
void				ft_sfree(void *ptr);

/* 
**  2D ARRAY MANIPULATION
*/

void				ft_doubfree(void **doub, size_t size);
void				**ft_2darr_realloc(void **doub, size_t size);
char				**ft_2darr_del(char **array, size_t start, size_t end);
char				**ft_2darr_trim(char **doub, char *set);
size_t				ft_2darr_len(const char **doub);
char				*ft_2darr_to_str(char **doub, char *s);
int					ft_2darr_count(const char **doub, char *to_find);
char				**ft_doubdup(char **doub);
char				**ft_2darr_add(char **doub, char *content);

/*
** FILE DESCRIPTORS MANIPULATION
*/
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char const *s, int fd);

/*
** FILE MANIPULATION
*/

int					ft_filecpy(char *filecpyfrom, char *filecpyto, int mode);
bool				ft_validfname(char *name);
size_t				ft_filelcount(char *file);
char				*get_next_line( int fd );
char				**ft_file_to_2darr(char *file);

/*
** LINKED LISTS MANIPULATION
*/

t_list				*ft_lstnew(void *content);
void				ft_lstdelone(t_list *alst, void (*del)(void *));
void				ft_lstadd_back(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_front(t_list **alst, t_list *new);

/* 
**	Math functions
*/
long int			ft_isPrime(long int n);

/* 
**	error handling
*/

int					exitif(int condition, char *message);

/*
** Miscelaneous functions
*/

void				*ft_ternary(int condition, void *true_value, \
						void *false_value);						
int					ft_intternary(int condition, int true_value, \
						int false_value);

/*  
** ENV MANIPULATION
*/

char				*ft_getenv(char **env, char *var);
bool				ft_envexist(char **env, char *var);
char				*ft_envexp(char **env, char *var);
bool				ft_valid_envname(char *env_name);

/*
** DUMP VALUES TO THEIR BIN REPRESENTATION 
*/

void				ft_dumpbin_int( int num );

#endif
