/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:03:09 by vcaratti          #+#    #+#             */
/*   Updated: 2026/02/03 10:00:45 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp" 

	Node::Node( void ): _inserted( 0 ), next( NULL ), inferior( NULL ), val( 0 ){}

	Node::Node( const Node& other ): _inserted( other._inserted ), next( other.next ), inferior( other.inferior ), val( other.val ){}

	Node::~Node( void ){}

Node&	Node::operator=( const Node& other )
{
	this->_inserted = other._inserted ;
	this->next = other.next;
	this->inferior = other.inferior;
	this->val = other.val;
	return ( *this );
}

size_t	jacob_n( unsigned int n )
{
	if ( n == 0 || n == 1 )
		return n;
	size_t	j0 = 0;
	size_t	j1 = 1;
	size_t	jn;

	for ( size_t i = 2; i <= n; ++i )
	{
		jn = j1 + ( 2 * j0 );
		j0 = j1;
		j1 = jn;
	}
	return jn;
}
