/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:36:26 by fathjami          #+#    #+#             */
/*   Updated: 2022/01/05 18:04:52 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *path(char c)
{
	char *path;
	
	path = NULL;
	if(c == '1')
		path = "assets/wall.xpm";
	else if ( c == 'E')
		path = "assets/door.xpm";
	else if (c == 'P')
		path  = "assets/player.xpm";
	else if (c == 'C')
		path = "assets/collect.XPM";
	else
		return (NULL);
	return (path);
}

void fill_map(t_data param, t_mp m)
{
	char	*relative_path;
	int		img_width;
	void	*img;
	int i;
	int j;

	img_width = SQUARE;
	i = 0;
	while (m.map[i])
	{
		j = 0;
		while (m.map[i][j])
		{
			relative_path = path(m.map[i][j]);
			if (relative_path)
			{
				img = mlx_xpm_file_to_image(param.mlx, relative_path, &img_width, &img_width);
				mlx_put_image_to_window (param.mlx, param.mlx_win, img, j * img_width, i * img_width);
				mlx_destroy_image(param.mlx, img);
			}
			j++;
		}
		i++;
	}
}