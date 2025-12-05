/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:26:13 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/02 14:28:52 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void ){}

Serializer::Serializer( const Serializer& other ){(void)other;}

Serializer&	Serializer::operator=( const Serializer& other ){(void)other; return (*this);}

uintptr_t	Serializer::serialize( Data* ptr )
{
	return ( reinterpret_cast<uintptr_t>(ptr) );
}

Data*		Serializer::deserialize( uintptr_t raw )
{
	return ( reinterpret_cast<Data *>(raw) );
}
