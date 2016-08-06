#include <mlx.h>
#include <stdio.h>

int ft_key();
int ft_mouse();
int ft_loop(void *param);

int main(void)
{
	void *mlx;
	void *img;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "test mlx");
	mlx_key_hook(win, ft_key, 0);
	mlx_mouse_hook(win, ft_mouse, 0);
	mlx_loop(mlx);
	printf("test fin\n");
	return (0);
}

int ft_key(int keycode, void *param)
{
	printf("test key\n");
	return (0);
}

int ft_mouse(int button, int x, int y, void *param)
{
	printf("test mouse\n");
	return (0);
}

int ft_loop(void *param)
{
	printf("test loop\n");
	return (0);
}
