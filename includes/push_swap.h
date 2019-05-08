/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:37:03 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/07 18:37:04 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

enum option { verbose = 'v', help = 'h' };

typedef struct		s_data
{
	char			**av;
	char			**tab;
	int				len;
	int				index;
	int				fd;
	int				option;
}					t_data;

int		push_swap(char *str);

int		pars_arg(t_data *data);
int		pars_option(t_data *data);
int		checker(int ac, char **av);

#endif