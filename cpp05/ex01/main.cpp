/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:53:21 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/24 14:54:46 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
	Bureaucrat bob("bob", 10);
	Bureaucrat John;
	Form	formA("Petition change water colour", 15, 10);
	Form	formB("Petition change sky colour", 2, 1);

	try
	{
		std::cout << John << std::endl;
		John.incrementGrade();
		std::cout << John << std::endl;
		
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;

		std::cout << formA << std::endl;
		bob.signForm( formA );
		std::cout << formA << std::endl;

		std::cout << formB << std::endl;
		bob.signForm( formB );
		std::cout << formB << std::endl;
	}
	catch ( std::exception& e )
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
