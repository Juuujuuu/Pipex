/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmarti <julmarti@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:36:49 by julmarti          #+#    #+#             */
/*   Updated: 2022/01/28 16:53:42 by julmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h> // pour printf
# include <unistd.h> // pour read, execve, close, dup, pipe
# include <stdlib.h> // pour exit 
# include <string.h> // pour strlen
# include <sys/wait.h> // pour wait
# include <sys/types.h> // pour wait et le type pid_t 

int ft_pipex();
// créer une structure 
#endif