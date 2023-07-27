/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:27:27 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/15 14:19:26 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"



int main( int ac, char ** av )
{
	if (ac != 2) {
		std::cout << "Usage: ./convert number" << std::endl;
		return (1);
	}
	ScalarConverter c;
	c.convert(av[1]);
	std::cout << c;
	return (0);
}
