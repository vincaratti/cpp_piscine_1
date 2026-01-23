/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:03:09 by vcaratti          #+#    #+#             */
/*   Updated: 2026/01/23 13:05:26 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp" 

void	PmergeMe::mergeSort_vect( unsigned int* arr, const size_t n, bool print )
{
	std::vector< unsigned int >	vect;

	for ( size_t i = 0; i < n; i++ )
		vect.push_back( arr[i] );

	if ( print )
	{
		std::cout << "Before: ";
		for ( std::vector< unsigned int >::iterator it = vect.begin(); it != vect.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	mergeSort< std::vector< unsigned int > >( vect.begin(), --vect.end() );

	if ( print )
	{
		std::cout << "After: ";
		for ( std::vector< unsigned int >::iterator it = vect.begin(); it != vect.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}

void	PmergeMe::mergeSort_list( unsigned int* arr, const size_t n, bool print )
{
	std::list< unsigned int >	list;

	for ( size_t i = 0; i < n; i++ )
		list.push_back( arr[i] );

	if ( print )
	{
		std::cout << "Before: ";
		for ( std::list< unsigned int >::iterator it = list.begin(); it != list.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	mergeSort< std::list< unsigned int > >( list.begin(), --list.end() );
	
	if ( print )
	{
		std::cout << "After: ";
		for ( std::list< unsigned int >::iterator it = list.begin(); it != list.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}
