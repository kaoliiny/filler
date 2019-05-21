/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:19:26 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/01/07 14:14:00 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *el;

	if (!alst || !new)
		return ;
	el = *alst;
	new->next = *alst;
	*alst = new;
}
