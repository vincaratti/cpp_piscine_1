/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:34:47 by vcaratti          #+#    #+#             */
/*   Updated: 2025/11/24 13:38:01 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data	pre_d;
	d.data = "hello";

	uintptr_t	uptr;
	uptr = Serializer::serialize(&d);
	
	std::cout << "string: " << (Serializer::deserialize(uptr))->data << std::endl;
}
