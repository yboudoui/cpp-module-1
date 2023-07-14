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
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

	PresidentialPardonForm	macaron("macaron");
	RobotomyRequestForm		cat("cat");
	ShrubberyCreationForm	lolipop("lolipop");

	nooby.signForm(macaron);
	nooby += 100;
	nooby.signForm(cat);

	std::cout << std::endl;
	std::cout << std::endl;
	try {
        Bureaucrat bureaucrat("ash", 2); // error with 200
        ShrubberyCreationForm form1("Shrubbery");
        RobotomyRequestForm form2("Robotomy");
        PresidentialPardonForm form3("President");

        std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
        bureaucrat.signForm(form1);
        bureaucrat.executeForm(form1);
        std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
        bureaucrat.signForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
        bureaucrat.signForm(form3);
        bureaucrat.executeForm(form3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	return (0);
}

