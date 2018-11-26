/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_con_tab.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:20:49 by erli              #+#    #+#             */
/*   Updated: 2018/11/26 13:17:15 by erli             ###   ########.fr       */
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
	{'e', &ft_conv_e},
	{'%', &ft_conv_percent},
	{'\0', &ft_conv_not}
};

#endif
