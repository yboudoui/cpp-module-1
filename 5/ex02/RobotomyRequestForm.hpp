/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:01:14 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/05 11:56:45 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm(const std::string& name, int gradeSigning, int gradeExecution);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		std::string	getName(void) const;
		int			getGradeSigning(void) const;
		int			getGradeExecution(void) const;
		void		beSigned(const Bureaucrat& bureaucrat);
};

#endif
