/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmarti <julmarti@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:24:42 by julmarti          #+#    #+#             */
/*   Updated: 2022/02/01 16:55:37 by julmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/// Check que tout va bien lors de la création de pipe 
int error_check_pipe(int *fd)
{
   if (pipe(fd) == -1)  // La valeur de retour de pipe() est 0 en cas de succès, -1 si erreur
            perror("Impossible d'ouvrir le tube\n");
        return 1; 
}

/// Check lors du fork
int   error_check_pid(pid_t pid)
{
      if (pid < 0) // si le fork échoue 
            perror("Fork a échoué");
        return 2; 
}