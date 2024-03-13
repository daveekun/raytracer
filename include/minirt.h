/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:45:03 by dhorvath          #+#    #+#             */
/*   Updated: 2024/03/13 21:52:20 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

typedef struct s_color
{
	int r;
	int g;
	int b;
	int alpha;
}	t_color;


typedef struct s_vector3
{
	float x;
	float y;
	float z;
}	t_vector3;

typedef struct s_hit
{
	t_vector3	pos;
	t_color		color;
}	t_hit;

typedef struct s_ray
{
	t_vector3	dir;
	t_hit		*hit;	
}	t_ray;


#endif