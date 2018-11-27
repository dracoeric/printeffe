/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_con_tab.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:20:49 by erli              #+#    #+#             */
/*   Updated: 2018/11/27 17:31:28 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CON_TAB_H
# define FT_CON_TAB_H

# include "ft_printf.h"

t_conv	g_conv_tab[] =
{
	{'c', &ft_conv_c},
	{'s', &ft_conv_s},
	{'p', &ft_conv_p},
	{'d', &ft_conv_d},
	{'i', &ft_conv_d},
	{'o', &ft_conv_o},
	{'u', &ft_conv_u},
	{'x', &ft_conv_x},
	{'X', &ft_conv_big_x},
	{'f', &ft_conv_f},
	{'F', &ft_conv_f},
	{'e', &ft_conv_e},
	{'E', &ft_conv_big_e},
	{'g', &ft_conv_g},
	{'%', &ft_conv_percent},
	{'\0', &ft_conv_not}
};

t_conv	g_conv_tab_ptr[] =
{
/*	{'c', &ft_conv_c_ptr},
	{'s', &ft_conv_s_ptr},
	{'p', &ft_conv_p_ptr},
*/	{'d', &ft_conv_d_ptr},
	{'i', &ft_conv_d_ptr},
	{'o', &ft_conv_o_ptr},
/*	{'u', &ft_conv_u_ptr},
	{'x', &ft_conv_x_ptr},
	{'X', &ft_conv_big_x_ptr},
	{'f', &ft_conv_f_ptr},
	{'F', &ft_conv_f_ptr},
	{'e', &ft_conv_e_ptr},
	{'E', &ft_conv_big_e_ptr},
	{'g', &ft_conv_g_ptr},
	{'%', &ft_conv_percent},*/
	{'\0', &ft_conv_not}
};

#endif
