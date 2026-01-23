/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:02:48 by vcaratti          #+#    #+#             */
/*   Updated: 2026/01/23 13:41:14 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>

void	printTimeDiff( const timeval& start, const timeval& end , const char* container, size_t n )
{
	long	diff = ( (end.tv_sec - start.tv_sec) * 1000000L ) + ( end.tv_usec - start.tv_usec );

	std::cout	<< "Time to process a range of " << n << " elements with std::" << container
			<< " : " << diff << " µs" << std::endl;	
}

int main( int argc, char** argv )
{
	if ( argc < 3 )
	{
		std::cerr << "Not enough arguments." << std::endl;
		return 1;
	}

	unsigned int*	array = new unsigned int[ argc - 1 ];

	for ( int i = 1; i < argc; ++i )
	{
		std::string tmp(argv[i]);
		std::stringstream	stream(tmp);
		stream >> array[i - 1];
		if ( stream.fail() || !stream.eof() || tmp.at(0) == '-' )
		{
			std::cerr << "Error: bad argument: " << tmp << std::endl;
			return 1;
		}
	}

	PmergeMe::mergeSort_vect( array, argc - 1, 1 );

	struct timeval	start,end;
	
	gettimeofday( &start, 0 );
	PmergeMe::mergeSort_vect( array, argc - 1 );
	gettimeofday( &end, 0 );
	printTimeDiff( start, end, "vector", argc - 1 );

	gettimeofday( &start, 0 );
	PmergeMe::mergeSort_list( array, argc - 1 );
	gettimeofday( &end, 0 );
	printTimeDiff( start, end, "list", argc - 1 );

	return 0;
}
