/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_enter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:30:21 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/16 15:43:28 by brvalcas         ###   ########.fr       */
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

int			read_enter(t_data *data)
{
	int		ret;
	char	*line;
	
	while ((ret = get_next_line(0, &line)) > 0)
	{
		add_ope(&data->ope, ft_strdup(line));
		free(line);
		line = NULL;
	}
	return (1);
}