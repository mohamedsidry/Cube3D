/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:28:09 by msidry            #+#    #+#             */
/*   Updated: 2025/11/15 16:52:53 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"


bool init_error(t_game *container)
{
    if (container)
    {
        setStat(&container->error, 0);
        setError(&container->error, NULL);
        return (false);
    }
    return (true);
}

void setError(t_error *error, char *msg)
{
    if (!error)
        return ;
    free(error->message);
    if (!msg)
        error->message = NULL;
    else 
        error->message = ft_strdup(msg);
}
void setStat(t_error *error, int stat)
{
    if (!error)
        return ;
    error->stat = stat;
}

int what(t_error *error)
{
    if (error->stat)
        putError(error->message);
    return (error->stat);
}
void putError(char *msg)
{
    ft_putendl_fd(msg, 2);
}
