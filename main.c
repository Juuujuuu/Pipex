/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmarti <julmarti@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:20:09 by julmarti          #+#    #+#             */
/*   Updated: 2022/02/01 17:44:21 by julmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
    char **tab;
    int ret_open_f1;
    int ret_open_f2;

// si le format tapé n'est pas le bon
    if (argc != 5)
    {
        printf("Format : ./pipex file1 cmd1 cmd2 file2");
        exit(EXIT_FAILURE);
    }
    else
    {
        tab = ft_split(argv[1],' '); // quels sont les éléments délimitant ? 
    }
// check avec la fonction access() que les commandes utilisées existent
//    access(const char *pathname, int mode);

// vérifier si les fichier existent bien et si nous avons bien les permissions
    ret_open_f1 = open(argv[1], O_WRONLY);
    ret_open_f2 = open(argv[4], O_RDONLY);
    if (ret_open_f1 < 0 || ret_open_f2 < 0)
        return(-1);
    else 
        ft_pipex(argv[1]);
    return(0);
}