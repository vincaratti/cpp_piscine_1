/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:13:47 by vcaratti          #+#    #+#             */
/*   Updated: 2025/11/24 12:36:22 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "predicates.hpp"

static bool	isSign( const char c )
{
	if ( c == '-' || c == '+' )
		return ( 1 );
	return ( 0 );
}

bool	isPseudo( const std::string& str )
{
	if ( str == "-inf"
		|| str == "+inf"
		|| str == "nan"
		|| str == "-inff"
		|| str == "+inff"
		|| str == "nanf" )
		return ( 1 );
	return ( 0 );
}

bool	isInt( const std::string& str )
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++ ){
		if ( ((int)(*it) - '0' < 0 || (int)(*it) - '0' > 9) && !isSign(*it) )
			return ( 0 );
	}
	return ( 1 );
}

bool	isDouble( const std::string& str )
{
	for ( std::string::const_iterator it = str.begin(); it != str.end(); it++ ){
		if ( *it != '.' && ((int)(*it) - '0' < 0 || (int)(*it) - '0' > 9) && !isSign(*it) )
			return ( 0 );
	}
	return ( 1 );
}

bool	isFloat( const std::string& str )
{
	for ( std::string::const_iterator it = str.begin(); it != str.end(); it++ ){
		if ( *it != 'f' && *it != '.' && ((int)(*it) - '0' < 0 || (int)(*it) - '0' > 9) && !isSign(*it))
			return ( 0 );
	}
	return ( 1 );	
}

bool	isChar( const std::string& str )
{
	if ( str.size() != 1 )
		return ( 0 );
	if ( str[0] > 32 &&  str[0] < 126 )
		return ( 1 );
	return ( 0 );
}

bool	isDisplayable( const char c )
{
	return ( c > 32 && c < 126 );
}
