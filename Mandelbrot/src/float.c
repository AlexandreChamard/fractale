/*
** float.c for fractale in /home/alexandre/Documents/git/fractale/Mandelbrot/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Dec 16 22:29:01 2017 alexandre Chamard-bois
** Last update Tue Dec 19 10:32:27 2017 alexandre Chamard-bois
*/

#include <stdlib.h>
#include <stdio.h>
#include "mymath.h"
#include "macro.h"

void put_nb(char *nb, const char **str, int *i, int round)
{
	while (*i < round && **str >= '0' && **str <= '9') {
		nb[*i] = **str;
		(*i)++;
		(*str)++;
	}
}

void set_float_to_zero(my_float_t *f, int round)
{
	f->round = round;
	for (int i = 0; i < round; i++) {
		f->nb[i] = '0';
	}
}

my_float_t	*str_to_float(const char *str, int round)
{
	my_float_t *f = malloc(sizeof(my_float_t) + round);
	int i = 0;

	if (!f) {
		return (NULL);
	}
	set_float_to_zero(f, round);
	f->sign = POS;
	if (*str == '-') {
		f->sign = NEG;
		str++;
	}
	put_nb(f->nb, &str, &i, round);
	f->exp = i;
	if (*str == '.') {
		str++;
		put_nb(f->nb, &str, &i, round);
	}
	return (f);
}

my_float_t *dup_float(my_float_t *flt, int round)
{
    my_float_t *f = malloc(sizeof(my_float_t) + round);

    set_float_to_zero(f, round);
    f->sign = flt->sign;
    f->exp = flt->exp;
    f->round = round;
    for (int i = 0; i < MIN(round, flt->round); i++) {
        f->nb[i] = flt->nb[i];
    }
    return (f);
}

int main(int ac, char **av) {
    my_float_t *f1 = str_to_float(av[1], atoi(av[2]));
	my_float_t *f2 = str_to_float(av[3], atoi(av[4]));
    printf("%d\n", cmp_float(f1, f2));
	return (0);
}
