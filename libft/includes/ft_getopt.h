/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:41:33 by sclolus           #+#    #+#             */
/*   Updated: 2017/11/23 19:52:58 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

# include "libft.h"

# ifdef GETOPT_ON

#  define GETOPT_STOP_OPTION "--"
#  define GETOPT_ERR_CHAR '?'
#  define GETOPT_ERR_ILLEGAL_OPTION 1
#  define GETOPT_ERR_ILLEGAL_OPTION_MSG "illegal option -- "
#  define GETOPT_ERR_NO_ARG 2
#  define GETOPT_ERR_NO_ARG_MSG "option requires an argument -- "

extern char *g_optarg;
extern int	g_optind;
extern int	g_optopt;
extern int	g_opterr;
extern int	g_optreset;

int	ft_getopt(int argc, char *const argv[], const char *optstring);

# endif
#endif
