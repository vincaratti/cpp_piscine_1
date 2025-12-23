/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:02:32 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/23 13:41:40 by vcaratti         ###   ########.fr       */
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
	return (rpn());		
}

int	RPN::execute( std::string input )
{
	RPN tmp( input );
	return ( tmp.execute() );
}

bool	RPN::_is_op( char c )
{
	return ( ( c == '+' || c == '-' || c == '*' || c == '/' ) ? 1 : 0 );
}

bool	RPN::_is_not_valid( char c )
{
	return ( ( ( c >= '0' && c <= '9' ) || RPN::_is_op(c) || c == ' ') ? 0 : 1 );
}

void	RPN::_fill( std::string input ) //cannot fill stack using STL without it taking 20+ lines
{
	if ( std::find_if( input.begin(), input.end(), RPN::_is_not_valid ) != input.end() )
		throw InvalidCharacterException();
	std::string::iterator new_end = std::remove(input.begin(), input.end(), ' ');
	for ( std::string::iterator it = input.begin(); it != new_end; ++it )
		this->push( *it );
}

char	RPN::tpop( void )
{
	char	top = this->top();
	this->pop();
	return ( top );
}

int	RPN::rpn( void )
{
	if ( empty() )
		throw InvalidInputException();
	char	top = tpop();
	if (  !_is_op( top ) )
		return ( (top - '0') );

	int	right = rpn();
	int	left = rpn();

	if ( top == '+' )
		return ( left + right );
	if ( top == '-' )
		return ( left - right );
	if ( top == '*' )
		return ( left * right );
	return ( left / right );
	
}

const char*	RPN::InvalidCharacterException::what() const throw()
{
	return ( "Invalid character in input." );
}

const char*	RPN::InvalidInputException::what() const throw()
{
	return ( "Invalid input." );
}
