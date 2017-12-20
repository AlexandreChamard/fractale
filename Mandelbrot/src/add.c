/*
** add.c for fractale in /home/alexandre/Documents/git/fractale/Mandelbrot/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Mon Dec 18 14:04:34 2017 alexandre Chamard-bois
** Last update Tue Dec 19 11:22:08 2017 alexandre Chamard-bois
*/

#include "macro.h"
#include "mymath.h"
#include <stdlib.h>

void _add(my_float_t *f1, my_float_t *f2);
void _sub(my_float_t *f1, my_float_t *f2);

void sub_exp(my_float_t *f, int inc)
{
    for (int i = f->round - 1; i > 0; i--) {
        f->nb[i] = f->nb[i - 1];
    }
    f->nb[0] = '0';
}

void decal_sub(my_float_t *f, int i)
{
    while (i > 0) {
        if (f->nb[i] <= '9')
        f->nb[i] -= '0';
        f->nb[i - 1]++;
        i--;
    }
    if (!i && f->nb[0] > '9') {
        sub_exp(f, 1);
        f->nb[0] = '1';
    }
}

void _sub(my_float_t *f1, my_float_t *f2)
{
    int i = f2->exp - f1->exp;
    int j = 0;

    while (i < f1->round && j < f2->round) {
        f1->nb[i] -= f2->nb[j] - '0';
        if (f1->nb[i] < '0') {
            decal_sub(f1, i);
        }
        i++;
        j++;
    }
}

void add_exp(my_float_t *f, int inc)
{
    for (int i = f->round - 1; i > 0; i--) {
        f->nb[i] = f->nb[i - 1];
    }
    f->nb[0] = '0';
}

void decal_add(my_float_t *f, int i)
{
    while (i > 0) {
        if (f->nb[i] <= '9') {
            break;
        }
        f->nb[i] -= '0';
        f->nb[i - 1]++;
        i--;
    }
    if (!i && f->nb[0] > '9') {
        add_exp(f, 1);
        f->nb[0] = '1';
    }
}

void _add(my_float_t *f1, my_float_t *f2)
{
    int i = f2->exp - f1->exp;
    int j = 0;

    while (i < f1->round && j < f2->round) {
        f1->nb[i] += f2->nb[j] - '0';
        if (f1->nb[i] > '9') {
            decal_add(f1, i);
        }
        i++;
        j++;
    }
}

my_float_t *add_float(my_float_t *f1, my_float_t *f2)
{
    my_float_t *f;

    if (cmp_abs_float(f1, f2) >= 0) {
        f = dup_float(f1, MAX(f1->round, f2->round));
        if (f1->sign == f2->sign) {
            _add(f, f2);
        } else {
            _sub(f, f2);
        }
    } else {
        f = dup_float(f2, MAX(f1->round, f2->round));
        if (f1->sign == f2->sign) {
            _add(f, f1);
        } else {
            _sub(f, f1);
        }
    }
    return (f);
}
