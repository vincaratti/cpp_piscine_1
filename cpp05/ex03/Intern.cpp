/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:34:27 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/26 12:16:51 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ){}

Intern::Intern( const Intern& other )
{
	( void ) other;
}

Intern::~Intern( void ){}

Intern&	Intern::operator=( const Intern& other )
{
	( void ) other;
	return ( *this );
}

AForm*	Intern::makeForm( std::string formName, std::string formTarget )
{
	AForm*	ret;
	AForm*	formTypes[3];

	ret = NULL;
	formTypes[0] = new ShrubberyCreationForm( formTarget );
	formTypes[1] = new RobotomyRequestForm( formTarget );
	formTypes[2] = new PresidentialPardonForm( formTarget );

	for ( int i = 0; i < 3; i++ )
	{
		if ( formName == formTypes[i]->getName() )
		{
			ret = formTypes[i];
			formTypes[i] = NULL;
		}
	}
	for ( int i = 0; i < 3; i++ )
		delete formTypes[i];
	if ( !ret )
		throw FormInexistantException();
	std::cout << "Intern creates " << ret->getName() << std::endl;
	return ( ret );
}

const char* Intern::FormInexistantException::what() const throw()
{
	return ( "Given form name doesn't exist" );
}
