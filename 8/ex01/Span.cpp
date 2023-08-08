/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:42:19 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/31 15:01:05 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span(unsigned int N) : maxCapacity(N) {}

void	Span::addNumber(int number) {
	if (numbers.size() >= maxCapacity) {
		throw std::runtime_error("Span is already full. Cannot add more numbers.");
	}
	numbers.push_back(number);
}

int	Span::shortestSpan() const {
	if (numbers.size() < 2) {
		throw std::runtime_error("Not enough numbers to find a span.");
	}

	std::vector<int> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int shortest = std::abs(sortedNumbers[1] - sortedNumbers[0]);
	for (size_t i = 2; i < sortedNumbers.size(); i++) {
		int span = std::abs(sortedNumbers[i] - sortedNumbers[i - 1]);
		shortest = (span < shortest) ? span : shortest;
	}
	return (shortest);
}

int	Span::longestSpan() const {
	if (numbers.size() < 2) {
	    throw std::runtime_error("Not enough numbers to find a span.");
	}
	std::vector<int> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	return (std::abs(sortedNumbers.back() - sortedNumbers.front()));
}

void	Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	for (; start != end; start++) { addNumber(*start); }
}
