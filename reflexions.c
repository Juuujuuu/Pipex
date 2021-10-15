/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflexions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmarti <julmarti@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:49:44 by julmarti          #+#    #+#             */
/*   Updated: 2021/10/15 15:57:14 by julmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

pipe()
 |
 |-- fork()
      |
      |-- child // cmd1
      :     |--dup2()
      :     |--close end[0]
      :     |--execve(cmd1)
      :
      |-- parent // cmd2
            |--dup2()
            |--close end[1]
            |--execve(cmd2)