/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_enter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:30:21 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/16 16:25:41 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ope		*new_ope(char *str)
{
	t_ope	*new;

	if (!(new = malloc(sizeof(t_val))))
		return (NULL);
	new->ope = str;
	new->next = NULL;
	return (new);
}

void		add_ope(t_ope **old, char *str)
{
	t_ope	*tmp;

	if (!*old)
		*old = new_ope(str);
	else
	{
		tmp = *old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_ope(str);
	}
}

void		erase_ope(t_data *data)
{
	t_ope	*tmp;

	if (!data->ope)
		return ;
	while (data->ope)
	{
		tmp = data->ope->next;
		if (data->ope->ope)
		{
			free(data->ope->ope);
			data->ope->ope = NULL;
		}
		free(data->ope);
		data->ope = NULL;
		data->ope = tmp;
	}
}

int			read_enter(t_data *data)
{
	int		ret;
	char	*line;
	
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!(check_ope(data, line)))
		{
			get_next_line(0, NULL);
			if (line)
			{
				free(line);
				line = NULL;	
			}
			erase_ope(data);
			return (0);
		}
		add_ope(&data->ope, ft_strdup(line));
		free(line);
		line = NULL;
	}
	return (1);
}