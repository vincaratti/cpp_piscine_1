/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:02:00 by vcaratti          #+#    #+#             */
/*   Updated: 2026/01/21 10:40:36 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <map>
#include <exception>
#include <limits.h>

class BitcoinExchange
{
private:
		BitcoinExchange( void );

	std::map< std::string, double > database;
public:
		BitcoinExchange( const std::string& db_fn );
		BitcoinExchange( const BitcoinExchange& other );
		~BitcoinExchange( void );
	BitcoinExchange&	operator=( const BitcoinExchange& other );

	void	execute_file( const std::string& fn );

	class	BadFileNameException : public std::exception
	{
		virtual const char*	what() const throw();
	};

	class	BadFormatException : public std::exception
	{
	private:
		std::string	_err;
	public:
		virtual ~BadFormatException() throw();
			BadFormatException( const char* err );
		virtual const char*	what() const throw();
	};
};
