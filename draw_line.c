/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:30:03 by magrab            #+#    #+#             */
/*   Updated: 2019/02/13 19:52:33 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void	*g_mlx(int setup);

void	draw_line(void *win, int x0, int y0, int x1, int y1)
{
	int dx;
	int dy;
	int err;
	int e2;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	err = (dx>dy ? dx : -dy);
	while (x0 != x1 || y0 != y1)
	{
		mlx_pixel_put(g_mlx(0), win, x0, y0, 0xFFFFFF);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += (x0 < x1 ? 1 : -1);
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += (y0 < y1 ? 1 : -1);
		}
	}
}

void test_draw(void *win, int x, int y)
{
	static int x0;
	static int y0;
	static int x1;
	static int y1;

	if (x0 == 0)
	{
		x0 = x;
		y0 = y;
	}
	else if (x1 == 0)
	{
		x1 = x;
		y1 = y;
	}
	if (x0 != 0 && x1 != 0)
	{
		printf("drawing :\nx0 = %d\ty0 = %d\nx1 = %d\ty1 = %d\n", x0, y0, x1, y1);
		draw_line(win, x0, y0, x1, y1);
		x0 = 0;
		x1 = 0;
		y0 = 0;
		y1 = 0;
	}
}
