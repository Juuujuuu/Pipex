/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmarti <julmarti@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:49:44 by julmarti          #+#    #+#             */
/*   Updated: 2022/01/28 18:16:04 by julmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/// Check que tout va bien lors de la création de pipe 
int error_check_pipe(int *fd)
{
   if (pipe(fd) == -1)  // La valeur de retour de pipe() est 0 en cas de succès, -1 si erreur
             printf("Impossible d'ouvrir le tube\n");
            return 1; 

      // vérifier si les fichier existent bien et si nous avons bien les permissions (check avec la fonction access() )
      //open('file1.txt', O_WRONLY);
      //open('file2.txt', O_RDONLY);
}

/// Check lors du fork
int   error_check_pid(pid_t pid)
{
      if (pid < 0) // si le fork échoue 
             printf("Fork a échoué");
            return 2; 
}

/// First process, issu du fork -> process enfant 
void first_process(int *fd, char *buf)
{
     
      close (fd[1]); // je ferme la partie d'écriture
      while (read(fd[0], buf, strlen(buf)) != 0) // tant que je peux lire 
            printf("%s\n", buf);
     // dup2(fd[1], stdout); pour dupliquer et swap le fd. Penser à sécuriser si dup2 < 0
      close (fd[0]); // je ferme la partie de lecture 
      // execve(const char *pathname, char *const argv[], char *const envp[]);
}

/// Second process, process parent
void  second_process(int *fd, char *buf)
{   
      close (fd[0]); // je ferme la partie lecture 
      write(fd[1], buf, strlen(buf));
   //   dup2(fd[0], stdin); pour dupliquer et swap le fd
      close(fd[1]); // je ferme la partie d'écriture 
}

void ft_pipex(int argc,char **argv)
{
      int fd[2]; // fd[0] est le descripteur pour lire -  fd[1] est le descripteur pour écrire
      pid_t pid; // nom par convention quand on parle d'un fork , pour Personnal ID. type par convention également
      int retour_err_pipe;
      int retour_err_pid;
      char *buf;

      pipe(fd); // création du pipe 
      retour_err_pipe = error_check_pipe(fd); // check si les fichiers sont accessibles 
      if (retour_err_pipe > 0)
            printf("ERREUR RENCONTREE DANS L'OUVERTURE DES FICHIERS");
      pid = fork(); // appel système pour créer des processus. Il ne prend pas d'argument et retourne un process ID
      retour_err_pid = error_check_pid(pid);
      if (pid == 0) // le fork a réussi, on commence le processus enfant
            first_process(fd, buf); // avec le f1 et cmd1
      else // si pid > 0, j'écris, donc go processus parent
            second_process(fd, buf); // avec f2 et cmd2
      close(fd[0]); 
      close(fd[1]);
      // wait ? 
} 
// RAPPEL : on execute le programme like dis : ./pipex infile cmd1 cmd2 outfile. infile correspond à notre stdin et outfile à notre stdout. 


// http://www.zeitoun.net/articles/communication-par-tuyau/start

/* STEPS :
1. Qu'est ce qu'un pipe ? Qu'est-ce qu'un fork ? Pourquoi les utiliser ici ? DONE
2. Gestion des erreurs et des droits EN COURS 
3. Gestion des arguments ( parsing ?)
4. Die 
*/


/* FONCTIONS AUTORISEES  : 
- access :vérifie si le processus appelant peut accéder au fichier pathname. Si pathname est un lien symbolique, il est déréférencé.

- open :  renvoie un descripteur de fichier, un petit entier positif ou nul utilisable par des appels système ultérieurs (genre read, write)

- unlink :détruit un nom dans le système de fichiers. 

Si ce nom était le dernier lien sur un fichier, et si aucun processus n'a ouvert ce fichier, ce dernier est effacé, et l'espace qu'il utilisait est rendu disponible.
Renvoie 0 si réussite Renvoie -1 si échec

- close :  ferme le descripteur fd, de manière à ce qu'il ne référence plus aucun fichier, et puisse être réutilisé. 

- read : lit jusqu'à count octets depuis le descripteur de fichier fd dans le tampon pointé par buf

- write : écrit jusqu'à count octets dans le fichier associé au descripteur fd depuis le tampon pointé par buf.

- malloc : alloue size octets, et renvoie un pointeur sur la mémoire allouée.

- waitpid : suspend l'exécution du processus appelant jusqu'à ce que le fils spécifié par son pid ait changé d'état.

- wait : suspend l'execution du thread appelé jusqu'à qu'un de ses fils termine. Utile pour libérer le processus fils (et donc éviter les zombies)

- free : affiche les quantités totales de mémoire et de zone de swap libres et utilisées dans le système, ainsi que la mémoire partagée et les buffers utilisés par le noyau.

- pipe : créer un pipe avec un paramètre spécifique pour communiquer entre processus
le tableau pipe(fd[2]) est utilisé pour renvoyer deux fd faisant ref aux extrémites du tube.
pipefd[0] fait référence à l'extrémité de lecture du tube. 
pipefd[1] fait référence à l'extrémité d'écriture du tube. 
Les données écrites sur l'extrémité d'écriture du tube sont mises en mémoire tampon par le noyau jusqu'à ce qu'elles soient lues sur l'extrémité de lecture du tube.

- dup et dup2 : créent une copie du descripteur de fichier oldfd.
Dup utilise les + petit numéro inutilisé, dup2 transforme newfd en une copie de oldfd. 
Donc dup2 duplique fd en fd2, ce qui nous permet de "swapper" fd en fd2. 
Tout deux renvoient le nouveau descripteur, ou -1 s'ils échouent.

- execve : execute le programme correspondant au fichier filename. Permet d'exécuter un processus enfant avec un tableau de paramètres et ses variables d'environnement.

- fork : pour dupliquer le processus parent avec un PID propre au fils. Sa valeur renvoyée est pour le parent le numéro PID du processus fils, pour le fils 0. Si échec, return -1 

- perror :  affiche un message sur la sortie d'erreur standard, décrivant la dernière erreur rencontrée durant un appel système ou une fonction de bibliothèque. 

- strerror : renvoie une chaîne décrivant le code d'erreur passé en argument errnum

- exit : pour quitter le programme n'importe ou dans le code. Tous les flux ouverts de type stdio(3) sont vidés et fermés. Les fichiers créés par tmpfile(3) sont supprimés.

*/ 