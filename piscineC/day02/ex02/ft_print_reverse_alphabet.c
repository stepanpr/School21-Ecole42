/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 23:38:44 by emabel            #+#    #+#             */
/*   Updated: 2019/08/01 23:42:27 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
i
void	ft_print_reverse_alphabet(void)
{
	char letter;

	letter = 0;
	while (letter <= 9)
	{
		ft_putchar(letter + '0');
		letter = letter - 1;
	}
}
