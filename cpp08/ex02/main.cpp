/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:56:00 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/16 13:11:50 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include "MutantStack.hpp"
#include <list>


int main()
{
	MutantStack<int> mstack;

	std::cout << "inserting 5, 17; ";
	mstack.push(5);
	mstack.push(17);

	std::cout << "top: " << mstack.top() << std::endl;

	std::cout << "popping top;\n";
	mstack.pop();

	std::cout << "size: " << mstack.size() << std::endl;

	std::cout << "pushing 3, 5 ,737, 0" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	//iterator goes back to begin()

	std::cout << "iterating over stack, will pop the top if it finds value == 3:" << std::endl;
	while (it != ite)
	{
		std::cout << "\t" << *it << std::endl;
		if ( *it == 3 )
			mstack.pop(); //can pop during iteration, stays safe, end is dynamicaly updated
		++it;
	}

	std::stack<int> s(mstack);
	std::cout << std::endl << "\nCreated of copy of the stack; top of mstack: " << mstack.top()
			<< ", top of stack: " << s.top() << std::endl;
	std::cout << "\nusing end iterator to access last elem and modify it, then returning it to end()." << std::endl; 
	ite--;
	*ite = 1000;
	ite++;

	it = mstack.begin();	

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	try
	{
		std::cout << "[] operator usage:" << std::endl
		<< "\tmstack[2] = " << mstack[2] << std::endl
		 << "\tmstack[size of stack] = " << mstack[mstack.size()] << std::endl;
	} catch ( std::exception &e )
		{ std::cout << "Exception caught: " << e.what() << std::endl; }
	

	std::cout << "\nComparing iterators of different stacks:" << std::endl;
	
	MutantStack<int>	mstack1;
	MutantStack<int>	mstack2;

	mstack1.push(1);
	mstack1.push(2);
	mstack1.push(3);

	mstack2.push(4);
	mstack2.push(5);
	mstack2.push(6);

	MutantStack<int>::iterator	it_start = mstack1.begin();
	MutantStack<int>::iterator	it_end = mstack2.end();
	
	try
	{
		while ( it_start != it_end )
			it_start++;
	} catch ( std::exception &e )
		{ std::cout << "Exception caught: " << e.what() << std::endl; }

	std::cout << "dereferencing end iterator" << std::endl;
	
	try 
	{
		*it_end;
	} catch ( std::exception &e )
		{ std::cout << "Exception caught: " << e.what() << std::endl; }

	MutantStack<int>		ms;
	MutantStack<int>::iterator	it_empty = ms.begin();

	try
	{
		std::cout << *it_empty << std::endl;
	} catch ( std::exception &e )
		{ std::cout << "Exception caught: " << e.what() << std::endl; }
	
	return ( 0 );
}
