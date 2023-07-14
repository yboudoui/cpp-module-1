/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:00:24 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/13 10:18:52 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 72, 45), _target(target) {
	std::cout << "ShrubberyCreationForm constructor assignment called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (_signed == false)
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getGradeExecution()) {
        throw AForm::GradeTooLowException();
    }
    std::ofstream	file((_name + "_shrubbery").c_str());
    file << "this is not a tree." << std::endl;
    file.close();
}
