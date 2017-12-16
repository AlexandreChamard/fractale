/*
** camera.h for ok in /home/alexandre/Documents/balek/platform/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat Aug 19 18:36:06 2017 Alexandre Chamard-bois
** Last update Sat Dec 16 18:05:17 2017 alexandre Chamard-bois
*/

#ifndef CAMERA_H_
# define CAMERA_H_

# include "map.h"

# define SIZE_BLOCK   50
# define SPEED        0.01
# define SPEED_ZOOM   0.9
# define ZOOM_MIN     .5
# define ZOOM_MAX     2

typedef struct  s_camera
{
  float         x;
  float         y;
  float         zoom;
}               t_camera;

int init_camera(t_camera *camera, t_map *map);

#endif
