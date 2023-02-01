/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:46:14 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/01 14:06:01 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	my_mouse_hook(int button, int x, int y, t_fract *mand)
{
	mand->offx = mand->xmin + ((double)(x)*(mand->xmax - mand->xmin)) / WIDTH;
	mand->offy = mand->ymin + ((double)(y)*(mand->ymax - mand->ymin)) / HEIGHT;
	if (button == 4)
		ft_zoom(mand, mand->offx, mand->offy);
	else if (button == 5)
		ft_dezoom(mand, mand->offx, mand->offy);
	return (0);
}

void	ft_zoom(t_fract *mand, double offx, double offy)
{
	mand->xmin = offx + ((mand->xmin - offx) / mand->zoom);
	mand->xmax = offx + ((mand->xmax - offx) / mand->zoom);
	mand->ymin = offy + ((mand->ymin - offy) / mand->zoom);
	mand->ymax = offy + ((mand->ymax - offy) / mand->zoom);
	ft_draw(mand);
}

void	ft_dezoom(t_fract *mand, double offx, double offy)
{
	mand->xmin = offx + ((mand->xmin - offx) * mand->zoom);
	mand->xmax = offx + ((mand->xmax - offx) * mand->zoom);
	mand->ymin = offy + ((mand->ymin - offy) * mand->zoom);
	mand->ymax = offy + ((mand->ymax - offy) * mand->zoom);
	ft_draw(mand);
}
