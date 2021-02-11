/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 11:46:52 by aybouras          #+#    #+#             */
/*   Updated: 2019/05/30 18:36:43 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_list(t_list2 **alst)
{
	t_list2 *temp;

	if (!alst)
		return ;
	while (*alst != NULL)
	{
		temp = (*alst)->next;
		free(*alst);
		*alst = temp;
	}
	free(temp);
}
