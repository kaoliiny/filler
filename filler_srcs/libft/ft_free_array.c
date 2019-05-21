/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:52:34 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/03/07 18:28:06 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_array(char ***free_me)
{
	int	i;

	i = 0;
	while ((*free_me)[i])
		free((*free_me)[i++]);
	free(*free_me);
	free_me = NULL;
}
