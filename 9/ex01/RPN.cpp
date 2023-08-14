/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:45:55 by yboudoui          #+#    #+#             */
/*   Updated: 2023/08/14 17:39:03 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool	is_number(const std::string& s)
{
	return (!s.empty() && s.find_first_not_of("0123456789") == std::string::npos);
}

static bool	is_operand(const std::string& s)
{
	return (s.size() == 1 && s.find_first_not_of("+-*/") == std::string::npos);
}

int	rpn(std::string str)
{
	std::stack<int>		number;
	std::stack<char>	operand;

	if (str[str.size()] != ' ') { str += " "; }
	size_t pos = 0;
	std::string token;
	while ((pos = str.find(" ")) != std::string::npos) {
		token = str.substr(0, pos);
		str.erase(0, pos + 1);
		if (is_number(token)) { number.push(std::atoi(token.c_str())); }
		else if (is_operand(token)) { operand.push(token[0]); }
		else { throw std::runtime_error("Error"); }
		if (operand.size() >= 1 && number.size() == 2) {
			int	a = number.top(); number.pop();
			int	b = number.top(); number.pop();
			switch (operand.top()) {
				case '+':
					number.push(b + a);
					break ;
				case '-':
					number.push(b - a);
					break ;
				case '*':
					number.push(b * a);
					break ;
				case '/':
					if (a == 0) { std::cerr << "Error: divide by zero" << std::endl; return (1); }
					number.push(b / a);
					break ;
			}
			operand.pop();
		}
	}
	if (number.size() == 1 && operand.size() == 0)
		return (number.top());
	return (0);
}
