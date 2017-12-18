/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:12:49 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/18 18:47:19 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include "ft_printf.h"

char		*g_optarg = NULL;
int			g_optind = 1;
int			g_opterr = 1;
int			g_optopt = '?';

static int	init_static(int argc, char *const argv[], char **tmp)
{
	if (!**tmp)
	{
		if (g_optind >= argc || *(*tmp = argv[g_optind]) != '-')
		{
			*tmp = "";
			return (-1);
		}
		if ((*tmp)[1] && *++(*tmp) == '-')
		{
			++g_optind;
			*tmp = "";
			return (-1);
		}
	}
	return (1);
}

static char	need_arg(int argc,
		char *const argv[],
		char **tmp,
		const char *opstring)
{
	if (**tmp)
		g_optarg = *tmp;
	else if (argc <= ++g_optind)
	{
		*tmp = "";
		if (*opstring == ':')
			return (':');
		if (g_opterr)
			ft_fprintf(2,
					"%s: option requires an argument -- %c\n",
					argv[0], g_optopt);
		return ('?');
	}
	else
		g_optarg = argv[g_optind];
	*tmp = "";
	++g_optind;
	return (g_optopt);
}

int			ft_getopt(int argc, char *const argv[], const char *opstring)
{
	static char	*place = "";
	char		*oli;

	if (init_static(argc, argv, &place) == -1)
		return (-1);
	if ((g_optopt = *place++) == ':'
		|| !(oli = ft_strchr(opstring, g_optopt)))
	{
		if (g_optopt == '-')
			return (-1);
		if (!*place)
			++g_optind;
		if (g_opterr && *opstring != ':')
			ft_fprintf(2, "%s: illegal option -- %c\n", argv[0], g_optopt);
		return ('?');
	}
	if (*++oli != ':')
	{
		g_optarg = NULL;
		if (!*place)
			++g_optind;
		return (g_optopt);
	}
	return (need_arg(argc, argv, &place, opstring));
}
