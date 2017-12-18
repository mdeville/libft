/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:04:46 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/15 20:31:19 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

# include "libft.h"

char	*g_optarg = NULL;
int		g_optind = 0;
int		g_opterr = 1;
int		g_optopt = '?';

int		ft_getopt(int argc, char *const argv[], const char *opstring);

#endif
