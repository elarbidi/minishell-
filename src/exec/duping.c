/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-che <zait-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 03:26:42 by aelarbid          #+#    #+#             */
/*   Updated: 2023/01/21 07:47:09 by zait-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	dup_core1(int *fd)
{
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
}

void	dup_core2(int *fd)
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
}

void	dup_core3(int *pipeA, int *pipeB)
{
	dup2(pipeA[0], STDIN_FILENO);
	dup2(pipeB[1], STDOUT_FILENO);
	close(pipeA[0]);
	close(pipeA[1]);
	close(pipeB[1]);
	close(pipeB[0]);
}
