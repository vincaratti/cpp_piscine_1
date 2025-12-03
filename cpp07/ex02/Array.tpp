/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:36:20 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/03 15:08:57 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T> const char* Array<T>::BadIndexException::what() const throw()
	{ return ( "Index out of bounds." ); }

template <typename T> Array<T>::Array( void ): _size(0), _arr( NULL )
	{ std::cout<< "default constructor called.\n"; }

template <typename T> Array<T>::Array( const Array& other ): _size(other.size())
							, _arr( _size > 0 ? new T[other.size()] : NULL)
{
	std::cout << "copy constructor called.\n";
	for (size_t i = 0; i < _size && i < other.size(); i++)
		_arr[i] = other[i];
}

template <typename T> Array<T>::Array( size_t n ): _size(n), _arr( new T[n] )
	{ std::cout << "size constructor called.\n"; }

template <typename T> Array<T>::~Array( void )
{
	std::cout << "destructor called.\n";
	delete[] _arr;
}

template <typename T> Array<T>&	Array<T>::operator=( const Array& other )
{
	std::cout << "assignment operator called.\n";
	if ( this->_arr == other._arr )
		return ( *this );
	delete[] _arr;
	_size = other.size();
	_arr = new T[_size];
	for (size_t i = 0; i < _size; i ++)
		_arr[i] = other[i];
	return ( *this );
}

template <typename T> T const	&Array<T>::operator[]( int idx ) const
{
	if ( idx < 0 || idx >= static_cast<int>(_size) )
		throw Array<T>::BadIndexException();
	return ( _arr[idx] );
}

template <typename T> T&	Array<T>::operator[]( int idx )
{
	if ( idx < 0 || idx >= static_cast<int>(_size) )
		throw Array<T>::BadIndexException();
	return ( _arr[idx] );
}

template <typename T> size_t	Array<T>::size( void ) const {return ( _size );}
