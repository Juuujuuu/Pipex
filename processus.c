/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmarti <julmarti@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:26:00 by julmarti          #+#    #+#             */
/*   Updated: 2022/02/01 17:06:52 by julmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/// First process, issu du fork -> process enfant 
void first_process(int *fd, char **argv)
{
      close (fd[1]); // je ferme la partie d'écriture
      while (read(fd[0], argv, strlen(argv[1])) != 0) // tant que je peux lire 
            printf("J'ai lu le fichier 1 : %s\n", argv[1]);
     // dup2(fd[1], stdout); pour dupliquer et swap le fd. Penser à sécuriser si dup2 < 0. dup2(f1, STDIN) ferme le fd[1]
      close (fd[0]); // je ferme la partie de lecture 
      // execve(const char *pathname, char *const argv[], char *const envp[]);
}

/// Second process, process parent
void  second_process(int *fd, char **argv)
{   
      close (fd[0]); // je ferme la partie lecture 
      write(fd[1], argv, strlen(argv[1]));
   //   dup2(fd[0], stdin); pour dupliquer et swap le fd
      close(fd[1]); // je ferme la partie d'écriture 
}


/* execve(pathname, argv, envp)
pathname : the pathname of the command to execute
argv : the arguments to pass to the new programm
envp : the environnment list 

argv et envp sont des chaines de pointeurs sur char 

execve ne retourne rien, sauf erreur. Donc 
if (execve(cmd) == -1)
      perror("oulala on a une erreur");


Il est bien de distinguer les deux appels systèmes execve et fork 
- fork() permet de créer une copie du processus actuel 
- execve() permet de remplacer le code du process actuel et adresser l'espace avec le code d'un autre programme. 

Les fonctions getpid(), exit(), wait()/waitpid() sont aussi des appels systèmes dédiés au management de process. 
*/
