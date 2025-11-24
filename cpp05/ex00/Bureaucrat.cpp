/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:53:21 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/26 13:22:07 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ): _name( "John Doe" ), _grade( 75 ) {}

Bureaucrat::Bureaucrat( std::string name, short int grade ): _name( name )
{
	setGrade( grade );
}

Bureaucrat::Bureaucrat( const Bureaucrat& other )
{
	*this = other;
}

Bureaucrat::~Bureaucrat( void ){}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other )
{
	_grade = other.getGrade();
	return ( *this );
}

std::string	Bureaucrat::getName( void ) const
{
	return ( this->_name );
}

int		Bureaucrat::getGrade( void ) const
{
	return ( this->_grade );
}

void	Bureaucrat::setGrade( int grade )
{
	if ( grade < 1 )
		throw Bureaucrat::GradeTooHighException();
	if ( grade > 150 )
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

void	Bureaucrat::incrementGrade( void )
{
	setGrade( getGrade() - 1 );
}

void	Bureaucrat::decrementGrade( void )
{
	setGrade( getGrade() + 1 );
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ( "Grade is too high." );
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ( "Grade is too low." );
}

std::ostream&	operator<<( std::ostream& output, const Bureaucrat& bureaucrat )
{
	output << bureaucrat.getName();
	output << ", bureaucrat grade ";
	output << bureaucrat.getGrade();
	output << ".";
	return ( output );
}
