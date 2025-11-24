/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:43:18 by vcaratti          #+#    #+#             */
/*   Updated: 2025/10/27 12:50:52 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ):
				AForm( "PresidentialPardonForm", _req_sign_ppf, _req_exec_ppf ),
				_target( "Average Joe's house" )
				{}
PresidentialPardonForm::PresidentialPardonForm( std::string target ):
				AForm( "PresidentialPardonForm", _req_sign_ppf, _req_exec_ppf ),
				_target( target )
				{}
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ):
				AForm( "PresidentialPardonForm", _req_sign_ppf, _req_exec_ppf ),
				_target( other.getTarget() )
				{}

PresidentialPardonForm::~PresidentialPardonForm( void ){}


PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& other )
{
	_target = other.getTarget();
	return ( *this );
}

std::string PresidentialPardonForm::getTarget( void ) const
{
	return ( this->_target );
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	this->checkExec( executor );
	std::cout << this->getTarget() << " has successfully been pardonned by Zaphod Beeblebrox.\n";
}
