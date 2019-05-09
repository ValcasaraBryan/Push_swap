/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:38:35 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/09 21:14:01 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_str_is_int(char *str)
{
	int		i;

	if (!str)
		return (0);
    i = 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
	if (ft_strlen(str + i) > 10)
        return (0);
	while (str[i])
		if (!(ft_isdigit(str[i++])))
			return (0);
	return (1);
}
