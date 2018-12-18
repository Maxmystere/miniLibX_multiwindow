/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_mlxptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:42:29 by magrab            #+#    #+#             */
/*   Updated: 2018/12/18 21:30:05 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

void	*g_mlxptr(int setup)
{
	static void *mlx_ptr;

	if (setup == 1)
		mlx_ptr = mlx_init();
	return (mlx_ptr);
}

void	*g_win(int win, int sizex, int sizey, char *win_name)
{
	static void *win_ptr[42];

	if (win < 0)
	{
		win_ptr[-win] = mlx_new_window(g_mlxptr(0), sizex, sizey, win_name);
		return (win_ptr[-win]);
	}
	return (win_ptr[win]);
}
