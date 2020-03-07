/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_part2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:08:49 by cde-moul          #+#    #+#             */
/*   Updated: 2019/01/09 16:08:29 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_deltrip(char **list)
{
	int		a;

	a = 0;
	if (list != NULL && *list != NULL)
	{
		while (list[a] != NULL)
		{
			free((list)[a]);
			(list)[a] = NULL;
			a++;
		}
		free(list);
	}
}

static int	ft_reste2(char *buf, int i)
{
	int	count;

	count = 0;
	if (i == 6 || i == 7 || i == 11 || i == 12)
	{
		if (buf[i - 5] == '#')
			count++;
		if (buf[i - 1] == '#')
			count++;
		if (buf[i + 1] == '#')
			count++;
		if (buf[i + 5] == '#')
			count++;
	}
	if (i == 15)
	{
		if (buf[10] == '#')
			count++;
		if (buf[16] == '#')
			count++;
	}
	if (i != 6 && i != 7 && i != 11 && i != 12 && i != 15)
		return (ft_reste3(buf, i));
	return (count);
}

static int	ft_reste(char *buf, int i)
{
	int count;

	count = 0;
	if (i == 3)
	{
		if (buf[2] == '#')
			count++;
		if (buf[8] == '#')
			count++;
	}
	if (i == 5 || i == 10)
	{
		if (buf[i - 5] == '#')
			count++;
		if (buf[i + 1] == '#')
			count++;
		if (buf[i + 5] == '#')
			count++;
	}
	if (i != 3 && i != 5 && i != 10)
		return (ft_reste2(buf, i));
	return (count);
}

static int	ft_count(char *buf, int i)
{
	int count;

	count = 0;
	if (i == 0)
	{
		if (buf[1] == '#')
			count++;
		if (buf[5] == '#')
			count++;
	}
	if (i == 1 || i == 2)
	{
		if (buf[i - 1] == '#')
			count++;
		if (buf[i + 1] == '#')
			count++;
		if (buf[i + 5] == '#')
			count++;
	}
	if (i != 0 && i != 1 && i != 2)
		return (ft_reste(buf, i));
	return (count);
}

int			ft_verif(char *buf)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
			count = count + ft_count(buf, i);
		else if ((((i + 1) % 5) == 0 && buf[i] != '\n') ||\
				(((i + 1) % 5 != 0) && (buf[i] != '.' && buf[i] != '#')))
			return (0);
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}
