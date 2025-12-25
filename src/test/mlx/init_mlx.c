#include "../../../include/main.h"

void init_mlx(t_game *ref)
{
    if (!ref)
        return;

    ref->win.mlx = mlx_init(WIN_WIDTH, WIN_HIGHT, WIN_TITLE, true);
    if (!ref->win.mlx)
    {
        setError(&ref->error, "Error: Unable to init mlx !");
        setStat(&ref->error, 1);
        return;
    }
    ref->win.imgl.img = mlx_new_image(ref->win.mlx, WIN_WIDTH/2, WIN_HIGHT);
    if (!ref->win.imgl.img)
    {
        mlx_terminate(ref->win.mlx);
        setError(&ref->error, "Error: Unable to init mlx left image!");
        setStat(&ref->error, 1);
        return;
    }
    ref->win.imgr.img = mlx_new_image(ref->win.mlx, WIN_WIDTH/2, WIN_HIGHT);
    if (!ref->win.imgr.img)
    {
        mlx_delete_image(ref->win.mlx, ref->win.imgl.img);
        setError(&ref->error, "Error: Unable to init mlx right image!");
        setStat(&ref->error, 1);
        mlx_terminate(ref->win.mlx);
        return;
    }
    for (int y = 0; y < WIN_HIGHT; y++)
    {
        for (int x = 0; x < WIN_WIDTH / 2; x++)
            mlx_put_pixel(ref->win.imgl.img, x, y, ref->textures.east_txt.rgba);
    }
    for (int y = 0; y < WIN_HIGHT; y++)
    {
        for (int x = 0; x < WIN_WIDTH / 2; x++)
            mlx_put_pixel(ref->win.imgr.img, x, y, ref->textures.west_txt.rgba);
    }

    if (mlx_image_to_window(ref->win.mlx, ref->win.imgl.img, 0, 0) < 0)
    {
        mlx_delete_image(ref->win.mlx, ref->win.imgl.img);
        mlx_delete_image(ref->win.mlx, ref->win.imgr.img);
        setError(&ref->error, "Error: Unable to draw left image!");
        setStat(&ref->error, 1);
        mlx_terminate(ref->win.mlx);
        return;
    }
    if (mlx_image_to_window(ref->win.mlx, ref->win.imgr.img, WIN_WIDTH/2, 0) < 0)
    {
        mlx_delete_image(ref->win.mlx, ref->win.imgl.img);
        mlx_delete_image(ref->win.mlx, ref->win.imgr.img);
        setError(&ref->error, "Error: Unable to draw right image!");
        setStat(&ref->error, 1);
        mlx_terminate(ref->win.mlx);
        return;
    }
}