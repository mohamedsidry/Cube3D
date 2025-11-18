/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:39:38 by msidry            #+#    #+#             */
/*   Updated: 2025/11/18 10:59:24 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"


static void print_map_line(void *content);
void print_raw_map(t_list *map)
{
    if (!map)
    {
        echo("Empty Map List !"); 
        return;  
    }
    ft_lstiter(map, print_map_line);
}

static void print_map_line(void *content)
{
    if (!isMapConfig((char *)content))
    {
        char *colored = find_replace(MAPLINE, "$MAPLINE", (char *)content, 0);
        ft_putendl_fd(colored, 1);
        free (colored);
    }
    else
    {
        char *colored = find_replace(CONFIG, "$CONFIG", (char *)content, 0);
        ft_putendl_fd(colored, 1);
        free (colored);
    }
}


void echo(char *message)
{
    message = find_replace(ECHO_MSG, "$message", message, 0);
    ft_putstr_fd(message, 1);
    free(message);
}
void debug(char *lvl, char *message)
{
    message = find_replace(DEBUG_MSG, "$message", lvl, 0);
    printf("%s\n", message);
    ft_putstr_fd(message, 1);
    free(message);
    free(message);
}

void texture_info(t_texture *texture)
{
    printf("TYPE  : %s\n", texture->type == SOLID ? "COLOR" : "IMAGE");
    printf("PATH  : %s\n", texture->path);
    printf("COLOR : %u\n", texture->rgba);
    printf("ARGB  : (%d,%d,%d,%d) \n", (texture->rgba >> 24) & 0xFF, (texture->rgba >> 16) & 0xFF, texture->rgba >> 8 & 0xFF, texture->rgba & 0xFF);
}
