/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:54:20 by cde-moul          #+#    #+#             */
/*   Updated: 2019/01/16 16:08:01 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_piece *list;
	char	**tab;

	tab = NULL;
	if (argc != 2)
	{
		if (argc < 2)
			ft_putstr("usage : ajouter un fichier en parametre\n");
		else
			ft_putstr("usage : ne mettre qu'un seul fichier en parametre\n");
		return (0);
	}
	if (!(list = ft_read(open(argv[1], O_RDONLY))))
	{
		ft_putstr("error\n");
		return (0);
	}
	if (ft_game(list, &tab) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_listdel(&list);
	return (1);
}
