/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:49:56 by esouza            #+#    #+#             */
/*   Updated: 2018/12/05 17:46:05 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			which_arg(t_labels *head, int idx)
{
	if (head->args[idx][0] == 'r')
		return (T_REG);
	else if (head->args[idx][0] == DIRECT_CHAR)
		return (T_DIR);
	else if  (head->args[idx][0] == LABEL_CHAR)
		return (T_LAB);
	return (T_IND);
}
