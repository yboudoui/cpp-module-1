/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:16:07 by yboudoui          #+#    #+#             */
/*   Updated: 2023/08/13 17:51:04 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char *av[])
{
	std::stack<int>		number;
	std::stack<char>	operand;

	if (ac != 2) {
		std::cerr << "Error: wrong number of input. Expected 1 have " << toString(ac - 1) << std::endl;
		return (1);
	}

	try { std::cout <<  rpn(av[1]) << std::endl; }
	catch (std::exception &e) { std::cerr << e.what() << std::endl; }
	return (0);
}
