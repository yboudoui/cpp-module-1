/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:16:07 by yboudoui          #+#    #+#             */
/*   Updated: 2023/08/10 18:22:08 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <sstream>
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>

template<typename T>
std::string toString(const T& value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

std::ostream& operator<<(std::ostream& os, const struct tm& t) {
	os << toString(t.tm_year + 1900);
	os << "-";
	os << std::setfill('0') << std::setw(2) << toString(t.tm_mon + 1);
	os << "-";
	os << std::setfill('0') << std::setw(2) << toString(t.tm_mday);
	return (os);
}

struct CompareTM {
	bool operator()(const struct tm& tm1, const struct tm& tm2) const {
		if (tm1.tm_year != tm2.tm_year) { return tm1.tm_year < tm2.tm_year; }
		if (tm1.tm_mon != tm2.tm_mon) { return tm1.tm_mon < tm2.tm_mon; }
		return tm1.tm_mday < tm2.tm_mday;
	}
};

typedef std::map<struct tm, double, CompareTM>	t_data;

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

double	data_find_closest_value(t_data *data, struct tm *key)
{
	t_data::iterator it = data->find(*key);

	while (it == data->end()) {
		key->tm_hour -= 24;
		std::mktime(key);
		it = data->find(*key);
	}
	return (it->second);
}

int	main(int ac, char *av[])
{
	t_data	*data = NULL;
	std::ifstream	file;

	if (ac != 2) {
		std::cerr << "Error: wrong number of input. Expected 1 have " << toString(ac - 1) << std::endl;
		return (1);
	}
	try { data = populateMap(); }
	catch (const std::exception& e) {
		std::cerr << "Fatal error : " << e.what() << std::endl;
	}
	try { file.open(av[1]); }
	catch (const std::exception& e) {
		std::cerr << "Fatal error : " << e.what() << std::endl;
		delete data;
		return (1);
	}

	double			price = 0;
	std::string		line;
	tm				c_time = {};
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::string::size_type f = line.find_first_of("|");
		std::string date = line.substr(0, f);
		if (strptime(date.c_str(), "%Y-%m-%d", &c_time) == NULL) {
			std::cerr << "Error: bad input => " << date << std::endl;
		} else if (f > line.length()) {
			std::cerr << "Error: No value" << std::endl;
		} else {
			double	db_price = data_find_closest_value(data, &c_time);
			price = std::atof(line.substr(f + 1).c_str());
			if (price < 0.0)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (price > std::numeric_limits<int>::max())
				std::cerr << "Error: too large a number." << std::endl;
			else
				std::cout << c_time << " => " << price << " = " << (db_price * price) << std::endl;
		}
	}
	file.close();
	delete data;
	return (0);
}
