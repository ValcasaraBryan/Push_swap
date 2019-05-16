/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 21:43:11 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/16 14:56:45 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_val	*new_lst(char **s)
{
	t_val		*new;

	if (!(new = (t_val *)malloc(sizeof(t_val))))
		return (NULL);
	new->val = ft_atoi(*s);
	new->next = NULL;
	new->prev = NULL;
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
	return (new);
}

void			erase_list(t_val **old)
{
	t_val		*tmp;

	if (!*old)
		return ;
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

static int		return_list(t_val **list, char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
	erase_list(list);
	return (0);
}

static int		add_lst(t_val **old, char **s)
{
	t_val		*tmp;
	t_val		*buf;

	tmp = NULL;
	if (!ft_number_ok(*s))
		return (return_list(old, s));
	if (!*old)
		return (!(*old = new_lst(s)) ? 0 : 1);
	tmp = *old;
	while (tmp->next)
	{
		if (tmp == (*old)->prev || tmp->val == ft_atoi(*s))
			break ;
		tmp = tmp->next;
	}
	if (tmp->val == ft_atoi(*s) || !(buf = new_lst(s)))
		return (return_list(old, s));
	tmp->next = buf;
	tmp->next->prev = tmp;
	tmp->next->next = *old;
	if ((*old)->prev != tmp->next)
		(*old)->prev = tmp->next;
	return (1);
}

t_val			*intsplit(t_val *split, const char *s, char c)
{
	size_t		i;
	size_t		j;
	char		*tmp;

	i = 0;
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
