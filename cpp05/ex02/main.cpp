/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:53:21 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/26 13:47:23 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main( void )
{
	Bureaucrat bob("bob", 10);
	Bureaucrat John;
	ShrubberyCreationForm	formA("bobs_garden");
	RobotomyRequestForm	formB("john");
	PresidentialPardonForm	formC("john again");

	try
	{
		std::cout << "incrementing john\n";
		std::cout << John;
		John.incrementGrade();
		std::cout << std::endl;
		std::cout << John;
		
		std::cout << "\n\n\nincrementing bob\n\n";
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << "\n";
		std::cout << bob << std::endl;

		std::cout << "\n\n\nForm A\n\n";
		std::cout << formA << std::endl;
		std::cout << "\n";
		bob.signForm( formA );
		std::cout << "\n";
		std::cout << formA << std::endl;
		std::cout << "\n";
		bob.executeForm( formA );

		std::cout << "\n\n\nForm B\n\n";
		std::cout << formB << std::endl;
		std::cout << "\n";
		bob.signForm( formB );
		std::cout << "\n";
		std::cout << formB << std::endl;
		std::cout << "\n";
		bob.executeForm( formB );

		std::cout << "\n\n\nForm C\n\n";
		std::cout << formC << std::endl;
		std::cout << "\n";
		bob.signForm( formC );
		std::cout << "\n";
		std::cout << formC << std::endl;
		std::cout << "\n";
		bob.executeForm( formC );
	}
	catch ( std::exception& e )
	{
		std::cout<< "CAUGHT EXCEPTION:\n\t";
		std::cout << e.what() << std::endl;
	}

	return (0);
}
