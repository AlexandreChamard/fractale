/*
** cmp.c for fractale in /home/alexandre/Documents/git/fractale/Mandelbrot/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Mon Dec 18 14:09:22 2017 alexandre Chamard-bois
** Last update Tue Dec 19 10:23:20 2017 alexandre Chamard-bois
*/

#include "macro.h"
#include "mymath.h"

int cmp_float(my_float_t *f1, my_float_t *f2)
{
    my_float_t *tmp;
    int i = 0;

    if (f1->sign != f2->sign) {
        return (f1->sign == POS ? 1 : -1);
    }
    if (f1->exp != f2->exp) {
        return (f1->exp > f2->exp ? 1 : -1);
    }
    while (i < MIN(f1->round, f2->round) && f1->nb[i] == f2->nb[i]) {
        i++;
    }
    if (f1->round != f2->round && i == MIN(f1->round, f2->round)) {
        tmp = f1->round > f2->round ? f1 : f2;
        for (int j = i; j < tmp->round; j++) {
            if (tmp->nb[j] != '0') {
                return (f1->round > f2->round ? 1 : -1);
            }
        }
        return (0);
    }
    return (f1->nb[i] - f2->nb[i]);
}

int cmp_abs_float(my_float_t *f1, my_float_t *f2)
{
    my_float_t *tmp;
    int i = 0;

    if (f1->exp != f2->exp) {
        return (f1->exp > f2->exp ? 1 : -1);
    }
    while (i < MIN(f1->round, f2->round) && f1->nb[i] == f2->nb[i]) {
        i++;
    }
    if (f1->round != f2->round && i == MIN(f1->round, f2->round)) {
        tmp = f1->round > f2->round ? f1 : f2;
        for (int j = i; j < tmp->round; j++) {
            if (tmp->nb[j] != '0') {
                return (f1->round > f2->round ? 1 : -1);
            }
        }
        return (0);
    }
    return (f1->nb[i] - f2->nb[i]);
}
