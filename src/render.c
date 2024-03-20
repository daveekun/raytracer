/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:31:42 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 23:31:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <math.h>
#include <MLX42/MLX42.h>
/* singular sphere at 0 0 5 with radius of 1*/
typedef struct s_point3
{
    double x;
    double y;
    double z;
} point3;

typedef struct s_color
{
    int r;
    int g;
    int b;
    int a;
} color;

typedef struct s_ray
{
    point3 start;
    point3 dir;
    point3 pos;
    color  hit;
}   ray;

double distance(point3 a, point3 b)
{
    return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2)));
}

void    trace(ray *r)
{
    int steps = 0;
    point3 spherecenter = (point3){0, 0, 5};
    double radius = 10;

    while (steps < 10000)
    {
        if (distance(r->pos, spherecenter) <= radius)
        {
            r->hit = (color){255, 0, 0, 1};
            return ;
        }
        r->pos.x += r->dir.x;
        r->pos.y += r->dir.y;
        r->pos.z += r->dir.z;
        steps++;
    }
    r->hit = (color){0, 0, 0, 1};
    return ;
}

int getcolor(color c)
{
    return (c.r << 24 | c.g << 16 | c.b << 8 | c.a);
}

#define RAYX 100
#define RAYY 100
void render(mlx_image_t *img)
{
    int ray_index_x = 0;
    int ray_index_y = 0;

    double vx = 50;
    double vy = 50;
    double vz = 1;


    double x = 0;
    double y = 0;
    double px = vx / RAYX;
    double py = vy / RAYY;

    ray r;
    /*viewscreen */

    x = 0;
    ray_index_x = 0;
    while (ray_index_x < RAYX)
    {
        y = 0;
        ray_index_y = 0;
        while (ray_index_y < RAYY)
        {
            /* create ray */
            r.start = (point3){0, 0, 0};
            r.dir = (point3){x, y, vz};
            /* check where it hits */
            trace(&r);
            mlx_put_pixel(img, ray_index_x, ray_index_y, getcolor(r.hit));
            y += vy;
            ray_index_y++;
        }
        x += vx;
        ray_index_x++;
    }
}