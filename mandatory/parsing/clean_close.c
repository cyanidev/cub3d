/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andie <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:51:31 by andie             #+#    #+#             */
/*   Updated: 2025/05/25 23:31:22 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

void	free_parsing(t_cubp *cubp)
{
	if (!cubp)
		return ;
	if (cubp->map_info.fd > 0)
		close(cubp->map_info.fd);
	if (cubp->map_info.file)
		free_tab((void **)cubp->map_info.file);
	if (cubp->map)
		free_tab((void **)cubp->map);
	free_textures(cubp);
	free_floor_n_ceiling(cubp);
}
