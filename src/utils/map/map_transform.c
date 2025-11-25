#include "../../../include/main.h"

void normaize_width(t_map *map, unsigned char toapp)
{
    size_t idx;

    idx = 0;
    while (map->map2d[idx])
    {
        map->map2d[idx] = normalize(map->map2d[idx], map->width + 1, toapp);
        idx++;
    }
}
