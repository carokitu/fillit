/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:43:53 by cde-moul          #+#    #+#             */
/*   Updated: 2019/01/09 15:28:36 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_remove(char ***tab, char lettre)
{
	int	ligne;
	int	col;

	col = 0;
	ligne = 0;
	while ((*tab)[ligne])
	{
		while (((*tab)[ligne])[col])
		{
			if (((*tab)[ligne])[col] == lettre)
				((*tab)[ligne])[col] = '.';
			col++;
		}
		ligne++;
		col = 0;
	}
}

int		ft_pose(int *pos, char **forme, char ***tab)
{
	int	l;
	int	c;
	int	ligne;
	int	col;

	ligne = -1;
	c = pos[1];
	l = pos[0];
	while (forme[++ligne])
	{
		col = 0;
		c = pos[1];
		while ((forme[ligne])[col])
		{
			if (((*tab)[l])[c] == '.')
				((*tab)[l])[c] = forme[ligne][col];
			else if (((*tab)[l])[c] == '\0' ||\
					(((*tab)[l])[c] != '.' && (forme[ligne])[col] != '.'))
				return (0);
			col++;
			c++;
		}
		l++;
	}
	return (1);
}

int		ft_place(t_piece **list, char ***tab, char lettre)
{
	while ((*list)->lettre != lettre)
		(*list) = (*list)->next;
	while (((*list)->pos)[0] == -1 ||\
			((*tab)[((*list)->pos)[0]])[((*list)->pos)[1]] != '\0')
	{
		if (((*list)->pos)[0] == -1)
			((*list)->pos)[0]++;
		else
		{
			((*list)->pos)[1]++;
			if (((*tab)[((*list)->pos)[0]][((*list)->pos)[1]]) == '\n')
			{
				((*list)->pos)[0]++;
				((*list)->pos)[1] = 0;
			}
		}
		if (ft_pose((*list)->pos, (*list)->forme, tab) == 0)
			ft_remove(tab, (*list)->lettre);
		else
			return (1);
	}
	((*list)->pos[0]) = -1;
	((*list)->pos[1]) = 0;
	return (0);
}

int		ft_game(t_piece *list, char ***tab)
{
	int	ligne;
	int size;

	ligne = 0;
	size = ft_fullroot(ft_listsize(list) * 4);
	ft_init_tab(size, tab);
	while (list)
	{
		if (ft_place(&list, tab, list->lettre) == 0)
		{
			if (list->previous == NULL)
				ft_init_tab(size++, tab);
			else
			{
				list = list->previous;
				ft_remove(tab, list->lettre);
			}
		}
		else
			list = list->next;
	}
	printtab(tab);
	ft_deltrip(*tab);
	return (1);
}
