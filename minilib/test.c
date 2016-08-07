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
	img = mlx_new_image(e.mlx, 1920, 1080);
	data = mlx_get_data_addr(img, bpp, sizeline, endian);
	mlx_loop(mlx);
	printf("test fin\n");                                                                                                                   
	return (0);
}
