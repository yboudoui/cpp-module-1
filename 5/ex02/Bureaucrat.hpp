/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:38:50 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/05 09:22:41 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Bureaucrat.hpp

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;
		void				setGrade(int newGrade);

	public:
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		signForm(AForm& form);
		void		executeForm(AForm const & form);

		// Arithmetic operators
		Bureaucrat& operator+=(int promotion);
		Bureaucrat& operator-=(int promotion);
		Bureaucrat	operator+(const int promotion) const;
		Bureaucrat	operator-(const int promotion) const;

		// Increment and decrement operators
		Bureaucrat&	operator++();			// Pre-increment
		Bureaucrat	operator++(int);		// Post-increment
		Bureaucrat&	operator--();			// Pre-decrement
		Bureaucrat	operator--(int);		// Post-decrement

		// Exception
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade too high"; }
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade too low"; }
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
#endif

