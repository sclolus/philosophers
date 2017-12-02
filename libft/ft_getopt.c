/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:44:09 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/24 01:04:12 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

#ifdef GETOPT_ON

char				*g_optarg;
int					g_optind = 1;
int					g_optopt;
int					g_opterr = 1;
int					g_optreset;

static int32_t	getopt_done(const int argc, char *const argv[], uint64_t *index)
{
	if (g_optreset)
	{
		*index = 1;
		g_optind = 1;
		g_optreset = 0;
	}
	if (g_optind >= argc
		|| ft_strequ(argv[g_optind], GETOPT_STOP_OPTION)
		|| argv[g_optind][0] != '-')
		return (1);
	return (0);
}

static void		getopt_err(const char opt_char, const int error_type)
{
	if (!g_opterr)
		return ;
	if (error_type == GETOPT_ERR_ILLEGAL_OPTION)
		ft_error(2, (char*[]){GETOPT_ERR_ILLEGAL_OPTION_MSG
					, (char[]){opt_char, '\0'}}, 0);
	else if (error_type == GETOPT_ERR_NO_ARG)
		ft_error(2, (char*[]){GETOPT_ERR_NO_ARG_MSG
					, (char[]){opt_char, '\0'}}, 0);
	else
		ft_error(1, (char*[]){"Unknown error"}, 0);
}

static int		getopt_argument(const int argc, char *const argv[]
								, uint64_t *index, const char *opt_char)
{
	if (!argv[g_optind][*index + 1])
	{
		if (g_optind + 1 >= argc)
		{
			getopt_err(*opt_char, GETOPT_ERR_NO_ARG);
			return ((int)GETOPT_ERR_CHAR);
		}
		*index = 1;
		g_optarg = argv[g_optind + 1];
		g_optind += 2;
		return ((int)*opt_char);
	}
	g_optarg = argv[g_optind] + *index + 1;
	*index = 1;
	g_optind++;
	return ((int)*opt_char);
}

int				ft_getopt(int argc, char *const argv[], const char *optstring)
{
	static uint64_t	index = 1;
	char			*opt_char;

	if (getopt_done(argc, argv, &index))
		return (-1);
	if (argv[g_optind][index]
		&& (opt_char = ft_strchr(optstring, argv[g_optind][index]))
		&& *opt_char != ':')
	{
		g_optopt = *opt_char;
		if (opt_char[1] == ':')
			return (getopt_argument(argc, argv, &index, (const char*)opt_char));
		index++;
		if (!argv[g_optind][index])
		{
			index = 1;
			g_optind++;
		}
		return (g_optopt);
	}
	getopt_err(argv[g_optind][index], GETOPT_ERR_ILLEGAL_OPTION);
	g_optopt = argv[g_optind][index++];
	return ((int)GETOPT_ERR_CHAR);
}

#endif
