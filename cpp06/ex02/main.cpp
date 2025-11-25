/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:37:09 by vcaratti          #+#    #+#             */
/*   Updated: 2025/11/25 12:21:02 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate( void )
{
	Base*	arr[3];
	arr[0] = new A();	
	arr[1] = new B();	
	arr[2] = new C();

	std::srand(std::time(NULL));
	const int rd = std::rand() % 3;
	for ( int i = 0; i < 3; i++ )
	{
		if ( i != rd )
			delete ( arr[i] );
	}
	return (arr[rd]);
}

void	identify( Base* ptr )
{
	std::cout << "Pointer of type: ";

	A* a = dynamic_cast<A*>(ptr);
	if ( a != NULL )
		std::cout << "A\n";

	B* b = dynamic_cast<B*>(ptr);
	if ( b != NULL )
		std::cout << "B\n";

	C* c = dynamic_cast<C*>(ptr);
	if ( c != NULL )
		std::cout << "C\n";
}

void	identify( Base& ptr )
{
	std::cout << "Reference of type: ";

	try {
		A& a = dynamic_cast<A&>(ptr);
		(void)a;
		std::cout << "A\n";
		return ;
	} catch (std::bad_cast exp) {}
	try {
		B& b = dynamic_cast<B&>(ptr);
		(void)b;
		std::cout << "B\n";
		return ;
	} catch (std::bad_cast exp) {}
	try {
		C& c = dynamic_cast<C&>(ptr);
		(void)c;
		std::cout << "C\n";
		return ;
	} catch (std::bad_cast exp) {}
}

int main( void )
{
	Base*	ptr = generate();
	Base&	ref = *ptr;

	identify( ptr );
	identify( ref );
}
