/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 21:43:11 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/10 16:37:12 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_val	*return_list(t_val *list, char **s)
{
	free(*s);
	*s = NULL;
	return (list);
}

static t_val	*new_lst(char **s)
{
	t_val		*new;

	if (!ft_str_is_int(*s))
		return (return_list(NULL, s));
	if (!(new = (t_val *)malloc(sizeof(t_val))))
		return (return_list(NULL, s));
	new->val = ft_atoi(*s);
	new->next = NULL;
	new->prev = NULL;
	return (return_list(new, s));
}

void			erase_list(t_val **old)
{
	t_val		*tmp;

	if ((*old)->prev)
		(*old)->prev->next = NULL;
	while (*old)
	{
		tmp = (*old)->next;
		free((*old));
		(*old) = NULL;
		(*old) = tmp;
	}
}

static int		add_lst(t_val **old, char **s)
{
	t_val		*tmp;
	t_val		*buf;

	tmp = NULL;
	if (!*old)
		return (!(*old = new_lst(s)) ? 0 : 1);
	tmp = *old;
	while (tmp->next)
	{
		if (tmp == (*old)->prev)
			break ;
		tmp = tmp->next;
	}
	if (!(buf = new_lst(s)))
	{
		erase_list(old);
		return (0);
	}
	tmp->next = buf;
	tmp->next->prev = tmp;
	tmp->next->next = *old;
	if ((*old)->prev != tmp->next)
		(*old)->prev = tmp->next;
	return (1);
}

t_val			*intsplit(const char *s, char c)
{
	size_t		i;
	size_t		j;
	t_val		*split;
	char		*tmp;

	i = 0;
	split = NULL;
	tmp = NULL;
	while (s[i])
	{
		j = i;
		while (s[i] != c && s[i])
			i++;
		if ((s[j] != c && s[i] == c) || !s[i])
		{
			tmp = ft_strndup(&s[j], i - j);
			if (!(add_lst(&split, &tmp)))
				return (NULL);
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (split);
}
