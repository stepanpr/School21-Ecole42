/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 04:14:03 by emabel            #+#    #+#             */
/*   Updated: 2020/10/25 03:27:08 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/errno.h>

size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dst, char *src);
int 	ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char 	*ft_strdup(const char *s);

void test_strlen(void)
{
	printf("\033[1;32m\n=== ft_strlen === \n\033[0m");
	
	printf("\033[33mft_strlen (empt) =>\033[0m %ld\n", ft_strlen(""));
	printf("   \033[35mstrlen (empt) =>\033[0m %ld\n", strlen(""));
	printf("\033[33mft_strlen (medi) =>\033[0m %ld\n", ft_strlen("123456789012345678901234567890"));
	printf("   \033[35mstrlen (medi) =>\033[0m %ld\n", strlen("123456789012345678901234567890"));
	printf("\033[33mft_strlen (long) =>\033[0m %ld\n", ft_strlen("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"));
	printf("   \033[35mstrlen (long) =>\033[0m %ld\n", strlen("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"));
}

void test_strcpy(void)
{
	char dst[1000];
	printf("\033[1;32m\n=== ft_strcpy ===\n\033[0m");
	
	printf("\033[33mft_strcpy (empt) =>\033[0m %s\n", ft_strcpy(dst, ""));
	printf("   \033[35mstrcpy (empt) =>\033[0m %s\n", strcpy(dst, ""));
	printf("\033[33mft_strcpy (medi) =>\033[0m %s\n", ft_strcpy(dst, "medium mediun medium medium medium medium"));
	printf("   \033[35mstrcpy (medi) =>\033[0m %s\n", strcpy(dst, "medium mediun medium medium medium medium"));
	printf("\033[33mft_strcpy (long) =>\033[0m %s\n", ft_strcpy(dst, "long long long long long long long long long long long long long long long long long long long long long long long long"));
	printf("   \033[35mstrcpy (long) =>\033[0m %s\n", strcpy(dst, "long long long long long long long long long long long long long long long long long long long long long long long long"));
}

void test_strcmp(void)
{
	printf("\033[1;32m\n=== ft_strcmp === \n\033[0m");
	
	printf("\033[33mft_strcmp (empt) =>\033[0m %d\n", ft_strcmp("", ""));
	printf("\033[33mft_strcmp (e1st) =>\033[0m %d\n", ft_strcmp("", "string"));
	printf("\033[33mft_strcmp (e2nd) =>\033[0m %d\n", ft_strcmp("string", ""));
	printf("\033[33mft_strcmp (same) =>\033[0m %d\n", ft_strcmp("string", "string"));
	printf("\033[33mft_strcmp (dif+) =>\033[0m %d\n", ft_strcmp("string", "stri"));
	printf("\033[33mft_strcmp (dif-) =>\033[0m %d\n", ft_strcmp("stri", "string"));
}

void test_write(void)
{
	int fd;
	char *str1 = "nasmNASMnasmNASMnasmNASMnasm (ft_write) ";
	char *str2 = "nasmNASMnasmNASMnasmNASMnasm (   write) ";

	printf("\033[1;32m\n=== ft_write ===\033[0m\n");
	
	int wrt1 = ft_write(1, str1, 40);
	printf("\n\t\033[33mft_write's return =>\033[0m %d\n", wrt1);
	int wrt2 = write(1, str2, 40);
	printf("\n\t   \033[35mwrite's return =>\033[0m %d\n\n", wrt2);

	fd = open("write.txt", O_CREAT | O_APPEND | O_WRONLY, S_IRUSR | S_IWUSR | O_TRUNC);
	ft_write(fd, str1, 40);
	printf("\033[33mft_write - good fd (!check write.txt) =>\033[0m %d\n", fd);
	write(fd, str2, 40);
	printf("\033[35m   write - good fd (!check write.txt) =>\033[0m %d\n", fd);
	close(fd);
	
	fd = open("wri.txt", O_WRONLY);
	errno = 0;
	ft_write(fd, str1, 40);
	printf("\033[33mft_write - bad fd =>\033[0m %d \033[33m&& errno:\033[0m %d\n", fd, errno);
	errno = 0;
	write(fd, str2, 40);
	printf("\033[35m   write - bad fd =>\033[0m %d \033[35m&& errno:\033[0m %d\n", fd, errno);
	close(fd);
}

void test_read(void)
{
	int	fd;
	int ret;
	char *buf;

	printf("\033[1;32m\n=== ft_read ===\n\033[0m");

	errno = 0;
	fd = open("write.txt", O_RDONLY);
	buf = malloc(sizeof(char) * 100);
	ret = ft_read(fd, buf, 50);
	buf[50] = '\0';
	printf("\033[33mft_read:\033[0m\nfd => %d\nret => %d\nbuf => %s\nerrno => %d\n\n", fd, ret, buf, errno);
	free(buf);
	close(fd);
	
	errno = 0;
	fd = open("write.txt", O_RDONLY);
	buf = malloc(sizeof(char) * 100);
	ret = read(fd, buf, 50);
	buf[50] = '\0';
	printf("\033[35mread:\033[0m\nfd => %d\nret => %d\nbuf => %s\nerrno => %d\n\n", fd, ret, buf, errno);
	free(buf);
	close(fd);

	errno = 0;
	buf = malloc(sizeof(char) * 100);
	ret = ft_read(-1, buf, 50);
	buf[50] = '\0';
	printf("\033[33mft_read:\033[0m\nfd => %d\nret => %d\nbuf => %s\nerrno => %d\n\n", -1, ret, buf, errno);
	free(buf);

	errno = 0;
	buf = malloc(sizeof(char) * 100);
	ret = read(-1, buf, 50);
	buf[50] = '\0';
	printf("\033[35mread:\033[0m\nfd => %d\nret => %d\nbuf => %s\nerrno => %d\n\n", -1, ret, buf, errno);
	free(buf);
}

void test_strdup(void)
{
	char *str;
	
	printf("\033[1;32m\n=== ft_strdup ===\n\033[0m");
	
	printf("\033[33mempt:\033[0m %s\n", ft_strdup(""));
	printf("\033[33mshrt:\033[0m %s\n", ft_strdup("school21"));
	
	str = ft_strdup("school21school21school21school21school21school21school21school21school21school21school21school21school21school21school21school21school21school21");
	printf("\033[33mlong:\033[0m %s\n", str);
}

int		main(void)
{
	printf("\033[1;31m\n\tLIBASM:\n\033[0m");

	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();
	
	printf("\n");
	return (0);
}
