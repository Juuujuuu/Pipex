/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmarti <julmarti@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:40:56 by julmarti          #+#    #+#             */
/*   Updated: 2022/02/11 15:39:04 by julmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_parsing(char **argv, char *envp)
{
    printf("\t JE SUIS DANS FT_PARSING \n");
    char *path;
    char **tab;
    char **cmd1;
    char **cmd2;
    unsigned int start;
    size_t len;

    start = 0;
    len = 1000000;
    path = ft_substr(envp, start, len);
    tab = ft_split (path, ":");
    cmd1 = ft_split (argv[2], " ");
    cmd2 = ft_split (argv[3], " ");

}

/* NB : ajouter un \ à la fin des commandes.

Pour checker les envp, taper env dans le terminal
 et regarder la ligne "path" pour connaitre tous les chemins vers des commandes. */
