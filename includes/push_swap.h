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
# define S_ERR		2
# define S_STD		1
# define E_STD		1
# define TRUE		1
# define FALSE		0
# define LEN_OPTION	4
# define LEN_PRINT	2
# define OPTION_	"vhfp"
# define VERBOSE	0
# define HELP		1
# define FILE		2
# define PATTERN	3
# define MSG_HELP	"help :\n\n"
# define MSG_V		"-v\t\tverbose\n"
# define MSG_P		"-p\t\tpattern exemple\n"
# define MSG_F		"-f\t\tfile [file_name]\n"
# define MSG_H		"-h\t\tThis message\n"
# define MSG_U		"usage : ./checker [-%s] [pattern] [file]\n"
# define MSG_PA		"./checker -f [name_file]\n"
# define MSG_I		"checker: illegal option\n"
# define MSG_ERR	"Error\n"
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

/*
**					in main
**						in checker
*/
int					checker(int ac, char **av);
/*
**					in checker
**						in init_data
**						in check_val
**							in pars
**								in pars_option
**									in error_arg
**								in file_option
**									in pars_val_file
**									in error_val
**						in call_help
**							in print_help
**								in erase_data
**							in print_pattern
**								in print_pattern_one
**								in print_pattern_three
**								in erase_data
*/
void				init_data(t_data *data, int ac, char **av);
int					check_val(t_data *data);
int					pars(t_data *data, int index, int *file);
int					pars_option(t_data *data, char *tab);
int					error_arg(t_data *data, int val, char ***tab);
int					file_option(t_data *data, char *tab, int *file);
void				pars_val_file(t_data *data, char tab, int *file);
int					error_val(t_data *data, int val, char ***tab);
int					call_help(t_data *data);
int					print_help(t_data *data);
void				erase_data(t_data *data);
int					print_patern(t_data *data);
void				print_patern_one(t_data *data);
void				print_patern_three(t_data *data);

int					open_file(t_data *data);

t_val				*intsplit(const char *s, char c);

#endif
