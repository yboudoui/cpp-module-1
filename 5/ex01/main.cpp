/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:46:38 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/05 09:59:16 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	Bureaucrat	john("John", 1);
	Bureaucrat	nooby("Kevin", 150);
	Bureaucrat	samantha("Samantha", 140);

	std::cout << john << std::endl;
	std::cout << nooby << std::endl;
	std::cout << samantha << std::endl;
	samantha = nooby;
	std::cout << nooby << std::endl;

	samantha++;
	std::cout << samantha << std::endl;

	++samantha;
	std::cout << samantha << std::endl;

	try {
		std::cout << ++john << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << --nooby << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		nooby += 9999;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout <<  nooby << std::endl;

	Form	contrat("contrat", 50, 42);
	try {
		Form	contratFail("contrat", -50, 42);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	nooby.signForm(contrat);
	nooby += 100;
	nooby.signForm(contrat);
	return (0);
}

