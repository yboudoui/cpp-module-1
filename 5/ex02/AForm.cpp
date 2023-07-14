/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:05:09 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/13 10:02:40 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// AForm.cpp

#include "AForm.hpp"

AForm::AForm(const std::string& name, int gradeSigning, int gradeExecution) :
_signed(false),
_name(name),
_gradeRequiredSigning(gradeSigning),
_gradeRequiredExecution(gradeExecution) {
	if (_gradeRequiredSigning < 1 || _gradeRequiredExecution < 1)
		throw AForm::GradeTooHighException();
	if (_gradeRequiredSigning > 150 || _gradeRequiredExecution > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm constructor assignment called" << std::endl;
}

AForm::AForm(const AForm& other) :
_signed(other._signed),
_name(other._name),
_gradeRequiredSigning(other._gradeRequiredSigning),
_gradeRequiredExecution(other._gradeRequiredExecution) {
	std::cout << "AForm Copy constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

AForm&	AForm::operator=(const AForm& other) {
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

//Methode

std::string	AForm::getName(void) const {
	return (_name);
}

int	AForm::getGradeSigning(void) const {
	return (_gradeRequiredSigning);
}

int	AForm::getGradeExecution(void) const {
	return (_gradeRequiredExecution);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeRequiredSigning)
		throw AForm::GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << form.getName()
	<< " bureaucrat signe grade " << form.getGradeSigning()
	<< " execution grade " << form.getGradeExecution();
	return (os);
}
