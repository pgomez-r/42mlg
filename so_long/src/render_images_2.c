/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:19:27 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/02 09:17:43 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	render_exits(t_struct *st)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < st->height)
	{
		x = 0;
		while (x < st->width)
		{
			if (st->map[y][x] == 'E')
			{
				mlx_image_to_window(st->window, st->exit_c, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->exit_o, x * PIX, y * PIX);
				mlx_set_instance_depth(&st->exit_c->instances[st->exits], 110);
				mlx_set_instance_depth(&st->exit_o->instances[st->exits], -120);
				st->exits++;
			}
			x++;
		}
		y++;
	}
}

void	render_collectables(t_struct *st)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < st->height)
	{
		x = 0;
		while (x < st->width)
		{
			if (st->map[y][x] == 'C')
			{
				mlx_image_to_window(st->window, st->col1, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->col2, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->col3, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->col4, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->col5, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->col6, x * PIX, y * PIX);
				collectables_depth(st);
				st->cols++;
				st->collec_cnt++;
			}
			x++;
		}
		y++;
	}
}

void	collectables_depth(t_struct	*st)
{
	mlx_set_instance_depth(&st->col1->instances[st->cols], 110);
	mlx_set_instance_depth(&st->col2->instances[st->cols], -120);
	mlx_set_instance_depth(&st->col3->instances[st->cols], -130);
	mlx_set_instance_depth(&st->col4->instances[st->cols], -140);
	mlx_set_instance_depth(&st->col5->instances[st->cols], -150);
	mlx_set_instance_depth(&st->col6->instances[st->cols], -160);
}

void	remove_collectable(t_struct *st, int y, int x)
{
	size_t	i;

	i = 0;
	while (i < st->cols)
	{
		if ((st->col1->instances[i].y / PIX) == y / PIX
			&& (st->col1->instances[i].x / PIX) == x / PIX)
		{
			st->col1->instances[i].enabled = false;
			st->col2->instances[i].enabled = false;
			st->col3->instances[i].enabled = false;
			st->col4->instances[i].enabled = false;
			st->col5->instances[i].enabled = false;
			st->col6->instances[i].enabled = false;
			st->collec_cnt--;
			if (st->collec_cnt == 0)
				open_exit(st);
			return ;
		}	
		i++;
	}
}
