/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmarti <julmarti@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:40:56 by julmarti          #+#    #+#             */
/*   Updated: 2022/02/07 16:01:42 by julmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void    ft_parsing(char **argv, char *envp)
{
    char *path;
    char **tab;
    char **cmd1;
    char **cmd2;

    path = ft_substr(envp);
    tab = ft_split (path, ":");
    cmd1 = ft_split (argv[2], " ");
    cmd2 = ft_split (argv[3], " ");

}

/* NB : ajouter un \ à la fin des commandes.

Pour checker les envp, taper env dans le terminal et regarder la ligne "path" pour connaitre tous les chemins vers des commandes. 
