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

size_t	jacob_n( unsigned int n );

class Node
{
private:
		Node( void );
public:
	Node		*next;
	Node		*inferior;
	unsigned int	val;

		Node( const Node& other );
		~Node( void );
	Node&	operator=( const Node& other );
};

template < typename T >
class PmergeMe
{
private:
		//PmergeMe( void );

	typename T< Node >&	G_cont;
	typename T< Node >	L_cont;
public:
		PmergeMe( const PmergeMe& other );
		PmergeMe( typename T< Node >& input );
		~PmergeMe( void );
	PmergeMe& operator=( const PmergeMe& other );	
};

//template < typename T >
//	PmergeMe::PmergeMe( void )

template < typename T >
	PmergeMe::PmergeMe( const PmergeMe& other ): G_cont( other.G_cont ), L_cont( other.L_cont ){}

template < typename T >
	PMergeMe::PmergeMe( typename T< Node >& input ): G_cont( input )
{
	if ( G_cont.size() > 1 )
	{
		_split();
		PmergeMe rec = PmergeMe( this->G_cont );
	}
	_merge_list();/////////////////!!!!!!!!!!!!!!!
	_merge_vect();
}

template < typename T >
void	PmergeMe::_split( void )
{
	size_t	count = 0;
	Node*	prev;

	for ( typename T< Node >::iterator it = G_cont.begin(); it != G_cont.end(); it++ )
	{
		if ( count % 2 )
		{
			if ( *it.val >= prev.val )
			{
				prev.next = *it.inferior;
				*it.inferior = &prev;
				L_cont.push_back( Node( prev ) );
				it = G_cont.erase( it );
			}
			else
			{
				*it.next = prev.inferior;
				prev.inferior = &(*it);
				L_cont.push_back( Node( *it ) );
				it = G_cont.erase( --it );
				it++;
			}
		}
		else
			prev = *it;

		count++;
	}
	if ( count % 2 )
	{
		L_cont.push_back( G_cont.back() );
		G_cont.pop_back();
	}	
}

template < typename T >
void	PmergeMe::_b_insert( typename T<Node>::iterator end, Node& node )
{
	
}

template < typename T >
void	PmergeMe::_merge_list( void )
{
	//typename T<Node *>		toMerge;
	typename T< typename T<Node>::iterator >	toMergeIts;
	typename T<Node>::iterator	it = G_cont.begin();
	size_t				count = 1;
	size_t				jn;

	while ( it != G_cont.end() )
	{
		jn = jacob_n( count );
		while ( jn-- && it != G_cont.end() )
		{
			//toMerge.push_back( &(*it) )
			toMergeIts.push_back( it );
			it++;
		}
		for ( typename T< typename T<Node>::iterator>::iterator itr = toMerge.rbegin(); itr != toMerge.rend(); ++itr )
		{
			Node&	toInsert = *(*itr).inferior;
			*(*(*itr).inferior = toInsert.next;
			toInsert.next = NULL;
	
			_b_insert( *itr, toInsert );
		}
		toMerge.clear();
		count++;
	}
}

