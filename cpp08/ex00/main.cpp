/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:58:49 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/05 10:48:10 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>

int main( void )
{
	try
	{
		std::vector<int> v;
		for ( int i = 1; i < 6; i++)
			v.push_back(i);
		std::cout 	<< "value in v[3]: " << v[3]
			 	<< " ,value at address returned by easyfind(v[3]): "
				<< easyfind<std::vector<int> >(v, v[3]) 
				<< std::endl
				<< "address of v[3]: " << &(v[3])
				<< " , address of return of easyfind(3): "
				<< &(easyfind<std::vector<int> >(v, v[3]))
				<< std::endl << std::endl;
		v[3] = 1000;
		std::cout 	<< "value in v[3]: " << v[3]
		 		<< " ,value at address returned by easyfind(v[3]): "
				<< easyfind<std::vector<int> >(v, v[3]) 
				<< std::endl
				<< "address of v[3]: " << &(v[3])
				<< " , address of return of easyfind(3): "
				<< &(easyfind<std::vector<int> >(v, v[3]))
				<< std::endl << std::endl;
		
		std::cout	<< "Looking for inexistant integer: "
				<< std::endl
				<< easyfind< std::vector<int> >(v, 200000);
	}
	catch ( std::exception &e )
		{ std::cout << e.what() << std::endl; }
	return (0);
}
