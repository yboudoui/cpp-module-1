/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:05:09 by yboudoui          #+#    #+#             */
/*   Updated: 2023/06/18 20:38:20 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Form.cpp

#include "Form.hpp"

Form::Form(const std::string& name, int gradeSigning, int gradeExecution) : _name(name), _signed(false) {
	this->setGradeSigning(gradeSigning);
	this->setGradeExecution(gradeExecution);
	std::cout << "Form constructor assignment called" << std::endl;
}

Form::Form(const Form& other) : _name(other._name),  _signed(other._signed) {
	this->setGradeSigning(other._gradeRequiredSigning);
	this->setGradeExecution(other._gradeRequiredExecution);
	std::cout << "Form Copy constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

Form&	Form::operator=(const Form& other) {
	std::cout << "Form Copy assignment operator called. " << other._name << " to " << _name << std::endl;
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

//Methode

void	Form::setGradeSigning(int newGrade) {
	if (newGrade < 1)
		throw Form::GradeTooHighException();
	if (newGrade > 150)
		throw Form::GradeTooLowException();
	this->_gradeRequiredSigning = newGrade;
}

void	Form::setGradeExecution(int newGrade) {
	if (newGrade < 1)
		throw Form::GradeTooHighException();
	if (newGrade > 150)
		throw Form::GradeTooLowException();
	this->_gradeRequiredExecution = newGrade;
}

std::string	Form::getName(void) const {
	return (_name);
}

int	Form::getGradeSigning(void) const {
	return (_gradeRequiredSigning);
}

int	Form::getGradeExecution(void) const {
	return (_gradeRequiredExecution);
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeRequiredSigning)
		throw Form::GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << form.getName() << ", bureaucrat grade " << form.getGrade();
	return (os);
}
