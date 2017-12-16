/*
** my_str_to_wordtab.c for fractale in /home/alexandre/Documents/git/fractale/fractale/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Dec 16 14:39:06 2017 alexandre Chamard-bois
** Last update Sat Dec 16 14:39:08 2017 alexandre Chamard-bois
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
	for (int i = 0; tab[i]; i++) {
		free(tab[i]);
	}
	free(tab);
}

char	*put_word(char *str, int width, int *j)
{
	char *word;
	int i = 0;

	if (!(word = malloc(sizeof(char) * (width + 1))))
	return (NULL);
	while (i < width) {
		word[i] = str[*j];
		i++;
		(*j)++;
	}
	word[i] = 0;
	(*j)++;
	return (word);
}

char	**my_str_to_wordtab(char *str, int width, int height)
{
	char **tab;
	int i = 0;
	int j = 0;

	if (!(tab = malloc(sizeof(char *) * (height + 1))))
	return (NULL);
	while (i < height) {
		if (!(tab[i] = put_word(str, width, &j))) {
			free_tab(tab);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
