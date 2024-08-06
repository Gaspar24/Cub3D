

#include "cub3d.h"

int main(void)
{
    t_window    mlx;

    mlx.mlx_ptr = mlx_init();
    mlx.mlx_win = mlx_new_window(mlx.mlx_ptr,1280,720,"Maze Runner");
    mlx_loop(mlx.mlx_ptr);
    return(0);
}

