/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:17:05 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/16 00:13:24 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			open_edit(t_data *data)
{
	if ((data->output = open(data->edit, O_RDWR
		| O_CREAT, S_IRUSR + S_IWUSR + S_IRGRP + S_IROTH)) == -1)
	{
		ft_fprintf(E_FERR, S_ERR);
		return (ERROR);
	}
	return (TRUE);
}

int			open_file(t_data *data)
{
	if ((data->fd = open(SPLIT[data->I], O_RDONLY)) == -1)
	{
		ft_fprintf(F_DOES, S_ERR);
		return (ERROR);
	}
	if (take_file(data) == ERROR)
	{
		erase_list(&data->tab);
		close(data->fd);
		return (ERROR);
	}
	close(data->fd);
	return (TRUE);
}

int			take_file(t_data *data)
{
	char	*line;
	int		ret;

	line = NULL;
	while ((ret = get_next_line(data->fd, &line)) > 0)
	{
		if (split_file(data, line) == ERROR)
		{
			free(line);
			line = NULL;
			return (ERROR);
		}
		free(line);
		line = NULL;
	}
	return (TRUE);
}

int			split_file(t_data *data, char *line)
{
	char	**tab;
	int		i;

	if (!(tab = ft_strsplit(line, ' ')))
		return (ERROR);
	i = -1;
	while (tab[++i])
	{
		if (ft_number_ok(tab[i]))
			data->tab = intsplit(data->tab, tab[i], ' ');
		else
		{
			ft_fprintf(MSG_ERR, S_ERR);
			free_tab_str(&tab);
			return (ERROR);
		}
	}
	free_tab_str(&tab);
	return (TRUE);
}
