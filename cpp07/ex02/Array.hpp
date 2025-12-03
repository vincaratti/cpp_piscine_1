/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:36:20 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/03 15:58:07 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <ctime>
#include <cstdlib>

template <typename T> class Array
{
private:
	size_t		_size;
	T*		_arr;
public:

		Array( void );
		Array( const Array& other );
		Array( size_t n );
		~Array( void );

	Array&	operator=( const Array& other );
	T const	&operator[]( int idx ) const;
	T&	operator[]( int idx );

	size_t		size( void ) const;

	class	BadIndexException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

#include "Array.tpp"
