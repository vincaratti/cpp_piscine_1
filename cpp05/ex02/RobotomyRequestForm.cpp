/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:43:18 by vcaratti          #+#    #+#             */
/*   Updated: 2025/10/27 12:53:44 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ):
				AForm( "RobotomyRequestForm", _req_sign_rrf, _req_exec_rrf ),
				_target( "Average joe" )
				{}
RobotomyRequestForm::RobotomyRequestForm( std::string target ):
				AForm( "RobotomyRequestForm", _req_sign_rrf, _req_exec_rrf ),
				_target( target )
				{}
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ):
				AForm( "RobotomyRequestForm", _req_sign_rrf, _req_exec_rrf ),
				_target( other.getTarget() )
				{}

RobotomyRequestForm::~RobotomyRequestForm( void ){}


RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm& other )
{
	_target = other.getTarget();
	return ( *this );
}

std::string RobotomyRequestForm::getTarget( void ) const
{
	return ( this->_target );
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	this->checkExec( executor );
	std::cout << "RRRRROBOTOMY SOUNDZZZZZZ" << std::endl;
	std::srand(time(NULL));
	if ( std::rand() % 2 == 1 )
		std::cout << "Robotomy of " << this->getTarget() << " successfully completed.\n";
	else	
		std::cout << "Robotomy of " << this->getTarget() << " successfully failed.\n";
}
