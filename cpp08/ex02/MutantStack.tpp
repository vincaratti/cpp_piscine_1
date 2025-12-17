/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:56:00 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/09 13:56:18 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack( void ): std::stack<T>(){}

template <typename T>
MutantStack<T>::MutantStack( const MutantStack& other ): std::stack<T>(other){}

template <typename T>
MutantStack<T>::~MutantStack( void ){}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=( const MutantStack& other )
{
	if ( *this != other )
		std::stack<T>::operator=(other);
	return ( *this );
}

template <typename T>
T&	MutantStack<T>::operator[]( const size_t idx )
{
	if ( idx >= this->size())
		throw IndexTooHighException();
	iterator it( this, idx );
	return ( *it );
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin( void )
{//empty stack? or point to end()
	MutantStack<T>::iterator	it( this, 0 );
	return ( it );
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end( void )
{
	MutantStack<T>::iterator	it( this, this->size() ); //not -1 because end() is elem after last
	return ( it );
}

template <typename T>
MutantStack<T>::iterator::iterator( void ): _ptr( NULL ), _idx(0), _end(0){}

template <typename T>
MutantStack<T>::iterator::iterator( MutantStack* ptr , size_t idx ): _ptr( ptr ), _idx( idx )
									, _end(idx >= ptr->size()? 1 : 0){}

template <typename T>
MutantStack<T>::iterator::iterator( const iterator& other ): _ptr( other._ptr ), _idx( other._idx ), _end( other._end ){}

template <typename T>
MutantStack<T>::iterator::~iterator( void ){}

template <typename T>
void	MutantStack<T>::iterator::update_idx( void )
{
	if ( _idx >= _ptr->size() || _end )
		_idx = _ptr->size();
}

template <typename T>
void	MutantStack<T>::iterator::update_idx( iterator& other )
{
	if ( _idx >= _ptr->size() || _end )
		_idx = _ptr->size();	
	if ( other._idx >= other._ptr->size() || other._end )
		other._idx = other._ptr->size();
}

template <typename T>
typename MutantStack<T>::iterator&	MutantStack<T>::iterator::operator=( const iterator& other )
{
	_end = other._end;
	_idx = other._idx;
	_ptr = other._ptr;
	return ( *this );
}

template <typename T>
T&	MutantStack<T>::iterator::operator*( void )
{
	size_t		i;
	const size_t	size = _ptr->size();
	std::stack<T>	temp;

	update_idx();

	if ( _idx >= _ptr->size() )
		throw CannotDerefEndException() ; //Cannot deref end elem

	for ( i = 0; i < (size - _idx - 1 ); i++ )
	{
		temp.push(_ptr->top());
		_ptr->pop();
	}

	T&	ret = _ptr->top();

	for ( ; i > 0; i-- )
	{
		_ptr->push(temp.top());
		temp.pop();
	}

	return ( ret );
}

template <typename T>
typename MutantStack<T>::iterator&	MutantStack<T>::iterator::operator++( void )
{
	update_idx();
	if ( _idx >= _ptr->size() )
	{
		_idx = _ptr->size();//end
		_end = 1;
	}
	else
		_idx++;

	return ( *this );
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::iterator::operator++( int )
{
	update_idx();
	MutantStack<T>::iterator	temp( *this );
	++*this;

	return ( temp );
}

template <typename T>
typename MutantStack<T>::iterator&	MutantStack<T>::iterator::operator--( void )
{
	update_idx();
	if ( _end && _idx > 0 )
		_end = 0;
	if ( _idx <= 0 )
		_idx = 0;//begin
	else
		_idx--;

	return ( *this );
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::iterator::operator--( int )
{
	update_idx();
	if ( _idx <= 0 )
		_idx = 0;

	MutantStack<T>::iterator	temp( *this );
	
	if ( _end && _idx > 0 )
		_end = 0;
	--*this;

	return ( temp );
}

template <typename T>
bool	MutantStack<T>::iterator::operator>( iterator& other )
{
	update_idx( other );
	if ( _ptr != other._ptr )
		throw DiffStackIteratorsCompException();
	return ( _idx > other._idx );
}

template <typename T>
bool	MutantStack<T>::iterator::operator<( iterator& other )
{
	update_idx( other );
	if ( _ptr != other._ptr )
		throw DiffStackIteratorsCompException();
	return ( _idx < other._idx );
}

template <typename T>
bool	MutantStack<T>::iterator::operator>=( iterator& other )
{
	update_idx( other );
	if ( _ptr != other._ptr )
		throw DiffStackIteratorsCompException();
	return ( _idx >= other._idx );
}

template <typename T>
bool	MutantStack<T>::iterator::operator<=( iterator& other )
{
	update_idx( other );
	if ( _ptr != other._ptr )
		throw DiffStackIteratorsCompException();
	return ( _idx <= other._idx );
}

template <typename T>
bool	MutantStack<T>::iterator::operator==( iterator& other )
{
	update_idx( other );
	if ( _ptr != other._ptr )
		throw DiffStackIteratorsCompException();
	return ( _idx == other._idx );
}

template <typename T>
bool	MutantStack<T>::iterator::operator!=( iterator& other )
{
	update_idx( other );
	if ( _ptr != other._ptr )
		throw DiffStackIteratorsCompException();
	return ( _idx != other._idx );
}

template <typename T>
const char*	MutantStack<T>::iterator::CannotDerefEndException::what() const throw()
{
	return ( "Cannot dereference end()." );
}

template <typename T>
const char*	MutantStack<T>::iterator::DiffStackIteratorsCompException::what() const throw()
{
	return ( "Cannot compare iterators of different stacks" );
}

template <typename T>
const char*	MutantStack<T>::IndexTooHighException::what() const throw()
{
	return ( "Index too high" );
}
