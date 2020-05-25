/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:09:36 by emabel            #+#    #+#             */
/*   Updated: 2019/08/07 22:50:40 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	if (argc >= 2)
	{
		while (argv[i] != '\0')
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				ft_putchar(argv[i][j++]);
			}
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
