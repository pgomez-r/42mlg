/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 00:12:36 by codespace         #+#    #+#             */
/*   Updated: 2024/06/13 04:53:03 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	paint_miniplayer(mlx_image_t *mini, size_t *x, size_t *y)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mlx_put_pixel(mini, *x + j, *y + i, 0xFF0000FF);
			j++;
		}
		i++;
	}
	*(x) += 4;
	//*(y) += 4;
	return (4);
}

void	update_minimap(t_mlx_st *st)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < st->d->mini_h)
	{
		x = 0;
		while (x < st->d->mini_w)
		{
			if (st->d->map[y / (PIX / 4)][x / (PIX / 4)] == '1')
				mlx_put_pixel(st->gfx.minimap, x, y, 0x000000FF);
			else
				mlx_put_pixel(st->gfx.minimap, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
	x = st->gfx.player->instances[0].x / 4;
	y = st->gfx.player->instances[0].y / 4;
	paint_miniplayer(st->gfx.minimap, &x, &y);
	basic_ray(st);
}

void	game_hook(void *param)
{
	t_mlx_st	*st;

	st = (t_mlx_st *)param;
	if (st->d->exit_code == 0)
	{
		key_control(st);
		update_minimap(st);
		//basic_ray(st);
	}
}


void	init_data(t_struct *d, t_mlx_st *st)
{
	st->fpp.ang = M_PI / 2;
	d->map[0] = "11111111";
	d->map[1] = "10100001";
	d->map[2] = "10110001";
	d->map[3] = "10010001";
	d->map[4] = "10000001";
	d->map[5] = "10P00101";
	d->map[6] = "10000001";
	d->map[7] = "11111111";
	d->height = 8;
	d->width = 8;
	d->exit_code = 0;
	st->d = d;
	st->gfx.st_ptr = st;
}

int	main(void)
{
	t_struct	d;
	t_mlx_st	st;

	init_data(&d, &st);
	if (d.exit_code == 0)
	{
		st.game = mlx_init(d.height * PIX, d.width * PIX, "test", false);
		load_images(&st);
		render_map(&st);
		mlx_loop_hook(st.game, game_hook, &st);
		mlx_loop(st.game);
		mlx_terminate(st.game);
	}
	return (0);
}
