/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:36:05 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/27 18:22:46 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
	_types[0] = (ScalarConverter::t_type){._stream = "char : "};
	_types[1] = (ScalarConverter::t_type){._stream = "int : "};
	_types[2] = (ScalarConverter::t_type){._stream = "float : "};
	_types[3] = (ScalarConverter::t_type){._stream = "double : "};
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
	*this = src;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& rhs ) {
	if ( this != &rhs ) {
		_types[0] = rhs._types[0];
		_types[1] = rhs._types[1];
		_types[2] = rhs._types[2];
		_types[3] = rhs._types[3];
	}
	return (*this);
}

void	ScalarConverter::convert(std::string str) {
	float	value = 0;
	char	s[3] = {};
	size_t	found = 0;
	int		scan = std::sscanf(str.c_str(), "%f%2s", &value, s);

	if (scan == 1 || (scan == 2 && s[0] == 'f' && s[1] == 0)) {
		if (s[0]) str.resize(str.size() - 1);
		if (trunc(value) - value) {
			_types[1]._autorized = IMPOSSIBLE;
		} else if (found = str.find_first_of("."), found != std::string::npos) {
			if (str.find_first_not_of('0', found + 1) != std::string::npos)
				_types[1]._autorized = IMPOSSIBLE;
		}
		_types[0]._autorized = (!_types[1]._autorized && std::isgraph(static_cast<int>(value)) ? 0 : UNDISPLAYABLE);
	} else {
		_types[0]._autorized = IMPOSSIBLE;
		_types[1]._autorized = IMPOSSIBLE;
		_types[2]._autorized = IMPOSSIBLE;
		_types[3]._autorized = IMPOSSIBLE;
	}
	_types[0].msg(static_cast<char>(value));
	_types[1].msg(static_cast<int>(value));
	(*_types[2].msg(static_cast<float>(value))) += (_types[2]._autorized ? "" : "f");
	_types[3].msg(static_cast<double>(value));
}

ScalarConverter::t_type	*ScalarConverter::get_type(void) const {
	return ((ScalarConverter::t_type *)_types);
}

std::ostream&    operator<<( std::ostream& out, const ScalarConverter& rhs ) {
	for (int i = 0; i < 4; i++)
		out << rhs.get_type()[i]._stream << std::endl;
	return out;
}
