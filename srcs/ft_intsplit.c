/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 21:43:11 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/09 22:42:13 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_val	*new_lst(const char *s)
{
	t_val		*new;

	if (!(new = (t_val *)malloc(sizeof (t_val))))
		return (NULL);
	if (!ft_str_is_int((char *)s))
		return (NULL);
	new->val = ft_atoi(s);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static void		add_lst(t_val **old, const char *s)
{
	t_val		*tmp;

	tmp = NULL;
	if (!*old)
	{
        *old = new_lst(s);
        return ;
	}
	tmp = *old;
	while (tmp->next)
    {
        if (tmp == (*old)->prev)
            break ;
    	tmp = tmp->next;
    }
	tmp->next = new_lst(s);	
	tmp->next->prev = tmp;
    tmp->next->next = *old;
    if ((*old)->prev != tmp->next)
        (*old)->prev = tmp->next;
}

t_val			*intsplit(const char *s, char c)
{
	size_t	i;
	size_t	j;
	t_val	*split;

	i = 0;
	split = NULL;
	while (s[i])
	{
		j = i;
		while (s[i] != c && s[i])        
			i++;
		if ((s[j] != c && s[i] == c) || !s[i])
			add_lst(&split, ft_strndup(&s[j], i - j));
		while (s[i] == c && s[i])
			i++;
	}
	return (split);
}
