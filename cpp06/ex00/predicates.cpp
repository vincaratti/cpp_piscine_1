/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:13:47 by vcaratti          #+#    #+#             */
/*   Updated: 2025/11/21 11:15:53 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "predicates.hpp"

bool	isPseudo( const std::string& str )
{
	if ( str == "-inf" || str == "+inf" || str == "nan" )
		return ( 1 );
	return ( 0 );
}

bool	isInt( const std::string& str )
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++ ){
		if ( (int)(*it) - '0' < 0 || (int)(*it) - '0' > 9 )
			return ( 0 );
	}
	return ( 1 );
}

bool	isDouble( const std::string& str )
{
	for ( std::string::const_iterator it = str.begin(); it != str.end(); it++ ){
		if ( *it != '.' && ((int)(*it) - '0' < 0 || (int)(*it) - '0' > 9) )
			return ( 0 );
	}
	return ( 1 );
}

bool	isFloat( const std::string& str )
{
	for ( std::string::const_iterator it = str.begin(); it != str.end(); it++ ){
		if ( *it != 'f' && *it != '.' && ((int)(*it) - '0' < 0 || (int)(*it) - '0' > 9) )
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
