/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:05:33 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/13 09:48:04 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Form.hpp

#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		bool				_signed;
		const std::string	_name;
		const int			_gradeRequiredSigning;
		const int			_gradeRequiredExecution;

	public:
		Form(const Form& other);
		Form(const std::string& name, int gradeSigning, int gradeExecution);
		Form& operator=(const Form& other);
		~Form();

		std::string	getName(void) const;
		int			getGradeSigning(void) const;
		int			getGradeExecution(void) const;
		void		beSigned(const Bureaucrat& bureaucrat);

		// Exception
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Form Grade too high"; }
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Form Grade too low"; }
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);
#endif

