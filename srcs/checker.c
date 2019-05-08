/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:35:00 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/07 18:35:02 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_arg(t_data *data)
{
	if (data->tab != data->av)
		free_tab_str(&data->tab);
	ft_printf("usage : ./checker [-vhfp] [--help] [patern] [file]\n");
	exit (0);
}

void	print_patern_one(t_data *data)
{
	int	i;

	i = data->index;
	ft_printf("./checker ");
	if (i < data->len - 1 && data->len > 3)
		while (++i < data->len)
		{
			ft_printf("%s", data->tab[i]);
			if (i < data->len - 1)
				ft_printf(" ");
			else
				ft_printf("\n");
		}
	else
		ft_printf("1 2 3 4\n");
}

void	print_patern_two(t_data *data)
{
	int	i;

	i = data->index;
	ft_printf("./checker \"");
	if (i < data->len - 1 && data->len > 3)
		while (++i < data->len)
		{
			ft_printf("%s", data->tab[i]);
			if (i < data->len - 1)
				ft_printf(" ");
			else
				ft_printf("\"\n");
		}
	else
		ft_printf("1 2 3 4\"\n");
}

void	print_patern_three(t_data *data)
{
	ft_printf("./checker -f [name_file]\n");
	ft_printf("file -> all value on only one line separated by space caracter.\n\n", data->tab[data->index + 1]);
}

int		pars_option(t_data *data)
{
	int	i;

	i = 0;
	while (*(data->tab[data->index] + i) == '-' && *(data->tab[data->index] + i))
		i++;
	if (!ft_strcmp(data->tab[data->index] + i, "help") || !ft_strcmp((data->tab[data->index] + i), "h"))
	{
		ft_printf("help :\n\n");
		ft_printf("-v\t\tverbose\n");
		ft_printf("-p\t\tpatern exemple\n");
		ft_printf("-f\t\tfile [name_file]\n");
		ft_printf("-h / --help\tThis message\n");
		ft_printf("\n");
		error_arg(data);
	}
	else if (!ft_strcmp((data->tab[data->index] + i), "v"))
	{
		data->option++;
		return (1);
	}
	else if (!ft_strcmp((data->tab[data->index] + i), "p"))
	{
		print_patern_one(data);
		print_patern_two(data);
		print_patern_three(data);
		error_arg(data);
	}
	else if (!ft_strcmp((data->tab[data->index] + i), "f"))
	{
		if (data->index + 1 == data->len - 1)
		{
			if ((data->fd = open(data->tab[data->index + 1], O_RDWR)) <= -1)
			{
				ft_printf("Wrong file\n");
				error_arg(data);
			}
			else
			{
				ft_printf("open file\n");
				return (0);
			}
		}
		else if (data->index + 1 < data->len - 1)
		{
			ft_printf("Too many arguments\n");
			error_arg(data);
		}
		else
		{
			ft_printf("Missing file name\n");
			error_arg(data);
		}
	}
	else
	{
		ft_printf("checker: illegal option\n");
		error_arg(data);
	}
	return (0);
}

int		pars_arg(t_data *data)
{
	long long	nb;

	if (!data->tab)
		return (0);
	nb = ft_atoll(data->tab[data->index]);
	if (nb == 0)
	{
		if (*data->tab[data->index] != '-' && !ft_str_is_digit(data->tab[data->index]))
			return (0);
		else if (*data->tab[data->index] == '-')
			if (!(pars_option(data)))
				return (0);
	}
	return (1);
}

int			checker(int ac, char **av)
{
	t_data	data;

	data.index = 0;
	data.tab = NULL;
	data.len = ac;
	data.av = av;
	data.fd = -1;
	data.option = 0;
	if (data.len <= 1)
		return (0);
	if (data.len == 2)
	{
		if (!(data.tab = ft_strsplit(av[1], ' ')))
			return (0);
		data.len = ft_len_tab_str(data.tab);
		data.index = -1;
	}
	else
		data.tab = av;
	while (++data.index < data.len)
	{
		if (pars_arg(&data) && data.tab[data.index] && data.option == 0)
			ft_printf("%s\n", data.tab[data.index]);
		else
		{
			if (data.tab != av)
				free_tab_str(&data.tab);
			return (0);
		}
	}
	if (data.tab != av)
		free_tab_str(&data.tab);
	return (1);
}

int		main(int argc, char **argv)
{
	if (!(checker(argc, argv)))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (0);
}