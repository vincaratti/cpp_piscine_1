/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:53:21 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/24 12:40:52 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
	Bureaucrat bob("bob", 1);
	Bureaucrat John;

	try
	{
		std::cout << "1" << std::endl;
		John.incrementGrade();
		std::cout << "2" << std::endl;
		bob.incrementGrade();
		std::cout << "3" << std::endl;
		//bob.incrementGrade();
		std::cout << "4" << std::endl;
		std::cout << bob << std::endl;
		std::cout << "wut" << std::endl;
		Bureaucrat	dumbahh( "stoopid", 200 );
		std::cout << "5" << std::endl;
	}
	catch ( std::exception& e )
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
