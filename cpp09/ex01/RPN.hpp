/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:02:39 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/22 14:04:11 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <exception>

class	RPN : std::stack<char>
{
private:
	void	_push_if( char c );
	bool	_is_valid( char c ) const;
	void	_fill( std::string &input );
public:
		RPN( void );
virtual		~RPN( void );
		RPN( std::string input );
		RPN( const RPN &other );

	RPN&	operator=( const RPN& other );

	int	execute( void );
static	int	execute( std::string input );

int	tpop( void );
int	rpn( void );

	class	InvalidCharacterException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};
 
