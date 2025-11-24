/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:43:18 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/26 13:39:56 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void ):
		_name( "John Doe" ),
		_signed( 0 ),
		_req_sign( 75 ),
		_req_exec( 75 )
		{}

AForm::AForm( std::string name, int req_sign, int req_exec ):
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

AForm::AForm( const AForm& other ):
				_name( other.getName() ),
				_signed ( other.getSigned() ),
				_req_sign( other.getReqSign() ),
				_req_exec( other.getReqExec() )
				{}

AForm::~AForm( void ){}

AForm&	AForm::operator=( const AForm& other )
{
	_signed = other.getSigned();
	return ( *this );
}

std::string	AForm::getName( void ) const
{
	return ( this->_name );
}

bool	AForm::getSigned( void ) const
{
	return ( this->_signed );
}

int	AForm::getReqSign( void ) const
{
	return ( this->_req_sign );
}

int	AForm::getReqExec( void ) const
{
	return ( this->_req_exec );
}

void	AForm::beSigned( Bureaucrat& bureaucrat )
{
	if ( bureaucrat.getGrade() > this->getReqSign() )
		throw AForm::GradeTooLowException();
	_signed = 1;
}

void	AForm::checkExec( Bureaucrat const & executor ) const
{
	if ( executor.getGrade() > this->getReqExec() )
	{	
		std::cout << executor.getName() << " could not execute " <<
			this->getName() << ".\n";
		throw GradeTooLowException();
	}
	if ( !this->getSigned() )
		throw UnsignedFormException();
	std::cout << executor.getName() << " executed " << this->getName() << ".\n";
}

std::ostream&	operator<<( std::ostream& output, const AForm& form )
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

const char* AForm::GradeTooHighException::what() const throw()
{
	return ( "Grade is too high." );
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ( "Grade is too low." );
}

const char* AForm::UnsignedFormException::what() const throw()
{
	return ( "Can't exexcute unsigned form." );
}
