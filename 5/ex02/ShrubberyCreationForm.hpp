/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:54 by yboudoui          #+#    #+#             */
/*   Updated: 2023/07/05 11:05:32 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm(const std::string& name, int gradeSigning, int gradeExecution);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		std::string	getName(void) const;
		int			getGradeSigning(void) const;
		int			getGradeExecution(void) const;
		void		beSigned(const Bureaucrat& bureaucrat);
};

#endif
