/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:16:06 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/28 10:25:25 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void	print_int(int val) {
	std::cout << "int : " <<val << std::endl;
}

void	print_str(std::string val) {
	std::cout << "str : " << val << std::endl;
}

int	main(void) {
	int			int_array[] = {0,1,2,3,4,5,6,7,8,9};
	std::string	str_array[] = {"0","1","2","3","4","5","6","7","8","9"};

	iter(int_array, 10, print_int);
	std::cout << std::endl;
	iter(str_array, 10, print_str);
	return (0);
}
