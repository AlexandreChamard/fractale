/*
** my_strcat.c for ok in /home/alexandre/Documents/lib_cheat/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu>
**
** Started on  Mon Jan  2 15:13:31 2017 Alexandre Chamard-bois
** Last update Sun Aug 20 20:07:06 2017 Alexandre Chamard-bois
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "libmy.h"

char		*my_strcat(const char *first, const char *second)
{
	int		i;
	int		j;
	char	*concat;

	i = my_strlen(first);
	j = my_strlen(second);
	if (!(concat = my_malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	if (first)
		my_strcpy(concat, first);
	if (second)
		my_strcpy(concat + i, second);
	concat[i + j] = 0;
	return (concat);
}

char *my_concat(const int nb, ...)
{
	va_list ap;
	char *str;
	char *s1;
	char *s2;
	int i;

	str = NULL;
	if (!nb)
		return (NULL);
	va_start(ap, nb);
	i = 1;
	s1 = va_arg(ap, char *);
	while (i < nb)
	{
		s2 = va_arg(ap, char *);
		s1 = my_strcat(s1, s2);
		i++;
	}
	va_end(ap);
	return (str);
}

char	*my_strncat(const char *first, const char *second, const int n)
{
	int		i;
	int		j;
	char	*concat;

	i = -1;
	while (first[++i]);
	j = -1;
	while (second[++j]);
	j = MIN(j, n);
	if (!(concat = my_malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = -1;
	while (first[++i])
		concat[i] = first[i];
	j = -1;
	while (second[++j] && j < n)
		concat[i + j] = second[j];
	concat[i + j] = 0;
	return (concat);
}
