/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:16:07 by yboudoui          #+#    #+#             */
/*   Updated: 2023/08/10 19:15:51 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>

template<typename T>
std::string toString(const T& value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

bool	is_number(const std::string& s)
{
	return (!s.empty() && s.find_first_not_of("0123456789") == std::string::npos);
}

bool	is_operand(const std::string& s)
{
	return (s.size() == 1 && s.find_first_not_of("+-*/") == std::string::npos);
}

int	main(int ac, char *av[])
{
	std::stack<int>		number;
	std::stack<char>	operand;

	if (ac != 2) {
		std::cerr << "Error: wrong number of input. Expected 1 have " << toString(ac - 1) << std::endl;
		return (1);
	}

	std::string str(av[1]);
	if (str[str.size()] != ' ') { str += " "; }
	size_t pos = 0;
	std::string token;
	while ((pos = str.find(" ")) != std::string::npos) {
		token = str.substr(0, pos);
		str.erase(0, pos + 1);
		if (is_number(token)) { number.push(std::atoi(token.c_str())); }
		else if (is_operand(token)) { operand.push(token[0]); }
		else { std::cerr << "Error" << std::endl; return (1); }
		if (operand.size() == 1 && number.size() == 2) {
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
		std::cout << number.top() << std::endl;
	else
		std::cout << "0" << std::endl;
	return (0);
}
