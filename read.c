/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:48:35 by cde-moul          #+#    #+#             */
/*   Updated: 2019/01/14 10:48:39 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_listdel(t_piece **list)
{
	t_piece *bubble;

	while (*list)
	{
		bubble = *list;
		(*list)->lettre = 0;
		ft_deltrip(((*list)->forme));
		*list = (*list)->next;
		free(bubble);
	}
}

static void	ft_bubble(t_piece *bubble, t_piece **list, t_piece *piece)
{
	bubble = *list;
	while (bubble->next != NULL)
		bubble = bubble->next;
	bubble->next = piece;
	piece->previous = bubble;
}

int			ft_add_link(t_piece **list, char **buf, char lettre)
{
	t_piece *piece;
	t_piece *bubble;

	bubble = NULL;
	if (!(piece = (t_piece *)malloc(sizeof(t_piece))))
		return (0);
	if (piece)
	{
		piece->lettre = lettre;
		piece->forme = buf;
		piece->next = NULL;
		piece->pos[0] = -1;
		piece->pos[1] = 0;
		if (*list == NULL)
			piece->previous = NULL;
	}
	if (!(*list))
		*list = piece;
	else
		ft_bubble(bubble, list, piece);
	return (1);
}

int			ft_read2(t_piece **list, char ***clear, char lettre, int ret)
{
	if (ret == 0 || ft_add_link(list, *clear, lettre) == 0)
	{
		if ((*clear) != 0 && ret != 0)
			ft_deltrip(*clear);
		if (*list)
			ft_listdel(list);
		return (0);
	}
	return (1);
}

t_piece		*ft_read(int fd)
{
	int		ret;
	char	lettre;
	t_piece	*list;
	char	**clear;

	lettre = 'A';
	list = NULL;
	clear = NULL;
	ret = 0;
	if (ft_whileread(&list, lettre, ret, fd) == 0)
		return (0);
	return (list);
}
