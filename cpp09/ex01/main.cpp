/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:02:23 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/23 13:41:18 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//try ./NPM "invalid sequence" > /dev/null , only the error will show.

#include "RPN.hpp"

int main( int argc, char **argv )
{
	try
	{
		if ( argc == 1 )
		{
			RPN rpn1("1 2 +");

			std::cout << "RPN rpn1(1 2 +); rpn1.execute():\t" << rpn1.execute() << std::endl;

			std::cout << "RPN::execute(1 2 +):\t\t\t" << RPN::execute("1 2 +") << std::endl;

			std::cout << std::endl << "[tip] Try: ./RPN \"expression\"" << std::endl;
		}
		else if ( argc == 2 )
			std::cout << "RPN::execute(argv[1]):\t\t\t" << RPN::execute(argv[1]) << std::endl;
		else
			std::cerr << "invalid number of arguments." << std::endl;
	}
	catch ( std::exception &e )
		{ std::cerr << "Caught exception: " << e.what() << std::endl; }
	return (0);
}
