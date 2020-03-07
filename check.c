/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:20:22 by cde-moul          #+#    #+#             */
/*   Updated: 2019/01/09 15:32:56 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_moins_col(char ***clear, char ***tmp, int start, int end)
{
	int		a;
	int		ligne;
	int		i;
	char	*bob;

	bob = NULL;
	ligne = 0;
	a = 0;
	i = 0;
	while ((tmp[0])[ligne])
	{
		if (!((clear[0])[ligne] = ft_strsub((tmp[0])[ligne],\
						start, (end - start + 1))))
			return (0);
		ligne++;
	}
	while (ligne < 5)
	{
		(clear[0])[ligne] = NULL;
		ligne++;
	}
	ft_deltrip(tmp[0]);
	return (1);
}

static char		*ft_tab(char *buf, int start, int end)
{
	int		i;
	int		point;

	i = 0;
	point = 0;
	while ((start + i) < end)
	{
		if (buf[start + i] == '.')
			point++;
		i++;
	}
	if (point == 4)
		return (NULL);
	else
		return (ft_strsub(buf, start, 4));
}

int				ft_checkcol(char ***clear, char ***tmp, char lettre)
{
	int		col;
	int		ligne;
	int		start;
	int		end;

	start = -1;
	end = -1;
	col = -1;
	ligne = -1;
	while ((tmp)[0][++ligne])
	{
		while ((tmp)[0][ligne][++col])
		{
			if ((tmp)[0][ligne][col] == '#')
			{
				(tmp)[0][ligne][col] = lettre;
				if ((col < start) || (start == -1))
					start = col;
				else if (col > end)
					end = col;
			}
		}
		col = -1;
	}
	return (ft_moins_col(clear, tmp, start, end));
}

int				ft_while(char ***tmp, char *buf)
{
	int	i;
	int ligne;
	int point;

	ligne = 0;
	point = 0;
	i = 0;
	if (ft_verif(buf) == 0)
		return (0);
	while (buf[i])
	{
		if (((i + 1) % 5) == 0)
		{
			(tmp)[0][ligne] = ft_tab(buf, i - 4, i);
			if ((tmp)[0][ligne] != NULL)
				ligne++;
		}
		else if (buf[i] == '.')
			point++;
		i++;
	}
	ligne--;
	while (++ligne < 5)
		(tmp)[0][ligne] = NULL;
	return ((point == 12) ? 1 : 0);
}

int				ft_check(char ***clear, char *buf, char lettre)
{
	char	**tmp;
	int		a;

	a = 0;
	tmp = NULL;
	if (!(clear[0] = (char **)malloc(sizeof(char *) * 5))\
			|| (!(tmp = (char **)malloc(sizeof(char *) * 5))))
	{
		if (clear[0])
			ft_deltrip(clear[0]);
		if (tmp)
			ft_deltrip(tmp);
		return (0);
	}
	return (ft_checkif(&tmp, clear, buf, lettre));
}
