/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:03:17 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/31 14:32:06 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main(void) {
	int	searchValue;
	int	arr[] = {10, 20, 30, 40, 50};

	std::vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]));
	searchValue = 30;
	try {
		std::vector<int>::iterator result = easyfind(vec, searchValue);
		std::cout << "Value " << *result << " found in the vector" << std::endl;
	} catch (const std::exception& e) { std::cout << e.what() << std::endl; }
	searchValue = 3;
	try {
		std::vector<int>::iterator result = easyfind(vec, searchValue);
		std::cout << "Value " << *result << " found in the vector" << std::endl;
	} catch (const std::exception& e) { std::cout << e.what() << std::endl; }


	std::list<int> myList (arr, arr + sizeof(arr) / sizeof(arr[0]));
	searchValue = 40;
	try {
		std::list<int>::iterator result = easyfind(myList, searchValue);
		std::cout << "Value " << *result << " found in the list" << std::endl;
	} catch (const std::exception& e) { std::cout << e.what() << std::endl; }
	searchValue = 42;
	try {
		std::list<int>::iterator result = easyfind(myList, searchValue);
		std::cout << "Value " << *result << " found in the list" << std::endl;
	} catch (const std::exception& e) { std::cout << e.what() << std::endl; }

	return (0);
}

