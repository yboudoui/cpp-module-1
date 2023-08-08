/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:41:12 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/31 15:03:13 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <vector>

class Span
{
	private:
		unsigned int maxCapacity;
		std::vector<int> numbers;

	public:
		Span(unsigned int N);

		void	addNumber(int number);
		int		shortestSpan() const;
		int		longestSpan() const;
		void	addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);
};

#endif

