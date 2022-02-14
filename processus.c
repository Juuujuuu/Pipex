/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmarti <julmarti@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:26:00 by julmarti          #+#    #+#             */
/*   Updated: 2022/02/11 16:26:29 by julmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/// First process, issu du fork -> process enfant 
void first_process(int *fd, char **argv, char **envp)
{
      printf("\t JE SUIS DANS PROCESSUS PERE \n");
      close (fd[1]); // je ferme la partie d'écriture
      // appeler ft_parsing
      dup2(fd[1], STDOUT_FILENO); // pour dupliquer et swap le fd. Penser à sécuriser si dup2 < 0. dup2(f1, STDIN) ferme le fd[1]
      close (fd[0]); // je ferme la partie de lecture 
      execve(argv[2], argv+1, envp); // execve(const char *pathname, char *const argv[], char *const envp[])
      printf("La commande 1 a été identifiée: %s\n", argv[2]);
}

/// Second process, process parent
void  second_process(int *fd, char **argv, char **envp)
{   
      printf("\t JE SUIS DANS PROCESSUS FILS \n");
      close (fd[0]); // je ferme la partie lecture 
      // appeler ft_parsing
      dup2(fd[0], STDIN_FILENO); // pour dupliquer et swap le fd
      close(fd[1]); // je ferme la partie d'écriture 
      execve(argv[3], argv+1, envp); // execve(const char *pathname, char *const argv[], char *const envp[])
      printf ("La commande 2 a été identifiée: %s\n", argv[3]);
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
