/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 23:14:13 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/04/22 21:40:12 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_fig_coord(t_bot *bot)
{
	int		i;
	int		j;

	i = 0;
	bot->data.piece_num = 0;
	while (bot->data.piece[i] && (j = -1))
	{
		while (bot->data.piece[i][++j])
			if (bot->data.piece[i][j] == '*')
			{
				bot->data.piece_y[bot->data.piece_num] = i;
				bot->data.piece_x[bot->data.piece_num++] = j;
			}
		i++;
	}
}

bool	is_full(t_bot *bot, int i, int j, char x)
{
	return ((i + 1 < bot->data.y_size && j + 1 < bot->data.x_size
		&& i >= 0 && j >= 0
		&& (FULL(0, 1) == '\0' || FULL(0, 1)) == x)
		&& (FULL(1, 1) == '\0' || FULL(1, 1) == x)
		&& (FULL(1, 0) == '\0' || FULL(1, 0) == x)
		&& (FULL(0, -1) == '\0' || FULL(0, -1) == x)
		&& (FULL(-1, 0) == '\0' || FULL(-1, 0) == x)
		&& (FULL(-1, -1) == '\0' || FULL(-1, -1) == x));
}

int		count_dst(t_bot *bot, int y, int x)
{
	int		i;
	int		j;
	int		m;
	int		man;

	i = 0;
	j = 0;
	m = INT32_MAX;
	while (bot->data.map[i])
	{
		j = -1;
		while (bot->data.map[i][++j])
			if (ft_tolower(bot->data.map[i][j]) == bot->opponent
			&& !is_full(bot, i, j, bot->opponent))
			{
				man = ABS(x - j) + ABS(y - i);
				m = (m > man) ? man : m;
			}
		i++;
	}
	return (m);
}
