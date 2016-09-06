// `sdl-config --cflags --libs`

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct	s_complexe
{
	double r;
	double i;
}				t_complexe;

typedef struct	s_pos
{
	double x;
	double y;
}				t_pos;

typedef struct	s_ecart
{
	double xNeg;
	double xPos;
	double yNeg;
	double yPos;
	double z;
	double decal_x;
	double decal_y;
	int old_x;
	int old_y;
}				t_ecart;

typedef struct	s_env
{
	void *mlx;
	void *win;
	void *img;
	int s_line;
	int bpp;
	int endian;
	char *data;
	t_pos souris;
	t_ecart e;
	t_complexe c;
}				t_env;

void			ft_julia(t_env *env);
void			ft_print_julia(t_env *env);
int				ft_red_cross(t_env *env);
int				ft_key_press(int keycode, t_env *e);
int				ft_key_release(int keycode, t_env *env);
int				ft_mouse_hook(int button, int x, int y, t_env *e);
int				ft_dragged_mouse(int x, int y, t_env *e);
t_ecart			ft_zoom(t_ecart e, t_pos souris);
t_ecart			ft_dezoom(t_ecart e, t_pos souris);
