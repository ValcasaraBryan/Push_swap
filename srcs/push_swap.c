/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:35:00 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/07 18:35:02 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_swap(char *str)
{
	ft_printf("%s\n", str);
	return (1);
}

int		main(int argc, char **argv)
{
	int i;

	if (argc == 1)
		ft_printf("ERROR\n");
	if (argc == 2)
	{
		push_swap(argv[1]);
	}
	if (argc > 2)
	{
		i = 1;
		while (i < argc)
			ft_printf("%s\n", argv[i++]);
	}
	return (0);
}