/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:53:21 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/26 13:44:21 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main( void )
{
	Bureaucrat bob("bob", 10);
	Bureaucrat John("john", 149);
	AForm*	currentForm;
	Intern	Tibothy;	

	try
	{
		currentForm = Tibothy.makeForm( "PresidentialPardonForm", "bob");
		bob.signForm( *currentForm );
		John.executeForm( *currentForm );

		delete currentForm;

		//currentForm = Tibothy.makeForm( "theindustr..", "society" );
	}
	catch ( std::exception& e )
	{
		std::cout<< "CAUGHT EXCEPTION:\n\t";
		std::cout << e.what() << std::endl;
	}

	return (0);
}
