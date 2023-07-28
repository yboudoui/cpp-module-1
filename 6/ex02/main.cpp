/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:17:05 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/28 09:31:51 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Classes.hpp"

Base*	generate(void) {
	switch (std::rand() % 3) {
		case 0:
			return (new A);
		case 1:
			return (new B);
		default:
			return (new C);
	};
}

void    identify( Base* p ) {
	if ( dynamic_cast< A* >( p ) )
		std::cout << "A" << std::endl;
	else if ( dynamic_cast< B* >( p ) )
		std::cout << "B" << std::endl;
	else if ( dynamic_cast< C* >( p ) )
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown" << std::endl;
}

void	identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	} catch(const std::exception& e) {}
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
	} catch(const std::exception& e) {}
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
	} catch(const std::exception& e) {}
}

int	main(void)
{
	std::srand(std::time(NULL));

	Base*	a = generate();
	Base*	b = generate();
	Base*	c = generate();
	Base*	d = generate();

	std::cout << "a* = "; identify(a);
	std::cout << "a& = "; identify(*a);
	std::cout << std::endl;

	std::cout << "b* = "; identify(b);
	std::cout << "b& = "; identify(*b);
	std::cout << std::endl;

	std::cout << "c* = "; identify(c);
	std::cout << "c& = "; identify(*c);
	std::cout << std::endl;

	std::cout << "d* = "; identify(d);
	std::cout << "d& = "; identify(*d);
	std::cout << std::endl;

	delete a;
	delete b;
	delete c;
	delete d;

	return (0);
}
