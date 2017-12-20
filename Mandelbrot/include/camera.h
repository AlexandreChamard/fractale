/*
** camera.h for ok in /home/alexandre/Documents/balek/platform/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat Aug 19 18:36:06 2017 Alexandre Chamard-bois
** Last update Sat Dec 16 23:49:47 2017 alexandre Chamard-bois
*/

#ifndef CAMERA_H_
# define CAMERA_H_

# include "map.h"

# define SPEED        0.01
# define SPEED_ZOOM   0.9

typedef struct  s_camera
{
  float         x;
  float         y;
  float         zoom;
}               t_camera;

int init_camera(t_camera *camera);

#endif
