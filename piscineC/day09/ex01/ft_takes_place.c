/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:30:49 by emabel            #+#    #+#             */
/*   Updated: 2019/08/08 18:22:32 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_takes_place(int hour)
{
	char *times[24] = {
		"THE FOLLOWING TAKES PLACE BETWEEN 12.00 A.M. AND 01.00 A.M.\n", 
		"THE FOLLOWING TAKES PLACE BETWEEN 01.00 A.M. AND 02.00 A.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 02.00 A.M. AND 03.00 A.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 03.00 A.M. AND 04.00 A.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 04.00 A.M. AND 05.00 A.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 05.00 A.M. AND 06.00 A.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 06.00 A.M. AND 07.00 A.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 07.00 A.M. AND 08.00 A.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 08.00 A.M. AND 09.00 A.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 09.00 A.M. AND 10.00 A.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 10.00 A.M. AND 11.00 A.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 11.00 A.M. AND 12.00 P.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 12.00 P.M. AND 01.00 P.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 01.00 P.M. AND 02.00 P.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 02.00 P.M. AND 03.00 P.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 03.00 P.M. AND 04.00 P.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 04.00 P.M. AND 05.00 P.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 05.00 P.M. AND 06.00 P.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 06.00 P.M. AND 07.00 P.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 07.00 P.M. AND 08.00 P.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 08.00 P.M. AND 09.00 P.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 09.00 P.M. AND 10.00 P.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 10.00 P.M. AND 11.00 P.M.\n",
		"THE FOLLOWING TAKES PLACE BETWEEN 11.00 P.M. AND 12.00 A.M.\n"};
	write(1, times[hour], 60); 
}
