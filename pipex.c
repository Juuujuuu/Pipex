/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmarti <julmarti@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:49:44 by julmarti          #+#    #+#             */
/*   Updated: 2022/02/11 16:24:03 by julmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_pipex(int *fd, char **argv, char **envp)
{
      printf("\t JE SUIS DANS FT_PIPEX \n");
      pid_t pid; // nom par convention quand on parle d'un fork , pour Personnal ID. type par convention également

      pipe(fd); // création du pipe 
      if (error_check_pipe(fd) > 0) // check si les fichiers sont accessibles 
            perror("OUVERTURE DES FICHIERS");
      pid = fork(); // appel système pour créer des processus. Il ne prend pas d'argument et retourne un process ID
      if (error_check_pid(pid) < 0)
            perror("FORK");
      if (pid == 0) // le fork a réussi, on commence le processus enfant
            first_process(fd, argv, envp); // avec le f1 et cmd1
      else if (pid > 0) // si pid > 0, j'écris, donc go processus parent
            second_process(fd, argv, envp); // avec f2 et cmd2
      close(fd[0]); 
      close(fd[1]);
      // wait pour synchroniser parent et child 
}
