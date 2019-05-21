/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:03:35 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/04/22 20:25:26 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

bool			manage_error(void)
{
	ft_putendl_fd("error\n", 2);
	exit(-1);
}

void			player_ident(t_bot *bot, char *line)
{
	if (ft_strstr(line, "p1"))
	{
		bot->me = P1;
		bot->opponent = P2;
	}
	else
	{
		bot->me = P2;
		bot->opponent = P1;
	}
}

static void		create_piece(t_bot *bot, int y)
{
	int		i;
	char	*line;

	if (!(bot->data.piece = (char **)ft_memalloc(sizeof(char *) * (y + 1))))
		return ;
	bot->data.piece[y] = NULL;
	i = -1;
	while (++i < y)
	{
		(get_next_line(0, &line)) && (bot->data.piece[i] = strdup(line));
		free(line);
	}
}

static void		create_map(t_bot *bot, int y)
{
	int		i;
	char	*line;

	i = -1;
	get_next_line(0, &line);
	free(line);
	if (!(bot->data.map = (char **)ft_memalloc(sizeof(char *) * (y + 1))))
		return ;
	bot->data.map[y] = NULL;
	while (++i < y)
	{
		(get_next_line(0, &line)) && (bot->data.map[i] = strdup(line + 4));
		free(line);
	}
}

int				main(void)
{
	char	*line;
	int		byte;
	t_bot	*bot;

	bot = (t_bot*)malloc(sizeof(t_bot));
	while ((byte = get_next_line(0, &line)) > 0)
	{
		if (ft_strstr(line, "Plateau"))
		{
			create_map(bot, bot->data.y_size = ft_atoi(line + 8));
			bot->data.x_size = ft_atoi(line + 11);
		}
		else if (ft_strstr(line, "Piece"))
		{
			create_piece(bot, ft_atoi(line + 6));
			algo(bot);
			free_array(&bot->data.map);
			free_array(&bot->data.piece);
		}
		else if (ft_strstr(line, "$$$ "))
			player_ident(bot, line);
		free(line);
	}
	(byte < 0) && manage_error();
	return (0);
}
