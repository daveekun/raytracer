/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:29:29 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 23:29:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include <stdlib.h>

void render(mlx_image_t *img);

int main(void)
{
    mlx_t		*mlx;
	mlx_image_t	*image;

	mlx = mlx_init(1000, 1000, "fdf", false);
	if (!mlx)
		return (0);
	image = mlx_new_image(mlx, 100, 100);
	if (!image)
		return (0);
    render(image);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
    exit(0);
}
