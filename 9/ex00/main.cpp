/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:16:07 by yboudoui          #+#    #+#             */
/*   Updated: 2023/08/14 17:35:49 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"



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
			double	db_price = data_find_closest_value(*data, &c_time);
			price = std::atof(line.substr(f + 1).c_str());
			if (price < 0.0)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (price > std::numeric_limits<int>::max())
				std::cerr << "Error: too large a number." << std::endl;
			else
				std::cout << c_time << " => " << price << " = " << std::fixed << std::setprecision(4) << (db_price * price) << std::endl;
		}
	}
	file.close();
	delete data;
	return (0);
}
