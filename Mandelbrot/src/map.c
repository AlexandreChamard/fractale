/*
** cross.c for fractale in /home/alexandre/Documents/git/fractale/Mandelbrot/src/math
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Sat Dec 16 14:55:40 2017 alexandre Chamard-bois
** Last update Sat Dec 16 15:08:59 2017 alexandre Chamard-bois
*/

double map(double p, double x[2], double y[2])
{
	return ((p - x[0]) / (x[1] - x[0]) * (y[1] - y[0]) + y[0]);
}
