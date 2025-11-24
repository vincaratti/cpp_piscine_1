/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:22:31 by vcaratti          #+#    #+#             */
/*   Updated: 2025/11/24 12:41:07 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "includes.hpp"
#include "handlers.hpp"
#include "predicates.hpp"

class ScalarConverter {
private:
	ScalarConverter( void );
	ScalarConverter( const ScalarConverter& other );
public:
	~ScalarConverter( void );
	ScalarConverter& operator=( const ScalarConverter& other );

	static void	convert( std::string str );
};

enum Type
{
	Char,
	Int,
	Float,
	Double,
	Pseudo,
	Error
};
