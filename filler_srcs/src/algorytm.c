/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorytm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:14:13 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/04/24 19:12:06 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#define X		0
#define Y		1
#define MAP_Y_X	bot->data.map[res[Y]][res[X]]

static int	help_try_to_fit(t_bot *bot, int res[], int i, int *mine)
{
	(res[X] < 0) && (res[X] = bot->data.x_size - (res[X] * -1));
	(res[Y] < 0) && (res[Y] = bot->data.y_size - (res[Y] * -1));
	(ft_tolower(MAP_Y_X) == bot->me) && (*mine)++;
	if (ft_tolower(MAP_Y_X) == bot->opponent
	|| *mine > 1 || MAP_Y_X == '\0'
	|| (i == bot->data.piece_num - 1 && !*mine))
		return (0);
	return (1);
}

static int	try_to_fit(t_bot *bot, int y, int x, int ind)
{
	int		i;
	int		res[2];
	int		mine;
	int		d;
	int		tmp;

	i = -1;
	mine = 0;
	d = INT32_MAX;
	while (++i < bot->data.piece_num)
	{
		res[X] = x + bot->data.piece_x[i] - bot->data.piece_x[ind];
		res[Y] = y + bot->data.piece_y[i] - bot->data.piece_y[ind];
		if ((res[X] >= bot->data.x_size) || (res[Y] >= bot->data.y_size))
			return (0);
		if (!help_try_to_fit(bot, res, i, &mine))
			return (0);
		tmp = count_dst(bot, res[Y], res[X]);
		if (d >= tmp && (d = tmp) | 1)
			(d != INT32_MAX) && (bot->data.index = ind);
	}
	return (d);
}

static void	best_solution(t_bot *bot, int i, int j)
{
	int		d;
	int		index;

	d = 0;
	index = -1;
	while (++index < bot->data.piece_num)
	{
		d = try_to_fit(bot, i, j, index);
		if (d != 0 && bot->data.dst > d)
		{
			(bot->data.dst = d | 1)
			&& ((bot->data.x = j - bot->data.piece_x[bot->data.index]) | 1)
			&& (bot->data.y = i - bot->data.piece_y[bot->data.index]);
		}
	}
}

void		algo(t_bot *bot)
{
	int		i;
	int		j;

	i = 0;
	bot->data.y = 0;
	bot->data.x = 0;
	bot->data.dst = INT32_MAX;
	get_fig_coord(bot);
	while (bot->data.map[i])
	{
		j = -1;
		while (bot->data.map[i][++j])
		{
			if (ft_tolower(bot->data.map[i][j]) == bot->me
				&& !is_full(bot, i, j, bot->me))
				best_solution(bot, i, j);
		}
		i++;
	}
	ft_putnbr(bot->data.y);
	write(1, " ", 1);
	ft_putnbr(bot->data.x);
	write(1, "\n", 1);
}
