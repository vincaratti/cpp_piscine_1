/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:34:47 by vcaratti          #+#    #+#             */
/*   Updated: 2025/11/25 10:50:25 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data	d;
	d.data = "hello";

	uintptr_t	uptr;
	uptr = Serializer::serialize(&d);
	Data*	d_ptr = Serializer::deserialize(uptr);

	std::cout << "Object before serialization:\t" << d.data << std::endl << std::endl;
	std::cout << "Data structure address:\t\t" << &d << std::endl;
	std::cout << "intptr_t:\t\t\t" << uptr << std::endl;
	std::cout << "Data ptr post serialization:\t" << d_ptr << std::endl << std::endl;
	std::cout << "Object after serialization:\t" << d_ptr->data << std::endl;

	return ( 0 );
}
