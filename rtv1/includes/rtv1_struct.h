#ifndef RTV1_STRUCT_H
# define RTV1_STRUCT_H

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int 	s_line;
	int		endian;
	int		height;
	int		width;
}				t_mlx;

typedef struct	s_env
{
	t_mlx		*mlx;
	t_vector	*dir;
	//t_vector	*a;
	t_vector	*b;
	t_obj		*obj;
	t_light		*light;
	t_obj		*o_hit;
	t_cam		*cam;
	double 		angle;
	t_color		*c_hit;
}				t_env;

#endif