/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:55:49 by vcaratti          #+#    #+#             */
/*   Updated: 2025/11/25 11:03:02 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{

private:
		Serializer( void );
		Serializer( const Serializer& other );
public:
		~Serializer( void );
	Serializer&	operator=( const Serializer& other );

	static uintptr_t	serialize( Data* ptr );
	static Data*		deserialize( uintptr_t raw ); 
};
