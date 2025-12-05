/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:27:45 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/05 13:13:19 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Span.tpp"
#include <algorithm>
#include <vector>
#include <iostream>
#include <exception>
#include <iterator>

class	Span
{
public:
	unsigned int	max_size;
	std::vector	data;
	
		Span( void );
		Span( const Span& other );
		~Span( void );
	Span&	operator=( const Span& other );

		Span( unsigned int N );

	int	shortestSpan( void ) const;
	int	longestSpan( void ) const;

	template <typename T> void	insertRange( T::iterator start, T::iterator end );

	class	SizeLimitExceededException : public std::exception
	{
		virtual const char* what() const throw();
	}

	class	NotEnoughNumbersException : public std::exception
	{
		virtual const char* what() const throw();
	}
};

std::ostream&	operator<<( std::ostream& stream, Span& obj ); 
