/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:31:56 by yboudoui          #+#    #+#             */
/*   Updated: 2023/08/14 17:35:13 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	cmp_time(const struct tm& tm1, const struct tm& tm2) {
	if (tm1.tm_year != tm2.tm_year) { return tm1.tm_year - tm2.tm_year; }
	if (tm1.tm_mon != tm2.tm_mon) { return tm1.tm_mon - tm2.tm_mon; }
	return tm1.tm_mday - tm2.tm_mday;
}

t_data	*populateMap(void)
{
	int				line_number;
	std::string		line;
	tm				c_time;
	t_data			*output = new t_data;
	std::ifstream	file("data.csv");

	if (output == NULL)
		throw std::runtime_error("Unable to load data");
	line_number = 1;
	std::getline(file, line);
	while (std::getline(file, line)) {
		line_number += 1;
		std::string::size_type f = line.find_first_of(",");
		std::string date = line.substr(0, f);
		if (f > line.length()) {
			file.close();
			delete output;
			throw std::runtime_error("No value in data.csv:"+toString(line_number));
		}
		if (strptime(date.c_str(), "%Y-%m-%d", &c_time) == NULL) {
			file.close();
			delete output;
			throw std::runtime_error("Bad date in data.csv:"+toString(line_number));
		}
		(*output)[c_time] = std::atof(line.substr(f + 1).c_str());
	}
	file.close();
	return (output);
}

std::ostream& operator<<(std::ostream& os, const struct tm& t) {
	os << toString(t.tm_year + 1900);
	os << "-";
	os << std::setfill('0') << std::setw(2) << toString(t.tm_mon + 1);
	os << "-";
	os << std::setfill('0') << std::setw(2) << toString(t.tm_mday);
	return (os);
}

double	data_find_closest_value(t_data data, struct tm *key)
{
	t_data::const_iterator it = data.find((*key));

	if (cmp_time(*key, (struct tm)data.begin()->first) < 0) { return (0); }
	if (cmp_time(*key, (struct tm)data.end()->first) > 0) { return (0); }
	while (it == data.end()) {
		key->tm_hour -= 24;
		std::mktime(key);
		it = data.find(*key);
	}
	return (it->second);
}

