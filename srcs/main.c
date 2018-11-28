/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:56:28 by erli              #+#    #+#             */
/*   Updated: 2018/11/28 14:29:05 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int		main(void)
{
	char	*format_str;
	int		prec;
	int		width;
	int		**tab;
	char	***matstr;
	int		ret;
	double	df;

	if (!(tab = (int **)malloc(sizeof(int *) * 4)))
		return (0);
	if (!(tab[0] = (int *)malloc(sizeof(int) * 4)))
		return (0);
	if (!(tab[1] = (int *)malloc(sizeof(int) * 4)))
		return (0);
	if (!(tab[2] = (int *)malloc(sizeof(int) * 4)))
		return (0);
	if (!(tab[3] = (int *)malloc(sizeof(int) * 4)))
		return (0);
	tab[0][0] = 43;
	tab[0][1] = 123;
	tab[0][2] = 4325;
	tab[0][3] = 23;
	tab[1][0] = 132;
	tab[1][1] = 10;
	tab[1][2] = -34;
	tab[1][3] = 1;
	tab[2][0] = 2;
	tab[2][1] = 432;
	tab[2][2] = 2345;
	tab[2][3] = 43;
	tab[3][0] = -34;
	tab[3][1] = -123;
	tab[3][2] = 446;
	tab[3][3] = 4543;


	if (!(matstr = (char ***)malloc(sizeof(char **) * 4)))
		return (0);
	if (!(matstr[0] = (char **)malloc(sizeof(char *) * 4)))
		return (0);
	if (!(matstr[1] = (char **)malloc(sizeof(char *) * 4)))
		return (0);
	if (!(matstr[2] = (char **)malloc(sizeof(char *) * 4)))
		return (0);
	if (!(matstr[3] = (char **)malloc(sizeof(char *) * 4)))
		return (0);
	matstr[0][0] = "Je";
	matstr[0][1] = "suis";
	matstr[0][2] = "une";
	matstr[0][3] = "ligne";

	matstr[1][0] = "suis";
	matstr[1][1] = "fkldsfj";
	matstr[1][2] = "kjsdf";
	matstr[1][3] = "caca";

	matstr[2][0] = "une";
	matstr[2][1] = "prout";
	matstr[2][2] = "pipi";
	matstr[2][3] = "vomi";

	matstr[3][0] = "colonne";
	matstr[3][1] = "nuage";
	matstr[3][2] = "cotton";
	matstr[3][3] = "arc-en-ciel";




	printf("\n================ test de 'e' ================\n");
	format_str = "double f = %e\n";
	df = 3.1415;
	prec = 3;
	width = 0;
	printf("format_str = '%s'\nprecision = %d\nwidth = %d\n", format_str, prec, width);
	puts("\n\noriginal");
	ret = printf(format_str, df);
	printf("ret orig = %d\nft\n", ret);
	ret = ft_printf(format_str,  df);
	printf("ret   fd = %d\n", ret);




	printf("\n================ test de 'g' ================\n");
	format_str = "double f = %*.*g\n";
	df = 3.1415;
	prec = 3;
	width = 4;
	printf("format_str = '%s'\nprecision = %d\nwidth = %d\n", format_str, prec, width);
	puts("\n\noriginal");
	ret = printf(format_str, width, prec, df);
	printf("ret orig = %d\nft\n", ret);
	ret = ft_printf(format_str, width, prec, df);
	printf("ret   fd = %d\n", ret);





	printf("\n================ test de 'tableau' ================\n");
	format_str = "tab = %t*.*d\n";
	prec = 3;
	width = 5;
	ret = ft_printf(format_str, width, prec,  tab[0], 4);





	printf("\n================ test de 'matrice' ================\n");
	format_str = "mat = %m*s\n";
	prec = 2;
	width = 15;
	ret = ft_printf(format_str,  width, matstr, 4, 4);



	free(tab[0]);
	free(tab[1]);
	free(tab[2]);
	free(tab[3]);
	free(matstr[0]);
	free(matstr[1]);
	free(matstr[2]);
	free(matstr[3]);
	free(tab);
	free(matstr);
	
	return (0);
}
