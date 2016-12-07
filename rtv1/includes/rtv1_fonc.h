#ifndef RTV1_FONC_H
# define RTV1_FONC_H

/*
** fonc_vector
*/
void		ft_vector_normalize(t_vector *v);
double		ft_vector_dot(t_vector *a, t_vector *b);
t_vector	*ft_vector_copy(t_vector *a);
t_vector	*ft_vector_sub(t_vector *a, t_vector *b);
t_vector	*ft_p_hit(t_vector *v_O, t_vector *v_dir, double dist);

/*
** ft_intersection
*/
int		ft_inter_plane(void *plan, t_vector *pos, t_vector *dir, double *t);
int		ft_inter_sphere(void *sphere, t_vector *pos, t_vector *dir, double *t);
int		ft_inter_cylinder(void	*o, t_vector *pos, t_vector *dir, double *t);
int		ft_inter_cone(void *o, t_vector *pos, t_vector *dir, double *t);

/*
** ft_put_pixel
*/
void	ft_print_pixel(t_env *e, int x, int y, double angle);
void	ft_put_color_from_line(t_obj *obj, char *line, int i);

/*
** ft_hit
*/
double	ft_sphere_hit(void *o, t_vector *p_hit, t_vector *l_vector, void *e);
double	ft_plan_hit(void *o, t_vector *p_hit, t_vector *l_vector, void *e);
double	ft_cylinder_hit(void *o, t_vector *p_hit, t_vector *l_vector, void *x);
double	ft_cone_hit(void *o, t_vector *p_hit, t_vector *l_vector, void *x);

/*
** ft_malloc_obj
*/
t_light		*ft_malloc_light(void);
t_sphere	*ft_malloc_sphere(void);
t_plan		*ft_malloc_plan(void);
t_cylinder	*ft_malloc_cylinder(void);
t_cone		*ft_malloc_cone(void);

/*
** ft_full_obj
*/
void	ft_full_light(t_light *l, double x, double y, double z, double intensity);
void	ft_full_sphere(t_sphere *s, double x, double y, double z, double radius);
void	ft_full_plan(t_plan *p, double xn, double yn, double zn, double xp, double yp, double zp);
void	ft_full_cylinder(t_cylinder *c, double xd, double yd, double zd, double xp, double yp, double zp, double r);
void	ft_full_cone(t_cone *c, double xp, double yp, double zp, double xd, double yd, double zd, double angle);
void	ft_fill_color(t_color *c, int r, int g, int b);

/*
** ft_parcing
*/
int		ft_is_int(char *str);
char	*get_word(char *line, int nb);
void	ft_fill_vector_from_file(t_vector *v, char *line, int pos);
void	ft_fill_obj(t_env *e, char *line);
void	ft_parcing(t_env *e, char *file);
double	ft_atodi(char *str);

#endif