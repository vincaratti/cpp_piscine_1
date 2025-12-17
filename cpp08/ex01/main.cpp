/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:30:51 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/09 12:57:23 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << "Span sp: " << sp << std::endl;
	std::cout << "sp shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "sp longest :" << sp.longestSpan() << std::endl;


	Span sp2 = Span(15);

	std::vector<int> v;
	for (int i = 0; i < 5; i++)
	{ v.push_back(i*5); }

	sp2.insertRange<std::vector<int> >(sp.data.begin(), sp.data.end());
	sp2.insertRange<std::vector<int> >(v.begin(), v.end());
	sp2.insertRange<std::vector<int> >(sp.data.begin(), sp.data.end());

	std::cout << "Span sp2: " << sp2 << std::endl;
	// now at size 15
	
	try {
		sp2.addNumber(5);
	} catch ( std::exception &e )
	{ std::cerr << e.what() << std::endl; }
	
	try {
		sp2.insertRange<std::vector<int> >(v.begin(), v.end());
	} catch ( std::exception &e )
	{ std::cerr << e.what() << std::endl; }
	
	std::cout << "sp2 shortest: " << sp2.shortestSpan() << std::endl;
	std::cout << "sp2 longest :" << sp2.longestSpan() << std::endl;

	Span sp3 = Span(100001);

	std::srand(std::time(NULL));

	std::vector<int> r_values;
	for (unsigned int i = 0; i < sp3.max_size; i++ )
		r_values.push_back(std::rand() % sp3.max_size);
	sp3.insertRange< std::vector<int> >(r_values.begin(), r_values.end());
	std::cout << "Span sp3: { too long }, max_size: " << sp3.max_size << ", current size: " << sp3.data.size() << std::endl;

	std::cout << "sp3 shortest: " << sp3.shortestSpan() << std::endl;
	std::cout << "sp3 longest :" << sp3.longestSpan() << std::endl;

	return 0;
}
