/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:35:38 by yboudoui          #+#    #+#             */
/*   Updated: 2023/08/14 17:33:46 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iomanip>
# include <sstream>
# include <string>
# include <map>
# include <fstream>
# include <iostream>
# include <ctime>
# include <cstdlib>
# include <limits>

template<typename T>
std::string toString(const T& value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

int	cmp_time(const struct tm& tm1, const struct tm& tm2);

struct CompareTM {
	bool operator()(const struct tm& tm1, const struct tm& tm2) const {
		if (tm1.tm_year != tm2.tm_year) { return tm1.tm_year < tm2.tm_year; }
		if (tm1.tm_mon != tm2.tm_mon) { return tm1.tm_mon < tm2.tm_mon; }
		return tm1.tm_mday < tm2.tm_mday;
	}
};

typedef std::map<struct tm, double, CompareTM>	t_data;

t_data	*populateMap(void);
std::ostream& operator<<(std::ostream& os, const struct tm& t);
double	data_find_closest_value(t_data data, struct tm *key);

#endif
