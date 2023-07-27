/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:30:48 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/27 17:38:06 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <cstdio>
# include <iomanip>
# include <sstream>


class ScalarConverter {
	
		typedef enum s_autorized {
			UNDISPLAYABLE	=	(1 << 0),
			IMPOSSIBLE		=	(1 << 1),
		}	t_autorized;

		typedef struct s_type {
			int			_autorized;
			std::string	_stream;
			template <typename T> std::string *msg(const T & t) {
				std::ostringstream os;
				os << _stream;
				if (_autorized & UNDISPLAYABLE)
					os << "Non displayable";
				else if (_autorized & IMPOSSIBLE)
					os << "impossible";
				else
					os << std::fixed << std::setprecision(1) << t;
				_stream = os.str();
				return &_stream;
			}
		}	t_type;
	public:

		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter(void);

		void			convert(std::string str);
		t_type			*get_type(void) const;
		ScalarConverter& operator=(const ScalarConverter& rhs);
		
	private:
		t_type	_types[4];
	
};

std::ostream&    operator<<(std::ostream& out, const ScalarConverter& rhs);

#endif
