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

#include "RPN.hpp"

int main( int argc, char **argv )
{
	try
	{
		RPN rpn1("1 2 +");

		std::cout << "RPN rpn1(1 2 +); rpn1.execute():\t" << rpn1.execute() << std::endl;

		std::cout << "RPN::execute(1 2 +):\t\t\t" << RPN::execute("1 2 +") << std::endl;

		if ( argc == 2 )
			std::cout << "RPN::execute(argv[1]):\t\t\t" << RPN::execute(argv[1]) << std::endl;
	}
	catch ( std::exception &e )
		{ std::cout << "Caught exception: " << e.what() << std::endl; }
	return (0);
}
