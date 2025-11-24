/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:34:27 by vcaratti          #+#    #+#             */
/*   Updated: 2025/11/21 11:19:22 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ){}

ScalarConverter::ScalarConverter( const ScalarConverter& other ){(void)other;}

ScalarConverter&	ScalarConverter::operator=( const ScalarConverter& other ){(void)other; return ( *this );}

int	getType( std::string& str )
{
	enum Type ret;
	if ( isPseudo( str ) )
		ret = Pseudo;
	else if ( isInt( str ) )
		ret = Int;
	else if ( isDouble( str ) )
		ret = Double;
	else if ( isFloat( str ) )
		ret = Float;
	else if ( isChar( str ) )
		ret = Char;
	else
		ret = Error;
	return ( ret );
}


void	ScalarConverter::convert( std::string str )
{
	if ( str.size() < 1 )
		return ;//
	switch ( getType( str ) )
	{
		case 0:
			handleChar( str );
			break;
		case 1:
			handleInt( str );
			break;
		case 2:
			handleFloat( str );
			break;
		case 3:
			handleDouble( str );
			break;
		case 4:
			handlePseudo( str );
			break;
		case 5:
			handleError( str );
			break;
	}
}

