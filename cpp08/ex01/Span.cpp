/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:27:45 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/05 13:08:21 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ): max_size( 0 ){}

Span::Span( const Span& other ): max_size( other.max_size ), data( other.data ){}

Span&	Span::operator=( const Span& other )
{
	this->data = other.data;
	this->max_size = other.max_size;
	return ( *this );
}

Span::Span( unsigned int N ): max_size( N ){}

int	Span::shortestSpan( void )
{
	(void);
}

int	Span::longestSpan( void )
{
	(void);
}

const char*	Span::SizeLimitExceededException::what() const throw()
	{ return ("Maximum size exceeded for this container."); }

const char*	Span::NotEnoughNumbersException::what() const throw()
	{ return ("Not enough numbers to perform comparaison."); }

std::ostream&	operator<<( std::ostream& stream, const Span& obj )
{
	stream << "{ ";
	for ( std::vector::const_iterator it = obj.data.begin(); it != obj.data.end(); it++ )
	{
		stream << *it;
		if ( (it + 1) != obj.data.end() )
			stream << " , ";
	}
	stream << " }";
	return ( stream );
}
