/*
** math.h for math in /home/alexandre/Documents/git/fractale/Mandelbrot/include
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Dec 16 15:12:47 2017 alexandre Chamard-bois
** Last update Tue Dec 19 10:48:08 2017 alexandre Chamard-bois
*/

#ifndef MATH_H_
# define MATH_H_

#ifndef ROUND
# define ROUND	32
#endif

#ifndef POS
#define POS 0
#endif

#ifndef NEG
#define NEG 1
#endif

typedef struct	my_float {
	int	sign;
	int	exp;
	int	round;
	char	nb[];
}	my_float_t;

double map(double p, double x[2], double y[2]);

my_float_t *str_to_float(const char *str, int round);
my_float_t *dup_float(my_float_t *flt, int round);

my_float_t *add_float(my_float_t*, my_float_t*);
int cmp_float(my_float_t*, my_float_t*);
int cmp_abs_float(my_float_t *f1, my_float_t *f2);

#endif
