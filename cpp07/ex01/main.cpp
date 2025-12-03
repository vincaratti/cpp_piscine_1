/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:19:01 by vcaratti          #+#    #+#             */
/*   Updated: 2025/11/25 14:03:21 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

void	increment(int &i){ i++; }

void	printnb(const int &i){ std::cout << i << std::endl; }

int main( void )
{
	std::string	s = "abcd";
	int numbers[] = {32,45,55,67};
	const int c_numbers[] = {32,45,55,67};

	std::cout << "before incrementation:\n";
	iter( numbers, 4, &printnb );
	iter( numbers, 4, &increment );
	std::cout << "\nafter incrementation:\n";
	iter( numbers, 4, &printnb );

	//::iter( c_numbers, 4, &increment ); //cant work

	std::cout << "\nconst numbers:\n";
	iter( c_numbers, 4, &printnb );

	std::cout << "\ntemplated function given as param; print on int:\n";
	iter( numbers, 4, ::printobj<int> );
	std::cout << "\ntemplated function given as param; print on c str:\n";
	iter( s.c_str(), s.size(), ::printobj<const char> );
}
