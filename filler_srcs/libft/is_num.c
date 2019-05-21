/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:25:10 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/03/08 17:59:58 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_num(const char *str, void (*f)(int), int error_num)
{
	if (!str)
		return (false);
	while (*str)
		if (!ft_isdigit((int)*str) && *str != '-')
			f(error_num);
		else
			str++;
	return (true);
}
