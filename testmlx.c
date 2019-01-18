/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:15:27 by magrab            #+#    #+#             */
/*   Updated: 2019/01/18 19:07:59 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct	s_win{
	int		sizex;
	int		sizey;
	char	*title;
}				t_win;

void	*g_mlx(int setup)
{
	static void *mlx_ptr;

	if (setup == 1)
		mlx_ptr = mlx_init();
	return (mlx_ptr);
}

#define MAX_WIN 5

void	*g_win(int get, void *param)
{
	static void *win_ptr[MAX_WIN];
	t_win		*win;
	int			x;

	win = (t_win *)param;
	if (get > 0 && get <= MAX_WIN)
	{
		if (win != 0)
			win_ptr[get - 1] = mlx_new_window(g_mlx(0), win->sizex, win->sizey, win->title);
		return (win_ptr[get - 1]);
	}
	if (get < 0 && get >= -MAX_WIN)
	{
		mlx_destroy_window(g_mlx(0), win_ptr[-get - 1]);
		win_ptr[-get - 1] = NULL;
	}
	x = -1;
	if (get == 0 && param != NULL)
		while (++x < MAX_WIN)
		{
			get += (param != NULL);
			if (param == win_ptr[x])
			{
				mlx_destroy_window(g_mlx(0), win_ptr[x]);
				win_ptr[x] = NULL;
			}
		}
	return (NULL);
}

int	key_hook(int key, void *param)
{
	printf("key :%d\n", key);

	if (key == 53) //esc key
		exit(0);
	if (key == 50)
		mlx_clear_window(g_mlx(0), param);
	return (0);
}

int mouse_hook(int button, int x, int y, void *win)
{
	printf("button :%d\nwin : %p\n", button, win);
	if (button == 2)
		mlx_destroy_window(g_mlx(0), win);
	return (0);
}

int main()
{
	t_win win;

	win.sizex = 1000;
	win.sizey = 750;
	win.title = "Hello";
	if (!g_mlx(1))
		return (-1);

	int x = 1;
	while (x < 3)
	{
		if (!(g_win(x, &win)))
			return (-1);

		mlx_key_hook(g_win(x, 0), key_hook, g_win(x, 0));
		mlx_mouse_hook(g_win(x, 0), mouse_hook, g_win(x, 0));
		x++;
	}
	mlx_loop(g_mlx(0));
	return (0);
}
