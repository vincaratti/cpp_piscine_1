/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:34:27 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/26 11:58:47 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
public:
	Intern( void );
	Intern( const Intern& other );
	~Intern( void );

	Intern&	operator=( const Intern& other );

	AForm*	makeForm( std::string formName, std::string formTarget );

	class FormInexistantException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif
