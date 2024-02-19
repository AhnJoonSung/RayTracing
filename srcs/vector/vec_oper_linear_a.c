/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_oper_linear_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:15:39 by seongmik          #+#    #+#             */
/*   Updated: 2024/02/19 20:08:36 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vdot(t_vec3 lv, t_vec3 rv)
{
	return ((lv.x * rv.x) + (lv.y * rv.y) + (lv.z * rv.z));
}

t_vec3	vcross(t_vec3 lv, t_vec3 rv)
{
	t_vec3	ret;

	ret.x = lv.y * rv.z - lv.z * rv.y;
	ret.y = lv.x * rv.z - lv.z * rv.x;
	ret.z = lv.x * rv.y - lv.y * rv.x;
	return (ret);
}

double	vlen(t_vec3 v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

t_vec3	vunit(t_vec3 v)
{
	t_vec3	unitv;
	double	len;

	len = vlen(v);
	unitv.x = v.x / len;
	unitv.y = v.y / len;
	unitv.z = v.z / len;
	return (unitv);
}
