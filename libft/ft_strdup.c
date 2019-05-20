/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:04:42 by amazhara          #+#    #+#             */
/*   Updated: 2018/10/29 17:11:12 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*strcp;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	strcp = (char *)malloc(sizeof(char) * (len) + 1);
	if (strcp == '\0')
		return (NULL);
	while (i < len)
	{
		strcp[i] = str[i];
		i++;
	}
	strcp[i] = '\0';
	return (strcp);
}
