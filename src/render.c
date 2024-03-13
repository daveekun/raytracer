/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:42:59 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/13 21:59:42 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include "minirt.h"

t_ray	create_ray(int x, int y)
{
	const	float fov;
}

void	render(mlx_image_t *img)
{
	int		x;
	int		y;
	t_ray	ray;
	void	*scene;

	x = 0;
	y = 0;
	while (x < 1000)
	{
		while (y < 1000)
		{
			ray = create_ray(x, y);
			trace_ray(ray, scene);
			if (ray.hit)
				mlx_put_pixel(img, x, y, get_color(ray.hit->color));
			else
				mlx_put_pixel(img, x, y, 255);
			y++;
		}
		x++;
	}
}
