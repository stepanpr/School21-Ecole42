/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:53:55 by emabel            #+#    #+#             */
/*   Updated: 2020/07/30 16:48:06 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>				
 

int main() 
{ 
	int len = 0;
	
	ft_printf("\nft_printf || ");
		ft_printf("%c ww   www%cww w%c\n", 'f', 'f', 'f');
	ft_printf("   printf || ");
		printf("%c ww   www%cww w%c\n\n", 'f', 'f', 'f');
	
	ft_printf("ft_printf || ");
		ft_printf("%c", 'f');
	ft_printf("   printf || ");
		printf("%c\n\n", 'f');
	
	ft_printf("ft_printf || ");
		ft_printf("%-*.*d\n", 5, 7, -222222223);
	ft_printf("   printf || ");
		printf("%d\n\n", -222222223);
	
	ft_printf("ft_printf || ");
		ft_printf("%s\n", "abcde");
	ft_printf("   printf || ");
		printf("%s\n\n", "abcde");

	ft_printf("ft_printf || ");
		ft_printf("%x\n", -14000888);
	ft_printf("   printf || ");
		printf("%x\n\n", -14000888);

	ft_printf("ft_printf || ");
		ft_printf("%X\n", -14000888);
	ft_printf("   printf || ");
		printf("%X\n\n", -14000888);

	ft_printf("ft_printf || ");
		ft_printf("%u\n", -429496723);
	ft_printf("   printf || ");
		printf("%u\n\n", -429496723);

	ft_printf("ft_printf || ");
		ft_printf("%%%%%%%%%%\n");
	ft_printf("   printf || ");
		printf("%%%%%%%%%%\n\n");





		

		

		len = ft_printf("%30.10d 1234567890", 57);
			printf("\n");
		printf("len = %d\n", len);
		len = printf("%30.10d 1234567890", 57);
				printf("\n");
		printf("len = %d\n\n", len);

		len = ft_printf("%15s 1234567890", "-string  |");
			printf("\n");
		printf("len = %d\n", len);
		len = printf("%15s 1234567890", "-string  |");
				printf("\n");
		printf("len = %d\n\n", len);

		len = ft_printf("%s 1234567890", "-string  |");
			printf("\n");
		printf("len = %d\n", len);
		len = printf("%s 1234567890", "-string  |");
				printf("\n");
		printf("len = %d\n\n", len);

		len = ft_printf("%c12345678", 'L');
			printf("\n");
		printf("len = %d\n", len);
		len = printf("%c12345678", 'L');
				printf("\n");
		printf("len = %d\n\n", len);

		// len = ft_printf("%p 1234567890", 57888);
		// 	printf("\n");
		// printf("len = %d\n", len);
		// len = printf("%p 1234567890", 57888);
		// 		printf("\n");
		// printf("len = %d\n\n", len);

		len = ft_printf("%-55.10X 1234567890", 57655);
			printf("\n");
		printf("len = %d\n", len);
		len = printf("%-55.10X 1234567890", 57655);
				printf("\n");
		printf("len = %d\n\n", len);
		
		len = ft_printf("%-30.6s 1234567890", "-string ddd |");
			printf("\n");
		printf("len = %d\n", len);
		len = printf("%-30.6s 1234567890", "-string ddd |");
				printf("\n");
		printf("len = %d\n\n", len);
		
		len = ft_printf("%23.10u | %s | %X ...", -577, "string", 7777);
			printf("\n");
		printf("len = %d\n", len);
		len = printf("%23.10u | %s | %X ...", -577, "string", 7777);
				printf("\n");
		printf("len = %d\n\n", len);

		len = ft_printf("%23.6d | %s | %X ...", -577, "string", 7777);
			printf("\n");
		printf("len = %d\n", len);
		len = printf("%23.6d | %s | %X ...", -577, "string", 7777);
				printf("\n");
		printf("len = %d\n\n", len);

		ft_printf("%50.1i", 777666178);
		printf("|");
		printf("\n");
		printf("%50.1i", 777666178);
		printf("|\n\n");
		
		ft_printf("%90.*i", 30, 777666178);
		printf("|");
		printf("\n");
		printf("%90.*u", 30, 777666178);
		printf("|\n\n");
		
		ft_printf("p = NULL = %9.1p\n", NULL);
		ft_printf("p = NULL = %.5p\n", NULL);
		ft_printf("p = %2.9p\n", 1234);
		
		ft_printf("%.03s\n", NULL);
		ft_printf("%0*i", 7, -54);
		
	return 0;
} 
