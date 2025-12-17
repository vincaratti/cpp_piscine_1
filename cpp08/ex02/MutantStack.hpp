/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:56:00 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/16 13:26:12 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <stack>


template <typename T> class MutantStack : public std::stack<T>
{
public:
	class		iterator;

			MutantStack( void );
			MutantStack( const MutantStack& other );
			~MutantStack( void );
	MutantStack&	operator=( const MutantStack& other );
	T&		operator[]( const size_t idx );

	iterator	begin( void );
	iterator	end( void );

	class	iterator
	{
		private:
			MutantStack*	_ptr;
			size_t		_idx;
			bool		_end;

			void		update_idx( void );
			void		update_idx( iterator& other );
					iterator( void );//I prefer this over checking everywhere for _ptr == NULL
		public:
					iterator( MutantStack* ptr, size_t idx );
					iterator( const iterator& other );
					~iterator( void );
			iterator&	operator=( const iterator& other );

			T&		operator*( void );

			iterator	operator++( int );
			iterator	operator--( int );
	
			iterator&	operator++( void );
			iterator&	operator--( void );

			bool		operator>( iterator& other ); //comps not const bc constant updates to _idx
			bool		operator<( iterator& other );
			bool		operator>=( iterator& other );
			bool		operator<=( iterator& other );
			bool		operator==( iterator& other );
			bool		operator!=( iterator& other );

			class	CannotDerefEndException : public std::exception
				{ virtual const char*	what() const throw(); };

			class	DiffStackIteratorsCompException : public std::exception
				{ virtual const char*	what() const throw(); };
	};

		class	IndexTooHighException : public std::exception
			{ virtual const char*	what() const throw(); };
};

#include "MutantStack.tpp"
