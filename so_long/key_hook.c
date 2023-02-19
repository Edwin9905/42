/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkwon <gkwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 04:08:00 by gkwon             #+#    #+#             */
/*   Updated: 2023/02/19 16:24:53 by gkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_map *map)
{
	mlx_destroy_window(map->mlx, map->window);
	exit(0);
}

int	press_key(int key_code, t_map *map)
{
	if (key_code == KEY_ESC)
		exit_game(map);
	if (key_code == KEY_W)
		move(map, KEY_W);
	if (key_code == KEY_A)
		move(map, KEY_A);
	if (key_code == KEY_S)
		move(map, KEY_S);
	if (key_code == KEY_D)
		move(map, KEY_D);
	return (0);
}

void	next_mom(t_map *map, unsigned int *x, unsigned int *y, int key)
{
	*x = map->player.x;
	*y = map->player.y;
	if (key == KEY_W)
		(*y)--;
	else if (key == KEY_S)
		(*y)++;
	else if (key == KEY_A)
		(*x)--;
	else if (key == KEY_D)
		(*x)++;
}

void	move(t_map *map, int key)
{
	unsigned int	nx;
	unsigned int	ny;

	next_mom(map, &nx, &ny, key);
	if (map->map_char[ny][nx] == 'C')
		map->collect_cnt++;
	if (map->map_char[ny][nx] == 'E' && map->all_col_cnt == map->collect_cnt)
		exit_game(map);
	else if (map->map_char[ny][nx] != '1' && map->map_char[ny][nx] != 'E')
	{
		map->map_char[map->player.y][map->player.x] = '0';
		map->map_char[ny][nx] = 'P';
		map->player.x = nx;
		map->player.y = ny;
		draw_map(map, -1);
		map->player.mov_cnt++;
		ft_putstr_fd("move count : ", 1);
		ft_putnbr_fd(map->player.mov_cnt, 1);
		ft_putstr_fd("\n", 1);
	}
}
