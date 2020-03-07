/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:11:35 by cde-moul          #+#    #+#             */
/*   Updated: 2019/01/10 09:12:13 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		printtab(char ***tab)
{
	int ligne;

	ligne = 0;
	while ((*tab)[ligne] != NULL)
	{
		ft_putstr((*tab)[ligne]);
		ligne++;
	}
}

static int	ft_reste4(char *buf, int i)
{
	int	count;

	count = 0;
	if (i == 18)
	{
		if (buf[17] == '#')
			count++;
		if (buf[13] == '#')
			count++;
	}
	return (count);
}

int			ft_reste3(char *buf, int i)
{
	int	count;

	count = 0;
	if (i == 8 || i == 13)
	{
		if (buf[i - 5] == '#')
			count++;
		if (buf[i - 1] == '#')
			count++;
		if (buf[i + 5] == '#')
			count++;
	}
	if (i == 16 || i == 17)
	{
		if (buf[i - 1] == '#')
			count++;
		if (buf[i - 5] == '#')
			count++;
		if (buf[i + 1] == '#')
			count++;
	}
	if (i == 18)
		return (ft_reste4(buf, i));
	return (count);
}

int			ft_checkif(char ***tmp, char ***clear, char *buf, char lettre)
{
	int	a;

	a = ft_while(tmp, buf);
	if ((a == 0) || ft_checkcol(clear, tmp, lettre) == 0)
	{
		if ((*clear) && a != 0)
		{
			ft_deltrip(clear[0]);
			ft_deltrip(tmp[0]);
		}
		else if ((*clear) && a == 0)
		{
			free(*clear);
			free(*tmp);
		}
		return (0);
	}
	return (1);
}

int			ft_read3(t_piece **list, char *buf)
{
	if (*buf != '\n' && *buf != '\0')
	{
		if (*list)
			ft_listdel(list);
		return (0);
	}
	return (1);
}
