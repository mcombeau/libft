/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:55:32 by mcombeau          #+#    #+#             */
/*   Updated: 2021/12/07 12:12:51 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../libft.h"
#include <limits.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

/*
 *	Check if allowed <stddef.h> for functions with size_t (ft_memset).
 *	Check why original function segfaults but ft doesn't.
 *	Test MEMSET more
 *	FIX MEMMOVE!!!!!
 *
 *
 *
 * 
 * */

void	ft_putstr(char *s)
{
	while (*s != '\0')
		write(1, s++, 1);
}

void	test_isalpha(void)
{
	printf("=========== TESTING IS ALPHA ============\n\n");
	char	c;

	printf("char\t:\tReal\t:\tFT\n");
	c = 'a';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = 'A';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = 'z';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = 'Z';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = 's';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = 'F';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = ' ';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = '3';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = ',';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = 0;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = '`';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = '{';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = '@';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
	c = '[';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalpha(c), (ft_isalpha(c) != 0) ? 1 : 0);
}

void	test_isdigit(void)
{
	printf("\n\n=========== TESTING IS DIGIT ============\n\n");
	char	c;

	printf("char\t:\tReal\t:\tFT\n");
	c = '0';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isdigit(c), (ft_isdigit(c) != 0) ? 1 : 0);
	c = '9';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isdigit(c), (ft_isdigit(c) != 0) ? 1 : 0);
	c = '6';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isdigit(c), (ft_isdigit(c) != 0) ? 1 : 0);
	c = 'f';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isdigit(c), (ft_isdigit(c) != 0) ? 1 : 0);
	c = '\\';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isdigit(c), (ft_isdigit(c) != 0) ? 1 : 0);
	c = ':';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isdigit(c), (ft_isdigit(c) != 0) ? 1 : 0);
	c = -1;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isdigit(c), (ft_isdigit(c) != 0) ? 1 : 0);
}

void	test_isalnum(void)
{
	printf("\n\n=========== TESTING IS ALPHANUMERIC ============\n\n");
	char	c;

	printf("char\t:\tReal\t:\tFT\n");
	c = 'a';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = 'z';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = 'A';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = 'Z';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = '0';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = '9';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = 'm';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = 'L';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = '6';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = '@';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = '[';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = '`';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = '{';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = '\\';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
	c = ':';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isalnum(c), (ft_isalnum(c) != 0) ? 1 : 0);
}

void	test_isascii(void)
{
	printf("\n\n=========== TESTING IS ASCII ============\n\n");
	char	c;

	printf("char\t:\tReal\t:\tFT\n");
	c = 0;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isascii(c), (ft_isascii(c) != 0) ? 1 : 0);
	c = 127;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isascii(c), (ft_isascii(c) != 0) ? 1 : 0);
	c = 'a';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isascii(c), (ft_isascii(c) != 0) ? 1 : 0);
	c = -1;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isascii(c), (ft_isascii(c) != 0) ? 1 : 0);
	c = -30;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isascii(c), (ft_isascii(c) != 0) ? 1 : 0);
}

void	test_isprint(void)
{
	printf("\n\n=========== TESTING IS PRINT ============\n\n");
	char	c;

	printf("char\t:\tReal\t:\tFT\n");
	c = ' ';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isprint(c), (ft_isprint(c) != 0) ? 1 : 0);
	c = '~';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isprint(c), (ft_isprint(c) != 0) ? 1 : 0);
	c = 'a';
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isprint(c), (ft_isprint(c) != 0) ? 1 : 0);
	c = 43;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isprint(c), (ft_isprint(c) != 0) ? 1 : 0);
	c = 31;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isprint(c), (ft_isprint(c) != 0) ? 1 : 0);
	c = 127;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isprint(c), (ft_isprint(c) != 0) ? 1 : 0);
	c = -1;
	printf("\'%c\'\t:\t%d\t:\t%d\n", c, isprint(c), (ft_isprint(c) != 0) ? 1 : 0);
}

void	test_strlen(void)
{
	printf("\n\n=========== TESTING STRLEN ============\n\n");

	if (strlen("Hello") == ft_strlen("Hello"))
		printf("OK: expected %zu, got %zu. [test string \"Hello\".]\n", strlen("Hello"), ft_strlen("Hello"));
	else
		printf("Try again: expected %zu, got %zu [test string \" \".]\n", strlen("Hello"), ft_strlen("Hello"));
	
	if (strlen(" ") == ft_strlen(" "))
		printf("OK: expected %zu, got %zu. [test string \" \".]\n", strlen(" "), ft_strlen(" "));
	else
		printf("Try again: expected %zu, got %zu [test string \" \".]\n", strlen(" "), ft_strlen(" "));
	
	
	if (strlen("") == ft_strlen(""))
		printf("OK: expected %zu, got %zu. [test string \"\".]\n", strlen(""), ft_strlen(""));
	else
		printf("Try again: expected %zu, got %zu [test string \"\".]\n", strlen(""), ft_strlen(""));
	
	if (strlen("123456789123456789") == ft_strlen("123456789123456789"))
		printf("OK: expected %zu, got %zu. [test string \"123456789123456789\".]\n", strlen("123456789123456789"), ft_strlen("123456789123456789"));
	else
		printf("Try again: expected %zu, got %zu [test string \"123456789123456789\".]\n", strlen("123456789123456789"), ft_strlen("123456789123456789"));
	
	if (strlen("\0") == ft_strlen("\0"))
		printf("OK: expected %zu, got %zu. [test string \"\\0\".]\n", strlen("\0"), ft_strlen("\0"));
	else
		printf("Try again: expected %zu, got %zu [test string \"\\0\".]\n", strlen("\0"), ft_strlen("\0"));	
}

void	test_memset(void)
{
	printf("\n\n=========== TESTING MEMSET ============\n\n");

	char orsrc[20] = "Hello World";
	char ftsrc[20] = "Hello World";

	if(!strcmp(memset(orsrc, 'o', 3), ft_memset(ftsrc, 'o', 3)))
			printf("OK: expected \"%s\", got \"%s\".\n", orsrc, ftsrc);
	else
			printf("Try again: expected \"%s\", got \"%s\".\n", orsrc, ftsrc);
	if(!strcmp(memset(orsrc, 'x', 15), ft_memset(ftsrc, 'x', 15)))
			printf("OK: expected \"%s\", got \"%s\".\n", orsrc, ftsrc);
	else
			printf("Try again: expected \"%s\", got \"%s\".\n", orsrc, ftsrc);
	if(!strcmp(memset(orsrc, '~', 5), ft_memset(ftsrc, '~', 5)))
			printf("OK: expected \"%s\", got \"%s\".\n", orsrc, ftsrc);
	else
			printf("Try again: expected \"%s\", got \"%s\".\n", orsrc, ftsrc);
}

void	test_bzero(void)
{
	printf("\n\n=========== TESTING BZERO ============\n\n");

	char	sori[20] = "abcdef";
	char	sft[20] = "abcdef";
	bzero(sori, 4);
	ft_bzero(sft, 4);
	int	i;
	i = 0;

	while (i < 6 && sori[i] == sft[i])
		i++;
	if (i == 6)
		printf("OK: expected [%c] [%c] [%c] [%c] [%c] [%c], got [%c] [%c] [%c] [%c] [%c] [%c].\n", sori[0], sori[1], sori[2], sori[3], sori[4], sori[5], sft[0], sft[1], sft[2], sft[3], sft[4], sft[5]);

	else
		printf("Try again: expected [%c] [%c] [%c] [%c] [%c] [%c], got [%c] [%c] [%c] [%c] [%c] [%c].\n", sori[0], sori[1], sori[2], sori[3], sori[4], sori[5], sft[0], sft[1], sft[2], sft[3], sft[4], sft[5]);
}

void	test_memcpy(void)
{
	printf("\n\n=========== TESTING MEMCPY ============\n\n");

	char	dest0[20] = "World";
	char	dest1[20] = "World";

	if(!strcmp(memcpy(dest0, "source", 3), ft_memcpy(dest1, "source", 3)))
		printf("OK: expected \"%s\", got \"%s\".\n", dest0, dest1);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", dest0, dest1);
	if(!strcmp(memcpy(dest0, "123456source", 9), ft_memcpy(dest1, "123456source", 9)))
		printf("OK: expected \"%s\", got \"%s\".\n", dest0, dest1);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", dest0, dest1);
	if(!strcmp(memcpy(dest0, "123456source", 0), ft_memcpy(dest1, "123456source", 0)))
		printf("OK: expected \"%s\", got \"%s\".\n", dest0, dest1);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", dest0, dest1);
}

void	test_memmove(void)
{
	printf("\n\n=========== TESTING MEMMOVE ============\n\n");

	char	srcdest[20] = "a1b2c3d4e5f6g7";
	char	ftsrcdest[20] = "a1b2c3d4e5f6g7";
	
	if (!strcmp((char *)memmove(srcdest + 2, srcdest, 7), (char *)ft_memmove(ftsrcdest +2, ftsrcdest, 7)))
		printf("OK: expected \"%s\", got \"%s\".\n", srcdest, ftsrcdest);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", srcdest, ftsrcdest);
		
	if (!strcmp((char *)memmove(srcdest + 4, srcdest, 7), (char *)ft_memmove(ftsrcdest +4, ftsrcdest, 7)))
		printf("OK: expected \"%s\", got \"%s\".\n", srcdest, ftsrcdest);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", srcdest, ftsrcdest);

	if (!strcmp((char *)memmove(srcdest, srcdest + 8, 7), (char *)ft_memmove(ftsrcdest, ftsrcdest + 8, 7)))
		printf("OK: expected \"%s\", got \"%s\".\n", srcdest, ftsrcdest);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", srcdest, ftsrcdest);

	if (!strcmp((char *)memmove(srcdest + 2, srcdest, 0), (char *)ft_memmove(ftsrcdest +2, ftsrcdest, 0)))
		printf("OK: expected \"%s\", got \"%s\".\n", srcdest, ftsrcdest);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", srcdest, ftsrcdest);

	if (!strcmp((char *)memmove(srcdest, srcdest, 5), (char *)ft_memmove(ftsrcdest, ftsrcdest, 5)))
		printf("OK: expected \"%s\", got \"%s\".\n", srcdest, ftsrcdest);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", srcdest, ftsrcdest);

}
/*
void	test_strlcpy(void)
{
	printf("\n\n=========== TESTING STRLCPY ============\n\n");

	char	dstor[20] = "Hello World!";
	char	dstft[20] = "Hello World!";
 
	if ((strlcpy(dstor, "123456789", 5) == ft_strlcpy(dstft, "123456789", 5)) && !strcmp(dstor, dstft))
		printf("OK: expected \"%s\", got \"%s\".\n", dstor, dstft);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", dstor, dstft);

	if ((strlcpy(dstor, "", 5) == ft_strlcpy(dstft, "", 5)) && !strcmp(dstor, dstft))
		printf("OK: expected \"%s\", got \"%s\".\n", dstor, dstft);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", dstor, dstft);

	if ((strlcpy(dstor, "Help", 4) == ft_strlcpy(dstft, "Help", 4)) && !strcmp(dstor, dstft))
		printf("OK: expected \"%s\", got \"%s\".\n", dstor, dstft);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", dstor, dstft);
}

void	test_strlcat(void)
{
	printf("\n\n=========== TESTING STRLCAT ============\n\n");

	char	catdstor[20] = "123";
	char	catdstft[20] = "123";

	if ((strlcat(catdstor, "Hey", 4) == strlcat(catdstft, "Hey", 4)) && !strcmp(catdstor, catdstft))
		printf("OK: expected \"%s\", got \"%s\".\n", catdstor, catdstft);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", catdstor, catdstft);

	if ((strlcat(catdstor, "CoucouCommentVa", 15) == strlcat(catdstft, "CoucouCommentVa", 15)) && !strcmp(catdstor, catdstft))
		printf("OK: expected \"%s\", got \"%s\".\n", catdstor, catdstft);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", catdstor, catdstft);
	
	if ((strlcat(catdstor, "xx", 20) == strlcat(catdstft, "xx", 20)) && !strcmp(catdstor, catdstft))
		printf("OK: expected \"%s\", got \"%s\".\n", catdstor, catdstft);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", catdstor, catdstft);
	
	if ((strlcat(catdstor, "o", 2) == strlcat(catdstft, "o", 2)) && !strcmp(catdstor, catdstft))
		printf("OK: expected \"%s\", got \"%s\".\n", catdstor, catdstft);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", catdstor, catdstft);
}
*/
void	test_toupper(void)
{
	printf("\n\n=========== TESTING TO UPPER ============\n\n");
	char	c;

	printf("char\t:\tReal\t:\tFT\n");
	c = 'a';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, toupper(c), ft_toupper(c));
	c = 'w';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, toupper(c), ft_toupper(c));
	c = 'A';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, toupper(c), ft_toupper(c));
	c = ' ';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, toupper(c), ft_toupper(c));
	c = '3';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, toupper(c), ft_toupper(c));
	c = '~';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, toupper(c), ft_toupper(c));
	c = '*';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, toupper(c), ft_toupper(c));
}

void	test_tolower(void)
{
	printf("\n\n=========== TESTING TO LOWER ============\n\n");
	char	c;

	printf("char\t:\tReal\t:\tFT\n");
	c = 'A';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, tolower(c), ft_tolower(c));
	c = 'W';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, tolower(c), ft_tolower(c));
	c = 'a';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, tolower(c), ft_tolower(c));
	c = ' ';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, tolower(c), ft_tolower(c));
	c = '3';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, tolower(c), ft_tolower(c));
	c = '~';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, tolower(c), ft_tolower(c));
	c = '*';
	printf("\'%c\'\t:\t\'%c\'\t:\t\'%c\'\n", c, tolower(c), ft_tolower(c));
}

void	test_strchr(void)
{
	printf("\n\n=========== TESTING STRCHR ============\n\n");

	char *str = "Coucou la ville!";

	if (!strcmp(strchr(str, 'C'), ft_strchr(str, 'C')))
		printf("OK: expected \"%s\", got \"%s\".\n", strchr(str, 'C'), ft_strchr(str, 'C'));
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", strchr(str, 'C'), ft_strchr(str, 'C'));

	if (!strcmp(strchr(str, 'u'), ft_strchr(str, 'u')))
		printf("OK: expected \"%s\", got \"%s\".\n", strchr(str, 'u'), ft_strchr(str, 'u'));
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", strchr(str, 'u'), ft_strchr(str, 'u'));

	if (!strcmp(strchr(str, 'v'), ft_strchr(str, 'v')))
		printf("OK: expected \"%s\", got \"%s\".\n", strchr(str, 'v'), ft_strchr(str, 'v'));
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", strchr(str, 'v'), ft_strchr(str, 'v'));

	if (!strcmp(strchr(str, 'l'), ft_strchr(str, 'l')))
		printf("OK: expected \"%s\", got \"%s\".\n", strchr(str, 'l'), ft_strchr(str, 'l'));
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", strchr(str, 'l'), ft_strchr(str, 'l'));

	if (!strcmp(strchr(str, '\0'), ft_strchr(str, '\0')))
		printf("OK: expected \"%s\", got \"%s\".\n", strchr(str, '\0'), ft_strchr(str, '\0'));
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", strchr(str, '\0'), ft_strchr(str, '\0'));


	if (strchr(str, 'x') == ft_strchr(str, 'x'))
		printf("OK: expected \"%s\", got \"%s\".\n", strchr(str, 'x'), ft_strchr(str, 'x'));
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", strchr(str, 'x'), ft_strchr(str, 'x'));
}

void	test_strrchr(void)
{
	printf("\n\n=========== TESTING STRRCHR ============\n\n");

	char *strr = "Coucou la ville!";

	if (!strcmp(strrchr(strr, 'C'), ft_strrchr(strr, 'C')))
		printf("OK: expected \"%s\", got \"%s\".\n", strrchr(strr, 'C'), ft_strrchr(strr, 'C'));
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", strrchr(strr, 'C'), ft_strrchr(strr, 'C'));

	if (!strcmp(strrchr(strr, 'u'), ft_strrchr(strr, 'u')))
		printf("OK: expected \"%s\", got \"%s\".\n", strrchr(strr, 'u'), ft_strrchr(strr, 'u'));
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", strrchr(strr, 'u'), ft_strrchr(strr, 'u'));

	if (!strcmp(strrchr(strr, 'v'), ft_strrchr(strr, 'v')))
		printf("OK: expected \"%s\", got \"%s\".\n", strrchr(strr, 'v'), ft_strrchr(strr, 'v'));
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", strrchr(strr, 'v'), ft_strrchr(strr, 'v'));

	if (!strcmp(strrchr(strr, 'l'), ft_strrchr(strr, 'l')))
		printf("OK: expected \"%s\", got \"%s\".\n", strrchr(strr, 'l'), ft_strrchr(strr, 'l'));
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", strrchr(strr, 'l'), ft_strrchr(strr, 'l'));

	if (!strcmp(strrchr(strr, '\0'), ft_strrchr(strr, '\0')))
		printf("OK: expected \"%s\", got \"%s\".\n", strrchr(strr, '\0'), ft_strrchr(strr, '\0'));
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", strrchr(strr, '\0'), ft_strrchr(strr, '\0'));


	if (strrchr(strr, 'x') == ft_strrchr(strr, 'x'))
		printf("OK: expected \"%s\", got \"%s\".\n", strrchr(strr, 'x'), ft_strrchr(strr, 'x'));
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", strrchr(strr, 'x'), ft_strrchr(strr, 'x'));
}

void	test_strncmp(void)
{
	printf("\n\n=========== TESTING STRNCMP ============\n\n");
	
	char	s1[50] = "Hello there are 75 days left.";
	char	s2[50] = "Hello there are 75 days left.";
	
	if (strncmp(s1, s2, 20) == ft_strncmp(s1, s2, 20))
		printf("OK: expected %d, got %d.\n", strncmp(s1, s2, 20), ft_strncmp(s1, s2, 20));
	else
		printf("Try again: expected %d, got %d.\n", strncmp(s1, s2, 20), ft_strncmp(s1, s2, 20));
	
	if (strncmp(s1, s2, 0) == ft_strncmp(s1, s2, 0))
		printf("OK: expected %d, got %d.\n", strncmp(s1, s2, 0), ft_strncmp(s1, s2, 0));
	else
		printf("Try again: expected %d, got %d.\n", strncmp(s1, s2, 0), ft_strncmp(s1, s2, 0));
	
	s2[14] = ' ';
	if (strncmp(s1, s2, 20) == ft_strncmp(s1, s2, 20))
		printf("OK: expected %d, got %d.\n", strncmp(s1, s2, 20), ft_strncmp(s1, s2, 20));
	else
		printf("Try again: expected %d, got %d.\n", strncmp(s1, s2, 20), ft_strncmp(s1, s2, 20));
	
	s2[14] = '~';
	if (strncmp(s1, s2, 20) == ft_strncmp(s1, s2, 20))
		printf("OK: expected %d, got %d.\n", strncmp(s1, s2, 20), ft_strncmp(s1, s2, 20));
	else
		printf("Try again: expected %d, got %d.\n", strncmp(s1, s2, 20), ft_strncmp(s1, s2, 20));
	
	if (strncmp(s1, s2, 9) == ft_strncmp(s1, s2, 9))
		printf("OK: expected %d, got %d.\n", strncmp(s1, s2, 9), ft_strncmp(s1, s2, 9));
	else
		printf("Try again: expected %d, got %d.\n", strncmp(s1, s2, 9), ft_strncmp(s1, s2, 9));
	
	strcpy(s2, "");
	if (strncmp(s1, s2, 20) == ft_strncmp(s1, s2, 20))
		printf("OK: expected %d, got %d.\n", strncmp(s1, s2, 20), ft_strncmp(s1, s2, 20));
	else
		printf("Try again: expected %d, got %d.\n", strncmp(s1, s2, 20), ft_strncmp(s1, s2, 20));

	strcpy(s2, "Hello there are tree days left");
	if (strncmp(s1, s2, 20) == ft_strncmp(s1, s2, 20))
		printf("OK: expected %d, got %d.\n", strncmp(s1, s2, 20), ft_strncmp(s1, s2, 20));
	else
		printf("Try again: expected %d, got %d.\n", strncmp(s1, s2, 20), ft_strncmp(s1, s2, 20));
}
/*
void	test_memchr(void)
{
	printf("\n\n=========== TESTING MEMCHR ============\n\n");

	char *memstr = "Allons-y vite!";

	if (!strcmp((char *)memchr(memstr, 'l', 5), (char *)ft_memchr(memstr, 'l', 5)))
		printf("OK: expected \"%s\", got \"%s\".\n", (char *)memchr(memstr, 'l', 5), (char *)ft_memchr(memstr, 'l', 5));
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", (char *)memchr(memstr, 'l', 5), (char *)ft_memchr(memstr, 'l', 5));
	
	if (!strcmp((char *)memchr(memstr, 'y', 10), (char *)ft_memchr(memstr, 'y', 10)))
		printf("OK: expected \"%s\", got \"%s\".\n", (char *)memchr(memstr, 'y', 10), (char *)ft_memchr(memstr, 'y', 10));
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", (char *)memchr(memstr, 'y', 10), (char *)ft_memchr(memstr, 'y', 10));

	if ((char *)memchr(memstr, 'y', 2) == 0 && ft_memchr(memstr, 'y', 2) == 0)
		printf("OK: expected \"%p\", got \"%p\".\n", memchr(memstr, 'y', 2), ft_memchr(memstr, 'y', 2));
	else
		printf("Try again: expected \"%p\", got \"%p\".\n", memchr(memstr, 'y', 2), ft_memchr(memstr, 'y', 2));

	if (memchr(memstr, 'y', 0) == 0 && ft_memchr(memstr, 'y', 0) == 0)
		printf("OK: expected \"%p\", got \"%p\".\n", memchr(memstr, 'y', 0), ft_memchr(memstr, 'y', 0));
	else
		printf("Try again: expected \"%p\", got \"%p\".\n", memchr(memstr, 'y', 0), ft_memchr(memstr, 'y', 0));

	if (memchr(memstr, 'x', 20) == 0 && ft_memchr(memstr, 'x', 20) == 0)
		printf("OK: expected \"%p\", got \"%p\".\n", memchr(memstr, 'x', 20), ft_memchr(memstr, 'x', 20));
	else
		printf("Try again: expected \"%p\", got \"%p\".\n", memchr(memstr, 'x', 20), ft_memchr(memstr, 'x', 20));

	if (!strcmp((char *)memchr(memstr, '\0', 20), (char *)ft_memchr(memstr, '\0', 20)))
		printf("OK: expected \"%s\", got \"%s\".\n", (char *)memchr(memstr, '\0', 20), (char *)ft_memchr(memstr, '\0', 20));
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", (char *)memchr(memstr, '\0', 20), (char *)ft_memchr(memstr, '\0', 20));

	char memstr2[20] = "/|\x12\xff\x09\x42\2002\42|\\";
	int size = 10;

	if (memchr(memstr2, '\200', size) == ft_memchr(memstr2, '\200', size))
		printf("OK: expected \"%s\", got \"%s\".\n", memchr(memstr2, '\200', size), ft_memchr(memstr2, '\200', size));
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", memchr(memstr2, '\200', size), ft_memchr(memstr2, '\200', size));
}
*/
void	test_memcmp(void)
{
	printf("\n\n=========== TESTING MEMCMP ============\n\n");
	
	char	s1[50] = "Just in time for doing c.";
	char	s2[50] = "Just in time for doing c.";
	
	if (memcmp(s1, s2, 20) == ft_memcmp(s1, s2, 20))
		printf("OK: expected %d, got %d.\n", memcmp(s1, s2, 20), ft_memcmp(s1, s2, 20));
	else
		printf("Try again: expected %d, got %d.\n", memcmp(s1, s2, 20), ft_memcmp(s1, s2, 20));
	
	if (memcmp(s1, s2, 0) == ft_memcmp(s1, s2, 0))
		printf("OK: expected %d, got %d.\n", memcmp(s1, s2, 0), ft_memcmp(s1, s2, 0));
	else
		printf("Try again: expected %d, got %d.\n", memcmp(s1, s2, 0), ft_memcmp(s1, s2, 0));

	s2[5] = 'x';
	if (memcmp(s1, s2, 20) == ft_memcmp(s1, s2, 20))
		printf("OK: expected %d, got %d.\n", memcmp(s1, s2, 20), ft_memcmp(s1, s2, 20));
	else
		printf("Try again: expected %d, got %d.\n", memcmp(s1, s2, 20), ft_memcmp(s1, s2, 20));
	
	if (memcmp(s1, s2, 4) == ft_memcmp(s1, s2, 4))
		printf("OK: expected %d, got %d.\n", memcmp(s1, s2, 4), ft_memcmp(s1, s2, 4));
	else
		printf("Try again: expected %d, got %d.\n", memcmp(s1, s2, 4), ft_memcmp(s1, s2, 4));
	
	s2[5] = '#';
	if (memcmp(s1, s2, 20) == ft_memcmp(s1, s2, 20))
		printf("OK: expected %d, got %d.\n", memcmp(s1, s2, 20), ft_memcmp(s1, s2, 20));
	else
		printf("Try again: expected %d, got %d.\n", memcmp(s1, s2, 20), ft_memcmp(s1, s2, 20));

	strcpy(s2, "");
	if (memcmp(s1, s2, 20) == ft_memcmp(s1, s2, 20))
		printf("OK: expected %d, got %d.\n", memcmp(s1, s2, 20), ft_memcmp(s1, s2, 20));
	else
		printf("Try again: expected %d, got %d.\n", memcmp(s1, s2, 20), ft_memcmp(s1, s2, 20));

	strcpy(s2, "Just in time for doing a.");
	if (memcmp(s1, s2, 20) == ft_memcmp(s1, s2, 20))
		printf("OK: expected %d, got %d.\n", memcmp(s1, s2, 20), ft_memcmp(s1, s2, 20));
	else
		printf("Try again: expected %d, got %d.\n", memcmp(s1, s2, 20), ft_memcmp(s1, s2, 20));
}
/*
void	test_strnstr(void)
{
	char	haystack[25] = "Hello the world exists.";
	char	needle[25] = "the world";

	if (strnstr(haystack, needle, 20) == ft_strnstr(haystack, needle, 20))
		printf("OK: expected \"%s\", got \"%s\".\n", strnstr(haystack, needle, 20), ft_strnstr(haystack, needle, 20));
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", strnstr(haystack, needle, 20), ft_strnstr(haystack, needle, 20));
	
}
*/
void	test_atoi(void)
{
	printf("\n\n=========== TESTING ATOI ============\n\n");

	if (atoi("145") == ft_atoi("145"))
		printf("OK: expected %d, got %d.\n", atoi("145"), ft_atoi("145"));
	else
		printf("Try again: expected %d, got %d.\n", atoi("145"), ft_atoi("145"));

	if (atoi("-52") == ft_atoi("-52"))
		printf("OK: expected %d, got %d.\n", atoi("-52"), ft_atoi("-52"));
	else
		printf("Try again: expected %d, got %d.\n", atoi("-52"), ft_atoi("-52"));

	if (atoi("+200") == ft_atoi("+200"))
		printf("OK: expected %d, got %d.\n", atoi("+200"), ft_atoi("+200"));
	else
		printf("Try again: expected %d, got %d.\n", atoi("+200"), ft_atoi("+200"));
	
	if (atoi("   		1") == ft_atoi("   		1"))
		printf("OK: expected %d, got %d.\n", atoi("   		1"), ft_atoi("   		1"));
	else
		printf("Try again: expected %d, got %d.\n", atoi("   		1"), ft_atoi("   		1"));
	
	if (atoi("abc") == ft_atoi("abc"))
		printf("OK: expected %d, got %d.\n", atoi("abc"), ft_atoi("abc"));
	else
		printf("Try again: expected %d, got %d.\n", atoi("abc"), ft_atoi("abc"));

	if (atoi("  14n5") == ft_atoi("  14n5"))
		printf("OK: expected %d, got %d.\n", atoi("  14n5"), ft_atoi("  14n5"));
	else
		printf("Try again: expected %d, got %d.\n", atoi("  14n5"), ft_atoi("  14n5"));

	if (atoi("-2147483648") == ft_atoi("-2147483648"))
		printf("OK: expected %d, got %d.\n", atoi("-2147483648"), ft_atoi("-2147483648"));
	else
		printf("Try again: expected %d, got %d.\n", atoi("-2147483648"), ft_atoi("-2147483648"));


	if (atoi("2147483700") == ft_atoi("2147483700"))
		printf("OK: expected %d, got %d.\n", atoi("2147483700"), ft_atoi("2147483700"));
	else
		printf("Try again: expected %d, got %d.\n", atoi("2147483700"), ft_atoi("2147483700"));
}

void	test_strdup(void)
{
	printf("\n\n=========== TESTING STRDUP ============\n\n");
	
	char	tocpy[22] = "Duplication in action.";
	char	*orcpy;
	char	*ftcpy;

	orcpy = strdup(tocpy);
	ftcpy = ft_strdup(tocpy);
	if (!strcmp(orcpy, ftcpy))
		printf("OK: expected \"%s\", got \"%s\".\n", orcpy, ftcpy);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", orcpy, ftcpy);
	free(orcpy);
	free(ftcpy);

	
	orcpy = strdup(tocpy + 18);
	ftcpy = ft_strdup(tocpy + 18);
	if (!strcmp(orcpy, ftcpy))
		printf("OK: expected \"%s\", got \"%s\".\n", orcpy, ftcpy);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", orcpy, ftcpy);
	free(orcpy);
	free(ftcpy);

	orcpy = strdup("Hello");
	ftcpy = ft_strdup("Hello");
	if (!strcmp(orcpy, ftcpy))
		printf("OK: expected \"%s\", got \"%s\".\n", orcpy, ftcpy);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", orcpy, ftcpy);
	free(orcpy);
	free(ftcpy);


	orcpy = strdup("");
	ftcpy = ft_strdup("");
	if (!strcmp(orcpy, ftcpy))
		printf("OK: expected \"%s\", got \"%s\".\n", orcpy, ftcpy);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", orcpy, ftcpy);
	free(orcpy);
	free(ftcpy);
}

void	test_substr(void)
{
	printf("\n\n=========== TESTING SUBSTR ============\n\n");
	
	char	srcstr[20] = "Hello World!";
	char	*substr;

	substr = ft_substr(srcstr, 6, 20);
	if (!strcmp(srcstr + 6, substr))
		printf("OK: expected \"%s\", got \"%s\".\n", srcstr + 6, substr);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", srcstr + 6, substr);
	free(substr);


	substr = ft_substr(srcstr, 0, 20);
	if (!strcmp(srcstr, substr))
		printf("OK: expected \"%s\", got \"%s\".\n", srcstr, substr);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", srcstr, substr);
	free(substr);

	substr = ft_substr(srcstr, 7, 1);
	if (substr[0] == srcstr[7] && substr[1] == '\0')
		printf("OK: expected \"%c\", got \"%s\".\n", srcstr[7], substr);
	else
		printf("Try again: expected \"%c\", got \"%s\".\n", srcstr[7], substr);
	free(substr);


	substr = ft_substr("", 7, 5);
	if (!strcmp(substr, ""))
		printf("OK: expected \"%s\", got \"%s\".\n", "", substr);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "", substr);
	free(substr);

	substr = ft_substr("Hello", 2, 0);
	if (!strcmp(substr, ""))
		printf("OK: expected \"%s\", got \"%s\".\n", "", substr);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "", substr);
	free(substr);

	substr = ft_substr("Hello", 15, 5);
	if (!strcmp(substr, ""))
		printf("OK: expected \"%s\", got \"%s\".\n", "", substr);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "", substr);
	free(substr);

	substr = ft_substr("", 0, 5);
	if (!strcmp(substr, ""))
		printf("OK: expected \"%s\", got \"%s\".\n", "", substr);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "", substr);
	free(substr);
}

void	test_strjoin(void)
{
	printf("\n\n=========== TESTING STRJOIN ============\n\n");


	char	join0[100] = "";
	char	join1[100] = "Coucou!";
	char	join2[100] = " comment va la vie?";
	char	*res0 = NULL;
	char	*res1;
	res1 = ft_strjoin(join1, join2);
	res0 = strcat(join1, join2);
	if (!strcmp(res0, res1))
		printf("OK: expected \"%s\", got \"%s\".\n", res0, res1);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", res0, res1);
	free(res1);

	strcpy(join1, "Coucou!");
	res1 = ft_strjoin(join0, join1);
	res0 = strcat(join0, join1);
	if (!strcmp(res0, res1))
		printf("OK: expected \"%s\", got \"%s\".\n", res0, res1);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", res0, res1);
	free(res1);

	strcpy(join1, " comment va la vie?");
	strcpy(join2, "");
	res1 = ft_strjoin(join1, join2);
	res0 = strcat(join1, join2);
	if (!strcmp(res0, res1))
		printf("OK: expected \"%s\", got \"%s\".\n", res0, res1);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", res0, res1);
	free(res1);
	
	strcpy(join0, "");
	strcpy(join1, "");
	res1 = ft_strjoin(join0, join1);
	res0 = strcat(join0, join1);
	if (!strcmp(res0, res1))
		printf("OK: expected \"%s\", got \"%s\".\n", res0, res1);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", res0, res1);
	free(res1);
}

void	test_strtrim(void)
{
	printf("\n\n=========== TESTING STRTRIM ============\n\n");

	char	*trimmed;

	trimmed = ft_strtrim("/......../.hello./////...", "./");
	if (!strcmp("hello", trimmed))
		printf("OK: expected \"%s\", got \"%s\".\n", "hello", trimmed);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "hello", trimmed);
	free(trimmed);

	trimmed = ft_strtrim("", "abcd");
	if (!strcmp("", trimmed))
		printf("OK: expected \"%s\", got \"%s\".\n", "", trimmed);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "", trimmed);
	free(trimmed);

	trimmed = ft_strtrim("hello", "");
	if (!strcmp("hello", trimmed))
		printf("OK: expected \"%s\", got \"%s\".\n", "hello", trimmed);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "hello", trimmed);
	free(trimmed);

	trimmed = ft_strtrim("hello", "l");
	if (!strcmp("hello", trimmed))
		printf("OK: expected \"%s\", got \"%s\".\n", "hello", trimmed);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "hello", trimmed);
	free(trimmed);

	trimmed = ft_strtrim("hello", "xyz");
	if (!strcmp("hello", trimmed))
		printf("OK: expected \"%s\", got \"%s\".\n", "hello", trimmed);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "hello", trimmed);
	free(trimmed);

	trimmed = ft_strtrim("llllllhellolllllll", "l");
	if (!strcmp("hello", trimmed))
		printf("OK: expected \"%s\", got \"%s\".\n", "hello", trimmed);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "hello", trimmed);
	free(trimmed);

	trimmed = ft_strtrim("llllllhellolllllll", "helo");
	if (!strcmp("", trimmed))
		printf("OK: expected \"%s\", got \"%s\".\n", "", trimmed);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "", trimmed);
	free(trimmed);

	trimmed = ft_strtrim("llllllhello/hilllllll", "helo");
	if (!strcmp("/hi", trimmed))
		printf("OK: expected \"%s\", got \"%s\".\n", "/hi", trimmed);
	else
		printf("Try again: expected \"%s\", got \"%s\".\n", "/hi", trimmed);
	free(trimmed);
}

void	test_split(void)
{
	printf("\n\n=========== TESTING SPLIT ============\n\n");
	char	**tab;
	unsigned int	i;
	char	s0[50] = "split         ";
	char	s1[50] = "      split       this for   me  !";
	char	s2[50] = "split       this for   me  !";
	char	s3[50] = "      split       this for   me  !       ";


	printf("---------- TEST 1 ----------\n");
	i = 0;
	tab = ft_split(s0, ' ');
	printf("Test string : \"%s\".\n\n", s0);
	if (!tab[0])
		printf("Try again.\n");
	while (tab[i])
	{
		printf("Tab [%d] : \"%s\".\n", i, tab[i]);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);

	printf("\n---------- TEST 2 ----------\n");
	i = 0;
	tab = ft_split(s1, ' ');
	printf("Test string : \"%s\".\n\n", s1);
	if (!tab[0])
		printf("Try again.\n");
	while (tab[i])
	{
		printf("Tab [%d] : \"%s\".\n", i, tab[i]);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);

	printf("\n---------- TEST 3 ----------\n");
	i = 0;
	tab = ft_split(s2, ' ');
	printf("Test string : \"%s\".\n\n", s2);
	if (!tab[0])
		printf("Try again.\n");
	while (tab[i])
	{
		printf("Tab [%d] : \"%s\".\n", i, tab[i]);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);

	printf("\n---------- TEST 4 ----------\n");
	i = 0;
	tab = ft_split(s3, ' ');
	printf("Test string : \"%s\".\n\n", s3);
	if (!tab[0])
		printf("Try again.\n");
	while (tab[i])
	{
		printf("Tab [%d] : \"%s\".\n", i, tab[i]);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);

	printf("\n---------- TEST 5 ----------\n");
	i = 0;
	tab = ft_split("", ' ');
	printf("Test string : \"%s\".\n\n", "");
	if (!tab[0])
		printf("Ok: expected null, got %s.\n", tab[0]);
	while (tab[i])
	{
		printf("Tab [%d] : \"%s\".\n", i, tab[i]);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);

	printf("\n---------- TEST 6 ----------\n");
	i = 0;
	tab = ft_split("split", '\0');
	printf("Test string : \"%s\".\n\n", "split");
	if (!tab[0])
		printf("Try again.\n");
	while (tab[i])
	{
		printf("Tab [%d] : \"%s\".\n", i, tab[i]);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);

	printf("\n---------- TEST 7 ----------\n");
	i = 0;
	tab = ft_split("\0aa\0bbb", '\0');
	printf("Test string : \"%s\".\n\n", "\\0aa\\0bbb");
	if (!tab[0])
		printf("Ok: expected null, got %s.\n", tab[0]);
	while (tab[i])
	{
		printf("Tab [%d] : \"%s\".\n", i, tab[i]);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);

	printf("\n---------- TEST 8 ----------\n");
	i = 0;
	tab = ft_split("        ", ' ');
	printf("Test string : \"%s\".\n\n", "       ");
	if (!tab[0])
		printf("Ok: expected null, got %s.\n", tab[0]);
	while (tab[i])
	{
		printf("Tab [%d] : \"%s\".\n", i, tab[i]);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);

	printf("\n---------- TEST 9 ----------\n");
	i = 0;
	tab = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	printf("Test string : \"%s\".\n\n", "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse");
	if (!tab[0])
		printf("Try again.\n");
	while (tab[i])
	{
		printf("Tab [%d] : \"%s\".\n", i, tab[i]);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);

	printf("\n---------- TEST 10 ----------\n");
	i = 0;
	tab = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
	printf("Test string : \"%s\" split at 'i'.\n\n", "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.");
	if (!tab[0])
		printf("Try again.\n");
	while (tab[i])
	{
		printf("Tab [%d] : \"%s\".\n", i, tab[i]);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);

	printf("\n---------- TEST 11 ----------\n");
	i = 0;
	tab = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z');
	printf("Test string : \"%s\" split at 'z'.\n\n", "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.");
	if (!tab[0])
		printf("Try again.\n");
	while (tab[i])
	{
		printf("Tab [%d] : \"%s\".\n", i, tab[i]);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	test_itoa(void)
{
	printf("\n\n=========== TESTING ITOA ============\n\n");

	int	n;

	n = 0;
	if (!strcmp("0", ft_itoa(n)))
		printf("OK: expected \"%d\", got \"%s\".\n", n, ft_itoa(n));
	else
		printf("Try again: expected \"%d\", got \"%s\".\n", n, ft_itoa(n));

	n = 123456789;
	if (!strcmp("123456789", ft_itoa(n)))
		printf("OK: expected \"%d\", got \"%s\".\n", n, ft_itoa(n));
	else
		printf("Try again: expected \"%d\", got \"%s\".\n", n, ft_itoa(n));

	n = -42;
	if (!strcmp("-42", ft_itoa(n)))
		printf("OK: expected \"%d\", got \"%s\".\n", n, ft_itoa(n));
	else
		printf("Try again: expected \"%d\", got \"%s\".\n", n, ft_itoa(n));

	n = -2147483648;
	if (!strcmp("-2147483648", ft_itoa(n)))
		printf("OK: expected \"%d\", got \"%s\".\n", n, ft_itoa(n));
	else
		printf("Try again: expected \"%d\", got \"%s\".\n", n, ft_itoa(n));
}

char	test_strmapi_toupper(unsigned int i, char c)
{
	i--;
	return (ft_toupper(c));
}

char	test_strmapi_tolower(unsigned int i, char c)
{
	i--;
	return (ft_tolower(c));
}

void	test_strmapi(void)
{
	printf("\n\n=========== TESTING STRMAPI ============\n\n");

	printf("\"hello!\" : \"%s\"\n", ft_strmapi("HELLO!", test_strmapi_tolower));	
	printf("\"BOOYA!\" : \"%s\"\n", ft_strmapi("booya!", test_strmapi_toupper));	
}

void	test_striteri_print(unsigned int i, char *c)
{
	i--;
	write(1, c, 1);
}

void	test_striteri(void)
{
	printf("\n\n=========== TESTING STRITERI ============\n\n");

	ft_putstr("\"Hello!\" : \"");	
	ft_striteri("Hello!", test_striteri_print);
	ft_putstr("\"\n");
	ft_putstr("\"BOOYA!\" : \"");
	ft_striteri("BOOYA!", test_striteri_print);
	ft_putstr("\"\n");	
}

void	test_putchar_fd(void)
{
	printf("\n\n=========== TESTING PUTCHAR_FD ============\n\n");
	
	ft_putchar_fd('x', 1);
	int fd = open("testing/testputchar.txt", O_WRONLY | O_CREAT, 0777);
	ft_putchar_fd('x', fd);
	printf("\nCheck /testing/testputchar.txt file. Should have 'x'.\n");
	close(fd);
}

void	test_putstr_fd(void)
{
	printf("\n\n=========== TESTING PUTSTR_FD ============\n\n");
	
	ft_putstr_fd("Hello World!", 1);
	int fd0 = open("testing/testputstr.txt", O_WRONLY | O_CREAT, 0777);
	ft_putstr_fd("Hello World!", fd0);
	printf("\nCheck /testing/testputstr.txt file. Should have \"Hello World!\".\n");
	close(fd0);
}

void	test_putendl_fd(void)
{
	printf("\n\n=========== TESTING PUTENDL_FD ============\n\n");
	
	ft_putendl_fd("Hello World!", 1);
	int fd1 = open("testing/testputendl.txt", O_WRONLY | O_CREAT, 0777);
	ft_putendl_fd("Hello World!", fd1);
	printf("\nCheck /testing/testputendl.txt file. Should have \"Hello World!\".\n");
	close(fd1);
}

void	test_putnbr_fd(void)
{
	printf("\n\n=========== TESTING PUTNBR_FD ============\n\n");
	
	ft_putstr_fd("910\t\t: ", 1);
	ft_putnbr_fd(910, 1);
	ft_putstr_fd("\n123456789\t: ", 1);
	ft_putnbr_fd(123456789, 1);
	ft_putstr_fd("\n0\t\t: ", 1);
	ft_putnbr_fd(0, 1);
	ft_putstr_fd("\n-8453\t\t: ", 1);
	ft_putnbr_fd(-8453, 1);
	ft_putstr_fd("\n2003\t\t: ", 1);
	ft_putnbr_fd(+2003, 1);
	ft_putstr_fd("\n-2147483648\t: ", 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putstr_fd("\n", 1);
	int fd2 = open("testing/testputnbr.txt", O_WRONLY | O_CREAT, 0777);
	ft_putnbr_fd(910, fd2);
	printf("\nCheck /testing/testputnbr.txt file. Should have \"910\".\n");
	close(fd2);
}

/* Utility functions for list tests below */
void	ft_del(void *content)
{
	*(int*)content = 0;
}

void	*ft_m(void *content)
{
	void	*newcontent;

	newcontent = malloc(sizeof(int));
	*((int*)newcontent) = *((int*)content) + 10;
	return (newcontent);
}

void	ft_it(void *content)
{
	printf("%i ", *((int*)content));
}

void	test_list_functions(void)
{
	int		tab[20];
	int		i;
	t_list	*begin;

	*tab = 0;
	begin = ft_lstnew(tab);
	printf("\n=========== TESTING LSTNEW  ============\n\n");
	if (begin && !begin->next && begin->content && *((int*)begin->content) == 0)
		printf("OK\n");
	else
		printf("Try again.\n");

	printf("\n\n=========== TESTING LSTADD_FRONT  ============\n\n");
	i = 0;
	while (++i < 10)
	{
		tab[i] = i;
		ft_lstadd_front(&begin, ft_lstnew(tab + i));
	}
	t_list	*tmp = begin;
	printf("Should print numbers from 9 to 0.\n");
	while (tmp)
	{
		printf("%i ", *((int*)tmp->content));
		tmp = tmp->next;
	}

	printf("\n\n=========== TESTING LSTSIZE  ============\n\n");
	if (ft_lstsize(begin) == 10)
		printf("OK: expected %d, got %d.\n", 10, ft_lstsize(begin));
	else
		printf("Try again: expected %d, got %d.\n", 10, ft_lstsize(begin));

	printf("\n\n=========== TESTING LSTLAST  ============\n\n");
	if (*((int*)(ft_lstlast(begin)->content)) == 0)
		printf("OK: expected list->content to be %d, got %d.\n", 0, *((int*)(ft_lstlast(begin)->content)));
	else
		printf("Try again: expected list->content to be %d, got %d.\n", 0, *((int*)(ft_lstlast(begin)->content)));

	printf("\n\n=========== TESTING LSTADD_BACK  ============\n\n");
	i = 0;
	while (++i < 10)
	{
		tab[i + 10] = -i;
		ft_lstadd_back(&begin, ft_lstnew(tab + i + 10));
	}
	tmp = begin;
	printf("Should print numbers from 9 to -9 :\n");
	while (tmp)
	{
		printf("%i ", *((int*)tmp->content));
		tmp = tmp->next;
	}

	printf("\n\n=========== TESTING LSTDELONE  ============\n\n");
	tmp = begin->next;
	ft_lstdelone(begin, ft_del);
	begin = tmp;
	printf("Should print numbers from 8 to -9 :\n");
	while (tmp)
	{
		printf("%i ", *((int*)tmp->content));
		tmp = tmp->next;
	}

	printf("\n\n=========== TESTING LSTITER  ============\n\n");
	printf("Should print numbers from 8 to -9 :\n");
	ft_lstiter(begin, &ft_it);

	printf("\n\n=========== TESTING LSTMAP  ============\n\n");
	t_list		*map;
	map = ft_lstmap(begin, &ft_m, &ft_del);
	printf("Should print numbers from 18 to 1 :\n");
	while (map)
	{
		if (begin->content)
			printf("%i ", *((int*)(map->content)));
		map = map->next;
	}

	printf("\n\n=========== TESTING LSTCLEAR ============\n\n");
	ft_lstclear(&begin, &ft_del);
	tmp = begin;
	if (!tmp)
		printf("OK, list doesn't exist.");
	else
	{
		printf("Try again, list isn't null.");
		while (tmp)
		{
			printf("[%i] ", *((int*)tmp->content));
			tmp = tmp->next;
		}
	}
	printf("\n");
}

int	main(void)
{
/*	printf("\n\n===============================\n");
	printf(    "=========== PART 1 ============\n");
	printf(    "===============================\n");
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
	test_bzero();

	test_memmove();
	test_strlcpy();
	test_strlcat();
	test_toupper();
	test_tolower();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_memchr();
	test_memcmp();
	test_strnstr();
	test_atoi();

	printf("\n\n=========== TESTING CALLOC ============\n\n");
	printf("??? How to test ???\n");
	test_strdup();

	printf("\n\n===============================\n");
	printf(    "=========== PART 2 ============\n");
	printf(    "===============================\n");
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_striteri();
	test_putchar_fd();
	test_putstr_fd();
	test_putendl_fd();
	test_putnbr_fd();

*/	printf("\n\n===============================\n");
	printf(    "============ BONUS ============\n");
	printf(    "===============================\n");
	test_list_functions();
}
