/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:40:40 by msidry            #+#    #+#             */
/*   Updated: 2025/11/18 14:54:50 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/main.h"


char **map_serializer(t_list *list)
{
    char **map2d;
    size_t length;
    size_t idx;
    
    if (!list)
        return (NULL);
    length = ft_lstsize(list) + 1;
    map2d = ft_calloc(length, sizeof(char *));
    if (!map2d)
        return (NULL);
    idx = 0;
    while (list)
    {
        map2d[idx] = ft_strdup((char *)list->content);
        if (!map2d[idx])
        {
            nullarr2d((void***)&map2d, length);
            return (NULL);
        }
        list = list->next;
    }
    return (map2d);
}
