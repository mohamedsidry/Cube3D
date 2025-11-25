/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:54:25 by msidry            #+#    #+#             */
/*   Updated: 2025/11/21 10:29:24 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"

static bool empty_line(t_error *error, char *line);
static bool supported_line(t_error *error,char *line);
static bool closed_line(t_error *error, char *line);
static bool one_direction(t_error *error, char **arr);
static bool closed_map(t_error *error, t_map *map);
static void BFS(t_map *map,  t_queue **queue, bool *isvalid);
void map_validator(t_game *ref)
{
    size_t  idx;
    bool closed;
    idx = 0;
    if (!isAllOk(ref))
        return ;
    if (!one_direction(&ref->error, ref->map.map2d))
        return ;
    while (ref->map.map2d[idx])
    {
        if (empty_line(&ref->error, ref->map.map2d[idx]))
            return ;
        if (!supported_line(&ref->error, ref->map.map2d[idx]))
            return ;
        if (!closed_line(&ref->error, ref->map.map2d[idx]))
            return;
        idx++;
    }

    normaize_width(&ref->map, ' ');
    closed = closed_map(&ref->error, &ref->map);
    if (closed)
        echo("Yesss the map is closed ");
    else
        echo("Shit map is not closed ");
}




static bool empty_line(t_error *error, char *line)
{
    char *err;

    if (!*line || contain_only(line, SPACES) )
    {
        if (error)
        {
            err = find_replace(ERROR_GENERAL, "$MSG", BAD_E_LINE, 0);
            setError(error, err);
            setStat(error, EXIT_FAILURE);
            nullstr(&err);
        }
        return (true);  
    }
    return (false);
}

static bool supported_line(t_error *error,char *line)
{
    char *err;
    if (!contain_only(line, MAPSET))
    {
        err = find_replace(ERROR_GENERAL, "$MSG", BAD_C_LINE, 0);
        setError(error, BAD_C_LINE);
        setStat(error, EXIT_FAILURE);
        nullstr(&err);
        return (false);
    }
    return (true);
}



static bool one_direction(t_error *error, char **arr)
{
    size_t y;
    size_t x;
    size_t count;
    char *message;

    y = -1;
    count = 0;
    while (arr && arr[++y])
    {
        x = -1;
        while (arr[y][++x])
        {
            if (match_count("NEWS", arr[y][x]))
                count++;
        }
    }
    if (count != 1)
    {
        message = find_replace(ERROR_GENERAL, "$MSG", BAD_D_LINE, 0);
        setError(error, message);
        setStat(error, EXIT_FAILURE);
        nullstr(&message);
    }
    return (count == 1);
}

static bool closed_map(t_error *error, t_map *map)
{
    t_queue *queue;
    bool    valid;
    bool is_border;
    size_t x, y;

    y = 0;
    valid = 1;
    queue = NULL;
    while (map->map2d[y])
    {
        x = 0;
        while (map->map2d[y][x])
        {
            is_border = x == 0 || x == map->width - 1 || y == 0 || y == map->hight - 1;
            if (is_border)
                q_push(&queue, q_create(map->map2d[y][x], x, y));
            x++;
        }
        y++;
    }
    BFS(map, &queue, &valid);
    (void)error;
    return (valid);
}

static void BFS(t_map *map,  t_queue **queue, bool *isvalid)
{
    bool **visited;
    size_t idx;
    t_queue out;
    size_t x, y;
    unsigned char trg;
    
    idx = -1;
    visited = ft_calloc(map->hight, sizeof(bool *));
    if (!visited)
        return;
    while (++idx < map->hight)
        visited[idx] = ft_calloc(map->width, sizeof(bool));
    
    while (*queue && *isvalid)
    {
        q_pop(queue, &out);
        x = out.x;
        y = out.y;
        if (visited[y][x])
            continue;
        visited[y][x] = true;
        trg = out.content;
        if (trg == '1')
            continue;
        else if (trg == ' ')
        {
            if (y > 0)
                q_push(queue, q_create(map->map2d[y - 1][x], x, y - 1));
            if (y < map->hight - 1)
                q_push(queue, q_create(map->map2d[y + 1][x], x, y + 1));
            if (x > 0)
                q_push(queue, q_create(map->map2d[y][x - 1], x - 1, y));
            if (x < map->width - 1)
                q_push(queue, q_create(map->map2d[y][x + 1], x + 1, y));
        }
        else
            *isvalid = false;

    }
    while (q_pop(queue, &out));
    nullarr2d((void***)&visited, map->hight);
}

static bool closed_line(t_error *error, char *line)
{
    char *tmp;
    size_t len;
    char *message;
    
    tmp = ft_strtrim(line, SPACES);
    if (!tmp)
        return (false);
    len = ft_strlen(tmp);
    if (tmp[0] != '1' || tmp[len - 1] != '1')
    {
        message = find_replace(ERROR_GENERAL, "$MSG", BAD_S_LINE, 0);
        setError(error, message);
        setStat(error, EXIT_FAILURE);
        nullstr(&tmp);
        nullstr(&message);
        return (false);
    }
    nullstr(&tmp);
    return (true);
}