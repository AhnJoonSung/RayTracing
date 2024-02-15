/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooahn <jooahn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:37:32 by jooahn            #+#    #+#             */
/*   Updated: 2024/02/15 09:23:22 by jooahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "data.h"

typedef struct s_color	t_color;

struct					s_color
{
	t_component			r;
	t_component			g;
	t_component			b;
};

t_color					color(t_component r, t_component g, t_component b);
void					write_color(t_color color);

#endif
