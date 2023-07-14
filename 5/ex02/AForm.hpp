/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <yboudoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:05:33 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/13 09:55:45 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// AForm.hpp

#ifndef AFORM_HPP
#define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:
		bool				_signed;
		const std::string	_name;
		const int			_gradeRequiredSigning;
		const int			_gradeRequiredExecution;

	public:
		AForm(const AForm& other);
		AForm(const std::string& name, int gradeSigning, int gradeExecution);
		AForm& operator=(const AForm& other);
		virtual ~AForm() = 0;

		std::string			getName(void) const;
		int					getGradeSigning(void) const;
		int					getGradeExecution(void) const;
		void				beSigned(const Bureaucrat& bureaucrat);
		virtual void		execute( const Bureaucrat& executor ) const = 0;

		// Exception
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Form Grade too high"; }
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Form Grade too low"; }
		};
	    class NotSignedException : public std::exception {
    	    public:
        	    virtual const char* what() const throw() { return "Form not signed"; }
    	};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
#endif

