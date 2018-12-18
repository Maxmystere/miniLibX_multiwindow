/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:15:27 by magrab            #+#    #+#             */
/*   Updated: 2018/12/18 21:36:00 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void	draw_line(void *win, int x0, int y0, int x1, int y1);
void	test_draw(void *win, int x, int y);

void	*g_mlxptr(int setup);
void	*g_win(int win, int sizex, int sizey, char *win_name);

int	deal_key(int key, void *param)
{
	printf("key :%d\n", key);

	if (key == 53) //esc key
		exit(0);
	if (key == 50)
		mlx_clear_window(g_mlxptr(0), param);
	return (0);
}

int deal_mouse(int button, int x, int y, void *win)
{
	printf("button :%d\n", button);

	test_draw(win,x, y);
	return (0);
}

int main()
{
	int x;

	g_mlxptr(1);
	if (!g_mlxptr(0))
		return (-1);

	g_win(-1, 1000, 1000,"Test");
	g_win(-2, 500, 500,"My Tab");
	g_win(-3, 200, 200,"Tib");

	//void **test = g_win(0);
	//*test = mlx_new_window(g_mlxptr(0), 1000, 1000, "Lol");

	x = 0;
	while (++x < 4)
	{
		mlx_key_hook(g_win(x,0,0,0), deal_key, g_win(x,0,0,0));
		mlx_mouse_hook(g_win(x,0,0,0), deal_mouse, g_win(x,0,0,0));
	}
	mlx_loop(g_mlxptr(0));
	return (0);
}
