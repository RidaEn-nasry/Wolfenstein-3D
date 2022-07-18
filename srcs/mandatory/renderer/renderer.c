
#include <renderer.h>




void    renderer(t_map *map)

{
    map->mlx = malloc(sizeof(*map->mlx));
    exit_free_if(!map->mlx, "Error: malloc failed", map);
    map->mlx->mlx = mlx_init(); ;
    exit_free_if(!map->mlx->mlx, "Error\n\tmlx_init error", map);
    map->mlx->win = mlx_new_window(map->mlx->mlx, WIDTH, HEIGHT, "wolfenstein 3d");
    exit_free_if(!map->mlx->win, "Error\n\tmlx window creation failed", map);
    map->mlx->img = mlx_new_image(map->mlx->mlx, WIDTH, HEIGHT);
    exit_free_if(!map->mlx->img, "Error\n\tmlx image creation failed", map);
    mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->img, 0, 0);
    render_map(map);

    return ;
}
