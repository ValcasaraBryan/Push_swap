/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:37:03 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/10 19:39:22 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define MSG		-2
# define ERROR		-1
# define TRUE		1
# define FALSE		0
# define LEN_OPTION	4
# define LEN_PRINT	2
# define OPTION_	"vhfp"
# define VERBOSE	0
# define HELP		1
# define FILE		2
# define PATTERN		3
# define MSG_HELP	"help :\n\n"
# define MSG_V		"-v\t\tverbose\n"
# define MSG_P		"-p\t\tpattern exemple\n"
# define MSG_F		"-f\t\tfile [file_name]\n"
# define MSG_H		"-h\t\tThis message\n"
# define MSG_U		"usage : ./checker [-%s] [pattern] [file]\n"
# define MSG_PA		"./checker -f [name_file]\n"
# define MSG_I		"checker: illegal option\n"
# define MESSAGE_H	MSG_HELP MSG_V MSG_P MSG_F MSG_H MSG_U

typedef struct		s_val
{
	int				val;
	struct s_val	*prev;
	struct s_val	*next;
}					t_val;

typedef struct		s_data
{
	char			**av;
	int				len;
	t_val			*tab;
	char			*arg;
	int				option[LEN_OPTION];
	int				index;
	int				fd;
}					t_data;

int					push_swap(char *str);

int					pars_option(t_data *data);
int					checker(int ac, char **av);
int					open_file(t_data *data);

void				erase_data(t_data *data);
void				error_arg(t_data *data);
int					print_help(t_data *data);
int					print_patern(t_data *data);
void				print_patern_one(t_data *data);
void				print_patern_two(t_data *data);
void				print_patern_three(t_data *data);

t_val				*intsplit(const char *s, char c);

#endif
