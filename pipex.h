/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmarti <julmarti@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:36:49 by julmarti          #+#    #+#             */
/*   Updated: 2022/02/07 15:31:56 by julmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h> // pour printf
# include <unistd.h> // pour read, execve, close, dup, pipe
# include <stdlib.h> // pour exit et ses constantes (EXIT_FAILURE)
# include <string.h> // pour strlen
# include <sys/wait.h> // pour wait
# include <sys/types.h> // pour wait et le type pid_t
# include <fcntl.h> // pour les flags d'open
# include "../Libft/libft.h" // pour ft_split

void    ft_pipex(int *fd, char **argv);
int     error_check_pipe(int *fd);
int     error_check_pid(pid_t pid);
void    first_process(int *fd, char **argv);
void    second_process(int *fd, char **argv);

#endif