/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:12:49 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/18 17:04:16 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include "ft_printf.h"

char		*g_optarg = NULL;
int			g_optind = 0;
int			g_opterr = 1;
int			g_optopt = '?';

int			init_static(int argc, char *const argv[], char **index, char **exec)
{
	char *tmp;

	tmp = *index;
	if (!*exec)
		*exec = *argv;
	if (!*tmp)
	{
		if (g_optind >= argc || *(tmp = argv[g_optind]) != '-')
		{
			tmp = "";
			return (-1);
		}
		if (tmp[1] && *++tmp == '-')
		{
			++g_optind;
			tmp = "";
			return (-1);
		}
	}
	return (1);
}

char		need_arg(int argc,
		char *const argv[],
		char **tmp,
		const char *opstring)
{
	char *index;

	index = *tmp;
	if (*index)
		g_optarg = index;
	else if (argc <= ++g_optind)
	{
		index = "";
		if (*opstring == ':')
			return (':');
		if (g_opterr)
			ft_fprintf(2,
				"%s: option requires an argument -- %c\n", argv[0], g_optopt);
		return ('?');
	}
	else
		g_optarg = argv[g_optind];
	index = "";
	++g_optind;
	return (-1);
}

int			ft_getopt(int argc, char *const argv[], const char *opstring)
{
	char		*oli;
	static char	*index = "";
	static char	*exec = NULL;

	if (init_static(argc, argv, &index, &exec) == -1)
		return (-1);
	if ((g_optopt = *index++) == ':'
			|| !(oli = strchr(opstring, g_optopt)))
	{
		if (g_optopt == '-')
			return (-1);
		if (!*index)
			++g_optind;
		if (g_opterr && *opstring != ':')
			ft_fprintf(2, "%s: illegal option -- %c\n", exec, g_optopt);
		return ('?');
	}
	if (*++oli != ':')
	{
		g_optarg = NULL;
		if (!*index)
			++g_optind;
	}
	return (((*oli = need_arg(argc, argv, &index, opstring)) != -1) ?
			*oli : g_optopt);
}
