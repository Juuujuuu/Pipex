/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmarti <julmarti@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:49:44 by julmarti          #+#    #+#             */
/*   Updated: 2022/02/01 17:13:35 by julmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_pipex(char **argv)
{
      int fd[2]; // fd[0] est le descripteur pour lire -  fd[1] est le descripteur pour écrire
      pid_t pid; // nom par convention quand on parle d'un fork , pour Personnal ID. type par convention également
      int retour_err_pipe;
      int retour_err_pid;

      pipe(fd); // création du pipe 
      retour_err_pipe = error_check_pipe(fd); // check si les fichiers sont accessibles 
      if (retour_err_pipe > 0)
            perror("ERREUR RENCONTREE DANS L'OUVERTURE DES FICHIERS");
      pid = fork(); // appel système pour créer des processus. Il ne prend pas d'argument et retourne un process ID
      retour_err_pid = error_check_pid(pid);
      if (retour_err_pid > 0)
            perror("ERREUR RENCONTRE LORS DU FORK");
      if (pid == 0) // le fork a réussi, on commence le processus enfant
            first_process(fd, argv); // avec le f1 et cmd1
      else // si pid > 0, j'écris, donc go processus parent
            second_process(fd, argv); // avec f2 et cmd2
      close(fd[0]); 
      close(fd[1]);
      // wait pour synchroniser parent et child 
} 
