/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:27:45 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/09 12:42:45 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ): max_size( 0 ){}

Span::~Span( void ){}

Span::Span( const Span& other ): max_size( other.max_size ), data( other.data ){}

Span&	Span::operator=( const Span& other )
{
	this->data = other.data;
	this->max_size = other.max_size;
	return ( *this );
}

Span::Span( unsigned int N ): max_size( N ){}

void	Span::addNumber( int n )
{
	if ( this->data.size() == max_size )
		throw SizeLimitExceededException();
	this->data.push_back( n );
	std::sort( this->data.begin(), this->data.end() );
}

int	Span::shortestSpan( void ) const
{
	if ( this->data.size() <= 1 )
		throw NotEnoughNumbersException();
	std::vector<int> differences(this->data);
	std::adjacent_difference(differences.begin(), differences.end(), differences.begin());
	return ( *(std::min_element( (differences.begin() + 1), differences.end() )) );
}

int	Span::longestSpan( void ) const
{
	if ( this->data.size() <= 1 )
		throw NotEnoughNumbersException();
	return ( *(std::max_element(this->data.begin(), this->data.end()))
		- *(std::min_element(this->data.begin(), this->data.end())) );
}

const char*	Span::SizeLimitExceededException::what() const throw()
	{ return ("Maximum size exceeded for this container."); }

const char*	Span::NotEnoughNumbersException::what() const throw()
	{ return ("Not enough numbers to perform comparaison."); }

std::ostream&	operator<<( std::ostream& stream, const Span& obj )
{
	stream << "{ ";
	for ( std::vector<int>::const_iterator it = obj.data.begin(); it != obj.data.end(); it++ )
	{
		stream << *it;
		if ( (it + 1) != obj.data.end() )
			stream << " , ";
	}
	stream << " }; max size: " << obj.max_size << ", current size: " << obj.data.size();
	return ( stream );
}
