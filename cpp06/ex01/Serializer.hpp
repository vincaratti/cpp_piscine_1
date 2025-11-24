/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:55:49 by vcaratti          #+#    #+#             */
/*   Updated: 2025/11/24 13:33:26 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef struct	Data_s	{
	std::string	data;
}	Data;

class Serializer
{

private:
		Serializer( void );
		Serializer( const Serializer& other );
public:
	virtual	~Serializer( void );
	Serializer&	operator=( const Serializer& other );

	uintptr_t	serialize( Data* ptr);
	Data*		deserialize( uintptr_t raw ); 
};
