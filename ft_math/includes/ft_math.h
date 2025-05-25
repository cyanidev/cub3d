/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:57:08 by acaceres          #+#    #+#             */
/*   Updated: 2025/05/25 23:01:54 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H
# define PI 3.1415926535
# define DR 0.0174533
# ifndef FLT_MAX
#  define FLT_MAX 3.40282347e+38F
# endif
# ifndef FLT_MIN
#  define FLT_MIN 1.17549435e-38F
# endif
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include "Q_rsqrt.h"

long double	ft_abs(long double n);

#endif
