/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:19:24 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/16 14:47:51 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_number_ok(char *str)
{
	if (ft_str_is_number(str) && ft_str_is_int(str))
		return (1);
	else
		return (0);
}

int			ft_str_is_number(char *str)
{
	int		neg;

	if (!str)
		return (0);
	neg = 0;
	if (str[neg] == '-' || str[neg] == '+')
		neg++;
	if (ft_str_is_digit(&str[neg]))
		return (1);
	else
		return (0);
}

int			ft_is_option(char *str, char *option)
{
	int		i;

	i = 0;
	if (ft_number_ok(str))
		return (FALSE);
	while (str[++i])
		if (params(str[i], option) == FALSE)
			return (FALSE);
	return (i > 1 ? TRUE : FALSE);
}
