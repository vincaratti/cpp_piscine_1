/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:53:21 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/26 11:25:39 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <exception>
#include <iostream>

class AForm;

class Bureaucrat
{
public:

	Bureaucrat( void );
	Bureaucrat( std::string name, short int grade );
	Bureaucrat( const Bureaucrat& other );
	~Bureaucrat( void );

	Bureaucrat&	operator=( const Bureaucrat& other );

	std::string	getName( void ) const;
	int		getGrade( void ) const;

	void	incrementGrade( void );
	void	decrementGrade( void );

	void	signForm( AForm& form );
	void	executeForm( AForm const & form ) const;
	
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};

private:
	const std::string	_name;
	short int		_grade;

	void	setGrade( int grade );
};

std::ostream&	operator<<( std::ostream& output, const Bureaucrat& bureaucrat );

#endif
