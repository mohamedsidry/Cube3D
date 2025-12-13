/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_texture_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:41:23 by msidry            #+#    #+#             */
/*   Updated: 2025/12/13 11:43:46 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


static bool valid_rgba(char *color);
static bool valid_hexa(char *color);

void rgba_handler(t_error *error, t_texture *texture, char *rgbacolor)
{
    char *color;
    size_t len;

    while (is_space(*rgbacolor))
        rgbacolor++;
    len = ft_strlen(rgbacolor);
    if (len && *rgbacolor == '(' && rgbacolor[len - 1] == ')')
        color = ft_substr(rgbacolor, 1, ft_strlen(&rgbacolor[1]) - 1);
    else
        color = ft_strdup(rgbacolor);
    if (!valid_rgba(color))
    {
        setError(error, ERROR_FORMAT);   
        setStat(error, EXIT_FAILURE);
        nullstr(&color);
        return ;
    }
    texture->type = SOLID;
    texture->rgba = rgbatoint(color);
    texture->isvalid = true;
    nullstr(&color);
}


static bool valid_rgba(char *color)
{
    int len;
    int idx;
    int jdx;
    char **rgba;
    if (!color || !*color)
        return (false);
    rgba = ft_split(color, ',');
    idx = -1;
    while (rgba[++idx])
    {
        len = -1;
        jdx = -1;
        while (is_space(rgba[idx][++jdx]));
        while (rgba[idx][++len + jdx])
        {
            if (!ft_isdigit(rgba[idx][jdx + len]))
                break;
        }
        if (len == 0 || len > 4 ||
         ft_strncmp(color, "255", 3) > 0 ||
         !contain_only(&rgba[idx][jdx + len], SPACES))
            return false;
    }
    return (nullarr2d((void ***)&rgba, idx), true);
}




void hexa_handler(t_error *error, t_texture *texture, char *hexacolor)
{
    char *color;
    size_t len;

    while (is_space(*hexacolor))
        hexacolor++;
    len = ft_strlen(hexacolor);
    if (!valid_hexa(hexacolor))
    {
        setError(error, ERROR_FORMAT);   
        setStat(error, EXIT_FAILURE);
        return ;
    }
    if (len == 6)
        color = concat3(capitalize(hexacolor), "FF", NULL, 1);
    else
        color = concat3(capitalize(hexacolor), NULL, NULL, 1);
    texture->type = SOLID;
    texture->rgba = hexatoint(color);
    texture->isvalid = true;
    nullstr(&color);
}

static bool valid_hexa(char *color)
{
    size_t len;

    if (!color)
        return (false);
    len = ft_strlen(color);
    if (len != 6 && len != 8)
        return (false);
    if (!contain_only(color, HEXASET))
        return (false);
    return (true);
}
