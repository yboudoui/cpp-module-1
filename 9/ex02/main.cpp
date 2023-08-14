/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:16:07 by yboudoui          #+#    #+#             */
/*   Updated: 2023/08/13 21:55:15 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

// clear; valgrind -q ./PmergeMe $(shuf -i 0-100000 -n 5000 | tr '\n' ' ')

int	main(int ac, char *av[])
{
	std::vector<int>	v_n;
	std::list<int>		l_n;

	if (ac < 3) {
		std::cerr << "Error: wrong number of input. Expected at least 2 argument have " << toString(ac - 1) << std::endl;
		return (1);
	}

	av += 1;
	int	i;
	while (*av) {
		if(sscanf(*av, "%d", &i) != 1) {
			std::cerr << "Argument " << *av << " is not valide" << std::endl;
			return (1);
		}
		v_n.insert(v_n.end(), i);
		l_n.insert(l_n.end(), i);
		av += 1;
	}

	clock_t begin, end;
	double elapsed_secs_v, elapsed_secs_l;

	std::cout << "Before:" << std::setw(4); print_container(v_n);
	std::cout << std::endl;

	begin = std::clock();
	std::vector<int>	v = ford_johnson<int, std::vector>(v_n, 1);
	end = std::clock();
	elapsed_secs_v = double(end - begin) / CLOCKS_PER_SEC;

	begin = std::clock();
	std::list<int>		l = ford_johnson<int, std::list>(l_n, 1);
	end = std::clock();
	elapsed_secs_l = double(end - begin) / CLOCKS_PER_SEC;

	std::cout << "After:" << std::setw(4); print_container(v);
	std::cout << std::endl;

	std::cout << "Time to process a range of " << v.size() << " elements with std::[vector] : " << elapsed_secs_v << " ns" << std::endl;
	std::cout << "Time to process a range of " << l.size() << " elements with std::[list] : " << elapsed_secs_l << " ns" << std::endl;
	return (0);
}
