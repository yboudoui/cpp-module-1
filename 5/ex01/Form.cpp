/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:05:09 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/13 10:01:52 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Form.cpp

#include "Form.hpp"

Form::Form(const std::string& name, int gradeSigning, int gradeExecution) :
_signed(false),
_name(name),
_gradeRequiredSigning(gradeSigning),
_gradeRequiredExecution(gradeExecution) {
	if (_gradeRequiredSigning < 1 || _gradeRequiredExecution < 1)
		throw Form::GradeTooHighException();
	if (_gradeRequiredSigning > 150 || _gradeRequiredExecution > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form constructor assignment called" << std::endl;
}

Form::Form(const Form& other) :
_signed(other._signed),
_name(other._name),
_gradeRequiredSigning(other._gradeRequiredSigning),
_gradeRequiredExecution(other._gradeRequiredExecution) {
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
	os << form.getName()
	<< " bureaucrat signe grade " << form.getGradeSigning()
	<< " execution grade " << form.getGradeExecution();
	return (os);
}
