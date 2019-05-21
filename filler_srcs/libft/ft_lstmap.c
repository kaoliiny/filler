/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 00:16:42 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/03/07 18:26:10 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*created;
	t_list	*frez;

	if (!lst || !f)
		return (NULL);
	frez = (*f)(lst);
	new = ft_lstnew(frez->content, frez->content_size);
	created = new;
	lst = lst->next;
	while (lst != NULL)
	{
		frez = (*f)(lst);
		if (!(created->next = ft_lstnew(frez->content,
			frez->content_size)))
			return (NULL);
		created = created->next;
		lst = lst->next;
	}
	return (new);
}
