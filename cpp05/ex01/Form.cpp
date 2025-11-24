/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:43:18 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/26 13:25:01 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ):
		_name( "John Doe" ),
		_signed( 0 ),
		_req_sign( 75 ),
		_req_exec( 75 )
		{}

Form::Form( std::string name, int req_sign, int req_exec ):
							_name( name ),
							_signed( 0 ),
							_req_sign( req_sign ),
							_req_exec( req_exec )
{
	if ( req_sign < 1 || req_exec < 1 )
		throw GradeTooHighException();
	if ( req_sign > 150 || req_exec > 150 )
		throw GradeTooLowException();
}

Form::Form( const Form& other ):
				_name( other.getName() ),
				_signed ( other.getSigned() ),
				_req_sign( other.getReqSign() ),
				_req_exec( other.getReqExec() )
{
	*this = other;
}

Form::~Form( void ){}

Form&	Form::operator=( const Form& other )
{
	_signed = other.getSigned();
	return ( *this );
}

std::string	Form::getName( void ) const
{
	return ( this->_name );
}

bool	Form::getSigned( void ) const
{
	return ( this->_signed );
}

int	Form::getReqSign( void ) const
{
	return ( this->_req_sign );
}

int	Form::getReqExec( void ) const
{
	return ( this->_req_exec );
}

void	Form::beSigned( Bureaucrat& bureaucrat )
{
	if ( bureaucrat.getGrade() > this->getReqSign() )
		throw Form::GradeTooLowException();
	_signed = 1;
}

std::ostream&	operator<<( std::ostream& output, const Form& form )
{
	output << "Form ";
	output << form.getName();
	output << ", signed: ";
	output << form.getSigned();
	output << ", required grade to sign: ";
	output << form.getReqSign();
	output << ", required grade to execute: ";
	output << form.getReqExec();
	output << ".";

	return ( output );
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ( "Grade is too high." );
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ( "Grade is too low." );
}
