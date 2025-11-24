/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:52:42 by vcaratti          #+#    #+#             */
/*   Updated: 2025/11/21 11:04:53 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main( int argc, char **argv )
{
	if ( argc != 2 )
		return ( std::cout << "bad number of arguments\n" , 1 );
	ScalarConverter::convert(argv[1]);
/*
	ScalarConverter::convert("0");
	ScalarConverter::convert("a");
	ScalarConverter::convert("7.00");
	ScalarConverter::convert("5.87f");
	ScalarConverter::convert("caca");

	std::string str = "b";
	int	i = std::atof(str.c_str());
	float f = std::atof(str.c_str());
	double d = std::atof(str.c_str());
	std::cout << "f: " << f << " ;d: " << d << " ;i: " << i << std::endl;*/
	return (1);
}
