/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:13:59 by msidry            #+#    #+#             */
/*   Updated: 2025/11/15 19:47:17 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

// STD HEADERS
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>

// CUSTOM HEADERS
# include "../libs/libft/libft.h"
# include "typedef.h"
# include "error.h"
# include "const.h"

// INIT GAME 
void game_init(t_game **ref, int argc, char *argv[]);
void game_destroy(t_game **ref);
// ERROR HANDLING
bool		init_error(t_game *container);
void		setError(t_error *error, char *msg);
void		setStat(t_error *error, int stat);
int		what(t_error *error);
void		putError(char *msg);

// VALIDATION
void		validatorInput(t_game *game);
void		isAllGood(t_game **ref);
bool        isAllOk(t_game *ref);

// MAP && scene
void init_map(t_game *ref);



// HELPER
char	*concat3(char *str1, char *str2, char *sep, int tofree);
char	*find_replace(char *src, char *target, char *new, int usefree);
#endif
