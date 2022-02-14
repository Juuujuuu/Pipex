/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmarti <julmarti@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:20:09 by julmarti          #+#    #+#             */
/*   Updated: 2022/02/11 15:57:21 by julmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    int fd[2]; // fd[0] est le descripteur pour lire -  fd[1] est le descripteur pour écrire

// si le format tapé n'est pas le bon
    if (argc != 5)
    {
        printf("Format : ./pipex file1 cmd1 cmd2 file2");
        exit(EXIT_FAILURE);
    }
// check avec la fonction access() que les commandes utilisées existent
//    access(const char *pathname, int mode);

// vérifier si les fichier existent bien et si nous avons bien les permissions
    fd[0] = open(argv[1], O_RDONLY);
    fd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd[0] < 0 || fd[1] < 0)
        return(-1);
    else 
        ft_pipex(fd, argv, envp);
    return(0);
}
// Le troisième paramètre, envp, est un tableau de pointeurs vers des variables d’environnement. Le tableau envp est arrêté par un pointeur null. 