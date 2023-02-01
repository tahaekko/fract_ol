/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamhaou <msamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 01:15:12 by msamhaou          #+#    #+#             */
/*   Updated: 2023/02/01 01:45:36 by msamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	ft_fract_init(t_fract *fract)
{
	if (fract->set == 0)
		ft_mand_init(fract);
	else if (fract->set == 1)
		ft_julia_init(fract);
	else if (fract->set == 2)
		ft_ship_init(fract);
}

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}
