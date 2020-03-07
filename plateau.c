/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plateau.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:12:45 by cde-moul          #+#    #+#             */
/*   Updated: 2019/01/14 10:37:38 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_fullroot(int nb)
{
	int i;

	i = 0;
	while (i < 2147483647 && nb > 0)
	{
		if (i > 46340)
			return (0);
		if (i * i >= nb)
			return (i);
		i++;
	}
	return (0);
}

int			ft_listsize(t_piece *list)
{
	int	size;

	size = 0;
	if (list)
	{
		while (list)
		{
			size++;
			list = list->next;
		}
	}
	return (size);
}

int			ft_init_tab(int size, char ***tab)
{
	int	ligne;
	int col;

	ligne = -1;
	if (*tab)
		ft_deltrip(*tab);
	if (!(*tab = (char **)malloc(sizeof(char *) * (size + 2))))
		return (0);
	while (++ligne < size)
	{
		col = -1;
		if (!((*tab)[ligne] = (char *)malloc(sizeof(char) * (size + 2))))
			return (0);
		while (++col < size)
			(*tab)[ligne][col] = '.';
		(*tab)[ligne][col] = '\n';
		(*tab)[ligne][col + 1] = '\0';
	}
	col = -1;
	if (!((*tab)[ligne] = (char *)malloc(sizeof(char) * size)))
		return (0);
	while (++col < size)
		(*tab)[ligne][col] = '\0';
	(*tab)[++ligne] = NULL;
	return (1);
}

static int	ft_lettre(char lettre, t_piece **list)
{
	if (lettre > 'Z')
	{
		ft_listdel(list);
		return (0);
	}
	return (1);
}

int			ft_whileread(t_piece **list, char lettre, int ret, int fd)
{
	char	buf[21];
	char	**clear;

	ret = read(fd, buf, 20);
	while (ret >= 1)
	{
		buf[ret] = '\0';
		if (ft_lettre(lettre, list) == 0)
			return (0);
		ret = ft_check((&clear), buf, lettre);
		if (ft_read2(list, &clear, lettre, ret) == 0)
			return (0);
		lettre++;
		ret = read(fd, buf, 1);
		if (ret != 0 && ft_read3(list, buf) == 0)
			return (0);
		if (ret == 1)
		{
			ret = read(fd, buf, 20);
			if (ret == 0)
				return (0);
		}
	}
	return (1);
}
