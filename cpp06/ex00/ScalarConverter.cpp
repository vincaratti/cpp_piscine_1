/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:34:27 by vcaratti          #+#    #+#             */
/*   Updated: 2025/11/24 12:47:55 by vcaratti         ###   ########.fr       */
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
	std::ostream&	stream = std::cout;
	stream << std::setprecision(std::numeric_limits<double>::digits10 + 1);

	if ( str.size() < 1 )
		return ;

	int	type = getType( str );

	stream << "Detected type: ";
	switch ( type )
	{
		case 0:
			stream << "char" << std::endl;
			handleChar( str, stream );
			break;
		case 1:
			stream << "int" << std::endl;
			handleInt( str, stream );
			break;
		case 2:
			stream << "float" << std::endl;
			handleFloat( str, stream );
			break;
		case 3:
			stream << "double" << std::endl;
			handleDouble( str, stream );
			break;
		case 4:
			stream << "Pseudo" << std::endl;
			handlePseudo( str, stream );
			break;
		case 5:
			stream << "Error" << std::endl;
			handleError( str, stream );
			break;
	}
}

