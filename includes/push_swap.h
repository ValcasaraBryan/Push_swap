/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:37:03 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/15 21:56:53 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define FLAG_O		data->option
# define FILE		data->no_file
# define EDIT_		data->no_edit
# define OPT		data->no_option
# define SPLIT		data->split
# define I			index_split

# define MSG		-2
# define ERROR		-1
# define S_ERR		2
# define S_STD		1
# define E_STD		1
# define TRUE		1
# define FALSE		0
# define LEN_OPTION	4
# define LEN_PRINT	2
# define OPTION_	"vhpe"
# define FILE_OP	"f"
# define VERBOSE	0
# define HELP		1
# define PATTERN	2
# define EDIT		3
# define MSG_HELP	"help :\n\n"
# define MSG_V		"-v\t\tverbose\n"
# define MSG_P		"-p\t\tpattern exemple\n"
# define MSG_F		"-f\t\tfile [file_name] (for input)\n"
# define MSG_H		"-h\t\tThis message\n"
# define MSG_E		"-e\t\tedit [edit_name] (for output)\n"
# define MSG_U		"usage : ./checker [-%s] [edit] [pattern] [file]\n"
# define MSG_PA		"-f [file_name]\n"
# define MSG_I		"checker: illegal option -- %s\n"
# define MSG_ERR	"Error\n"
# define F_DOES		"File doesn't existe\n"
# define F_NMIS		"File name missing\n"
# define E_NMIS		"Edit name missing\n"
# define E_FERR		"Edit file error\n"
# define MESSAGE_H	MSG_HELP MSG_V MSG_P MSG_F MSG_E MSG_H MSG_U

typedef struct		s_val
{
	int				val;
	struct s_val	*prev;
	struct s_val	*next;
}					t_val;

typedef struct		s_data
{
	char			**av;
	char			**split;
	int				no_option;
	int				no_file;
	int				no_edit;
	int				index;
	int				index_split;
	int				len;
	int				len_split;
	t_val			*tab;
	int				option[LEN_OPTION];
	int				fd;
	int				output;
	char			*edit;
}					t_data;

/*
**					in main
**						in checker
*/
int					checker(int ac, char **av);
/*
**					parsing.c
*/
int					pars(t_data *data);
int					check_option(t_data *data);
int					check_no_option(t_data *data);
int					active_option(t_data *data, int i, int a);
int					active_no_option(t_data *data, int i);
/*
**					files.c
*/
int					open_edit(t_data *data);
int					open_file(t_data *data);
int					take_file(t_data *data);
int					split_file(t_data *data, char *line);
/*
**					check_arg.c
*/
int					ft_number_ok(char *str);
int					ft_str_is_number(char *str);
int					ft_is_option(char *str, char *option);
/*
**					print_pattern.c
*/
int					print_pattern(t_data *data);
void				print_patern_one(t_data *data);
int					check_arg(t_data *data);
int					check_other_arg(t_data *data, int i);
void				print_patern_three(t_data *data);
/*
**					error.c
*/
int					error_val(t_data *data);
int					error_arg(t_data *data);
int					error_file(t_data *data);
int					error_edit(t_data *data);
/*
**					print_messages.c
*/
int					print_msg(t_data *data, int val);
int					print_help(t_data *data);
void				print_arg(char *str, int val);
/*
**					utils.c
*/
void				init_data(t_data *data, int ac, char **av);
void				print_list(t_data *data, t_val *head);
int					verbose(t_data *data);

t_val				*intsplit(t_val *split, const char *s, char c);
void				erase_list(t_val **old);

#endif
