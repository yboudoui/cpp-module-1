/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:47:41 by yboudoui          #+#    #+#             */
/*   Updated: 2023/08/08 11:28:24 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int main() {
	try {
		unsigned int	capacity = 10000;
		Span span(capacity);
		for (unsigned int i = 0; i < capacity - 15; ++i) { span.addNumber(i + 1); }

		int				arr[] = {11, 12, 13, 14, 15};
		std::vector<int> numbersToAdd (arr, arr + sizeof(arr) / sizeof(arr[0]));
		span.addRange(numbersToAdd.begin(), numbersToAdd.end());
		
		std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << span.longestSpan() << std::endl;
	} catch (const std::exception& e) { std::cout << "Error: " << e.what() << std::endl; }

	std::cout << std::endl;
	std::cout << std::endl;

	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) { std::cout << "Error: " << e.what() << std::endl; }
	return (0);
}

