/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:12:52 by emabel            #+#    #+#             */
/*   Updated: 2019/08/02 11:52:38 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_ft(void)
{
	int i = 42;
	int *nbr = &i;
	int **nnbr = &nbr;
	int ***nnnbr = &nnbr;
	int ****nnnnbr = &nnnbr;
	int *****nnnnnbr =  &nnnnbr;
	int ******nnnnnnbr = &nnnnnbr;
	int *******nnnnnnnbr = &nnnnnnbr;
	int ********nnnnnnnnbr = &nnnnnnnbr;
	int *********nnnnnnnnnbr = &nnnnnnnnbr;
void main(void)
{
	ft_ft(void);
	printf("%d", nnnnnnnnnbr);
}
