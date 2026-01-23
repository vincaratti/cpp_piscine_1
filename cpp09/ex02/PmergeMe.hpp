/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:03:14 by vcaratti          #+#    #+#             */
/*   Updated: 2026/01/23 13:20:22 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <list>
#include <vector>
#include <string>
#include <sstream>

class	PmergeMe
{
public:
	static void	mergeSort_vect( unsigned int* arr, const size_t n, bool print = 0 );
	static void	mergeSort_list( unsigned int* arr, const size_t n, bool print = 0 );
};

template < typename T >
typename T::iterator	getMidIt( typename T::iterator start, typename T::iterator end )
{
	size_t	dist = (std::distance( start, end ) - 1) / 2;
	while ( dist-- )
		start++;
	return ( start );
}

template < typename T >
void	merge( typename T::iterator left, typename T::iterator mid, typename T::iterator right )
{
	T	left_cont;
	typename T::iterator it_fill = left;
	while (1)
	{
		left_cont.push_back( *it_fill );
		if ( it_fill++ == mid )
			break;
	}
	T	right_cont;
	while (1)
	{
		right_cont.push_back( *it_fill );
		if ( it_fill++ == right )
			break;
	}
	
	typename T::iterator	l_it = left_cont.begin();
	typename T::iterator	r_it = right_cont.begin();
	typename T::iterator	insert_it = left;

	while ( l_it != left_cont.end() && r_it != right_cont.end() )
	{
		if ( *l_it <= *r_it )
			*insert_it++ = *l_it++;
		else
			*insert_it++ = *r_it++;
	}
	while ( l_it != left_cont.end() )
		*insert_it++ = *l_it++;
	while ( r_it != right_cont.end() )
		*insert_it++ = *r_it++;	
}

template < typename T >
void	mergeSort( typename T::iterator left, typename T::iterator right )
{
	if ( std::distance( left, right ) <= 0 )
		return ;

	typename T::iterator	mid = getMidIt<T>( left, right );

	mergeSort<T>( left, mid );
	mergeSort<T>( ++mid , right );
	
	merge<T>( left, --mid, right );
}

