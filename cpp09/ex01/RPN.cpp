/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:02:32 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/22 14:08:22 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void ): std::stack<char>(){};

RPN::~RPN( void ){}

RPN::RPN( std::string input ){ _fill( input );};

RPN::RPN( const RPN &other ): std::stack<char>( other ){};

RPN&	RPN::operator=( const RPN &other ){ std::stack<char>::operator=(other); return (*this); };

int	RPN::execute( void )
{
	return (0);		
}

int	RPN::execute( std::string input )
{
	RPN tmp( input );
	return ( tmp.execute() );
}

bool	RPN::_is_valid( char c ) const
{
	if ( (c < '0' || c > '9') && c != '+' && c != '-' && c != '*' && c != '/' && c != ' ')
		return ( 0 );
	return ( 1 );
}

void	RPN::_push_if( char c )
{
	if ( c != ' ' )
		this->push(c);
}

void	RPN::_fill( std::string &input )
{
	if ( std::find_if( input.begin(), input.end(), RPN::_is_valid ) != input.end() )
		throw InvalidCharacterException();
	std::for_each( input.begin(), input.end(), RPN::_push_if );
}

const char*	RPN::InvalidCharacterException::what() const throw()
{
	return ( "invalid character in input." );
}
