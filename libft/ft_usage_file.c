/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:35:09 by ashari            #+#    #+#             */
/*   Updated: 2019/04/22 12:07:36 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_usage_file(void)
{
	write(1, "\n\t\t\tOH NO! YOU MADE A MISTAKE!", 30);
	write(1, "\n", 1);
	write(1, "\t\t\t\tJUST READ ME.\n", 18);
	write(1, "\n", 1);
	write(1, "\t\tYou must give ONLY 1 file, as a parameter.\n", 45);
	write(1, "\t\tFile should contain a list of Tetriminos to assemble.\n", 56);
	write(1, "\t\tThis file has a very specific format : every Tetrimino", 56);
	write(1, "\n", 1);
	write(1, "\t\tmust exactly fit in a 4 by 4 chars square\n", 44);
	write(1, "\t\tand all Tetrimino are separated by an newline each.", 53);
	write(1, "\n", 1);
	write(1, "\n\t\t\t./fillit\ttest_file_XX\n\n", 27);
	write(1, "\t\tA few examples of valid descriptions of Tetriminos:\n", 54);
	write(1, "\n", 1);
	write(1, "\t\t.... .... #### .... .##. .... .#.. .... ....\n", 47);
	write(1, "\t\t..## .... .... .... ..## .##. ###. ##.. .##.\n", 47);
	write(1, "\t\t..#. ..## .... ##.. .... ##.. .... #... ..#.\n", 47);
	write(1, "\t\t..#. ..## .... ##.. .... .... .... #... ..#.\n", 47);
	write(1, "\n", 1);
	write(1, "\t\tNOW YOU CAN TEST OUR PROGRAM WITH 26 TETRAMINO!", 49);
	write(1, "\n", 1);
	write(1, "\t\t\t\tGOOD LUCK!\n", 15);
	return (0);
}
