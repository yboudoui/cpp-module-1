/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:39:10 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/13 09:42:06 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Bureaucrat.cpp

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
name(name),
grade(grade) {
	std::cout << "Bureaucrat constructor assignment called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
name(other.name),
grade(other.grade) {
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Bureaucrat Copy assignment operator called. " << other.name << " to " << name << std::endl;
	if (this != &other)
		this->setGrade(other.grade);
	return (*this);
}

//Methode

void	Bureaucrat::executeForm(AForm const & form) {
	try {
    	form.execute( *this );
		std::cout << name << " executed " << form.getName() << std::endl;
    } catch ( std::exception& e ) {
        std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

void	Bureaucrat::setGrade(int newGrade) {
	if (newGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (newGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = newGrade;
	std::cout << getName() << " have a new grade! " << grade << std::endl;
}

void	Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned( *this );
		std::cout << *this << " signed " << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << name << " coulnd't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::string	Bureaucrat::getName(void) const {
	return (name);
}

int	Bureaucrat::getGrade(void) const {
	return (grade);
}

// Arithmetic

Bureaucrat& Bureaucrat::operator+=(int promotion) {
	this->setGrade(this->grade - promotion);
	return (*this);
}

Bureaucrat& Bureaucrat::operator-=(int promotion) {
	this->setGrade(this->grade + promotion);
	return (*this);
}

Bureaucrat Bureaucrat::operator+(const int promotion) const {
	Bureaucrat	result(*this);
	result.setGrade(result.grade - promotion);
	return result;
}

Bureaucrat Bureaucrat::operator-(const int promotion) const {
	Bureaucrat	result(*this);
	result.setGrade(result.grade + promotion);
	return result;
}

// Increment and decrement operators

Bureaucrat& Bureaucrat::operator++() {
	this->setGrade(this->grade - 1);
	return (*this);
}

Bureaucrat Bureaucrat::operator++(int) {
	Bureaucrat temp(*this);
	temp.setGrade(temp.grade - 1);
	return temp;
}

Bureaucrat& Bureaucrat::operator--() {
	this->setGrade(this->grade + 1);
	return (*this);
}

Bureaucrat Bureaucrat::operator--(int) {
	Bureaucrat temp(*this);
	temp.setGrade(temp.grade + 1);
	return (temp);
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
