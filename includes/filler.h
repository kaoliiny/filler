/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 18:47:56 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/04/24 18:50:21 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define P1 'o'
# define P2 'x'

# define FULL(ii, ji) (bot->data.map[i + ii][j + ji])

# define ABS(Value) ((Value) < 0 ? -(Value) : (Value))

typedef struct	s_data
{
	char		**map;
	char		**piece;
	int			y_size;
	int			x_size;

	short int	piece_x[20];
	short int	piece_y[20];
	int			piece_num;
	int			dst;
	int			index;
	int			x;
	int			y;
}				t_data;

typedef struct	s_bot
{
	struct s_data	data;
	char			me;
	char			opponent;
}				t_bot;

void			algo(t_bot *bot);

bool			manage_error(void);

void			player_ident(t_bot *bot, char *line);
void			maps_create(t_bot *bot, bool x);

bool			is_full(t_bot *bot, int i, int j, char x);
int				count_dst(t_bot *bot, int y, int x);
void			get_fig_coord(t_bot *bot);

#endif
