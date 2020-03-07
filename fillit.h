/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-moul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:51:23 by cde-moul          #+#    #+#             */
/*   Updated: 2019/01/10 09:29:03 by cde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include "libft/libft.h"
# include "fcntl.h"
# include <stdio.h>

typedef	struct	s_piece
{
	char			lettre;
	char			**forme;
	int				pos[2];
	struct s_piece	*next;
	struct s_piece	*previous;
}				t_piece;

t_piece			*ft_read(int fd);
int				ft_reste3(char *buf, int i);
int				ft_game(t_piece *list, char ***tab);
int				ft_add_link(t_piece **list, char **buf, char lettre);
int				ft_check(char ***clear, char *buf, char lettre);
int				ft_verif(char *buf);
int				ft_fullroot(int nb);
int				ft_init_tab(int size, char ***tab);
int				ft_listsize(t_piece *list);
int				ft_place(t_piece **list, char ***tab, char lettre);
int				ft_while(char ***tmp, char *buf);
int				ft_checkcol(char ***clear, char ***tmp, char lettre);
int				ft_checkif(char ***tmp, char ***clear, char *buf, char lettre);
int				ft_read2(t_piece **list, char ***clear, char lettre, int ret);
int				ft_read3(t_piece **list, char *buf);
int				ft_whileread(t_piece **list, char lettre, int ret, int fd);
void			ft_deltrip(char **list);
void			ft_listdel(t_piece **list);
void			ft_remove(char ***tab, char lettre);
void			printtab(char ***tab);

#endif
