/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:27:45 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/09 12:50:02 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
#include <exception>
#include <iterator>
#include <numeric>
#include <cstdlib>
#include <ctime>

class	Span
{
public:
	unsigned int		max_size;
	std::vector<int>	data;
	
		Span( void );
		Span( const Span& other );
		~Span( void );
	Span&	operator=( const Span& other );

		Span( unsigned int N );

	int	shortestSpan( void ) const;
	int	longestSpan( void ) const;

	void	addNumber( int n );
	template <typename T> void	insertRange( typename T::const_iterator start, typename T::const_iterator end );

	class	SizeLimitExceededException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class	NotEnoughNumbersException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream&	operator<<( std::ostream& stream, const Span& obj ); 

#include "Span.tpp"
