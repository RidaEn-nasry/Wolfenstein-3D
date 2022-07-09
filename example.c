


int main( void ) {

	void *mlx;
	mlx = mlx_init();
	void *win = mlx_new_window(mlx, 800, 600, "test");
	// write hello world in the window
	mlx_string_put(mlx, win, 10, 10, 0xFFFFFF, "Hello World");

	mlx_loop(mlx);
	return (0);
}
