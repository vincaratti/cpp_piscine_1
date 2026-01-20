/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:02:08 by vcaratti          #+#    #+#             */
/*   Updated: 2026/01/20 12:43:25 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main( int argc, char **argv )
{
	if ( argc < 2 )
	{
		std::cout << "Error: could not open file.\n";
		return 1;
	}
	try
	{
		BitcoinExchange		btc( "data.csv" );
		btc.execute_file( argv[1] );
	}
	catch ( std::exception& e )
	{
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
