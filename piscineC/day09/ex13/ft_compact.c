/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 05:38:19 by emabel            #+#    #+#             */
/*   Updated: 2019/08/09 05:41:56 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		size_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

int		ft_compact(char **tab, int length)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	length = 0;
	while (tab[i])
	{
		if (tab[i] == 0)
		{
			k = 0;
			while (tab[i + k + 1])
			{
				j = 0;
				while (tab[i + k + 1][j])
				{
					tab[i + k][j] = tab[i + k + 1][j];
					j++;
				}
				k++;
			}
		}
		i++;
	}
	return (size_tab(tab));
}
