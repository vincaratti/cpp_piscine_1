/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:02:39 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/23 13:20:07 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <iterator>

class	RPN : std::stack<char>
{
private:
	static bool	_is_not_valid( char c );
	static bool	_is_op( char c );
	void		_fill( std::string input );
public:
		RPN( void );
virtual		~RPN( void );
		RPN( std::string input );
		RPN( const RPN &other );

	RPN&	operator=( const RPN& other );

	int	execute( void );
static	int	execute( std::string input );

	char	tpop( void );
	int	rpn( void );

	class	InvalidCharacterException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class	InvalidInputException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};
 
