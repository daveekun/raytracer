/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:40:05 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/13 21:42:53 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>

int main(void)
{
	mlx_t	*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(1000, 1000, "rt", false);
	img = mlx_new_image(mlx, 1000, 1000);
	render(img);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	exit(0);
}