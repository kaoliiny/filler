/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 15:14:15 by exam              #+#    #+#             */
/*   Updated: 2019/02/17 16:43:38 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_int_tab(int *tab[1000], unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				exchange;

	j = 0;
	if (!tab || !*tab)
		return ;
	while (j < size)
	{
		i = j;
		while (i < size)
		{
			if (*tab[j] > *tab[i])
			{
				exchange = *tab[j];
				*tab[j] = *tab[i];
				*tab[i] = exchange;
			}
			i++;
		}
		j++;
	}
}
