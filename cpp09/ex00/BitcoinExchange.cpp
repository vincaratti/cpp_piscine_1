/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:01:29 by vcaratti          #+#    #+#             */
/*   Updated: 2026/01/20 13:43:44 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	isValidDate( const std::string& date )
{
	if ( date.size() != 10 )
		return 0;
	if ( date[4] != '-' || date[7] != '-' )
		return 0;
	for ( std::string::const_iterator it = date.begin(); it != date.end(); ++it )
	{
		if ( *it != '-' && ( *it > '9' || *it < '0' ) )
			return 0 ;
	}
	int	m = std::atoi( date.substr(5,2).c_str() );
	int	d = std::atoi( date.substr(8,2).c_str() );
	if ( m <= 0 || m >= 12 || d <= 0 || d >= 31 ) //doesnt check for days of the month,
		return 0;
	return 1;
	
}

void	parserDB( const std::string& fn, std::map< std::string, double >& map )
{
	std::ifstream	file( fn.c_str() );
	if ( !file )
		throw BitcoinExchange::BadFileNameException();

	std::string	line;
	std::getline( file, line );
	if ( line != "date,exchange_rate" ) 
		throw BitcoinExchange::BadFormatException( "db first line needs to be: \"date,exchange_rate\"" );

	std::string	date, value;

	while ( std::getline( file, line) )
	{
		if ( line.empty() )
			throw BitcoinExchange::BadFormatException( "Empty line in database" );
		if ( line.find( ',' ) != 10 )
			throw BitcoinExchange::BadFormatException( "Bad line in database" );

		date = line.substr(0, 10);
		if  ( !isValidDate( date ) )
			throw BitcoinExchange::BadFormatException( "Incorrect date in database" );

		value = line.substr(11);
		std::stringstream	tmp_ss( value );
		double			tmp_d;
		tmp_ss >> tmp_d;
		if ( tmp_ss.fail() )
			throw BitcoinExchange::BadFormatException( "Encountered failure whilst parsing database" );
		if ( tmp_d > INT_MAX || tmp_d < 0 )
			throw BitcoinExchange::BadFormatException( "Invalid Value in database" );

		map[date] = tmp_d;
	}
}

void	decrementDate( std::string& date )
{
	int	y = std::atoi(date.substr(0, 4).c_str());
	int	m = std::atoi(date.substr(5, 2).c_str());
	int	d = std::atoi(date.substr(8, 2).c_str());

	if ( d > 1 )
		--d;
	else
	{
		d = 31;
		if ( m > 1 )
			--m;
		else
		{
			m = 12;
			--y;
		}
	}
	std::stringstream	res;
	res << y << '-' << m << '-' << d;
	date = res.str();
}

double	exchange( std::map< std::string, double>& map, std::string date, double value )
{
	double	ratio;

	bool	go = 1;
	while ( go )
	{
		try {
			ratio = map[date];
			go = 0;
		} catch ( std::exception &e )
		{
			decrementDate( date );
		}
	}
	return ( value * ratio );
}

void	inputExecutor( const std::string& fn, std::map< std::string, double>& map )
{
	std::ifstream file( fn.c_str() );
	if ( !file )
		throw BitcoinExchange::BadFileNameException();

	std::string	line, date, value;

	while ( std::getline( file, line ) )
	{
		if ( line.empty() || line == "date | value" )
			continue;
		if ( line.find( '|' ) != 11 || line.at(12) != ' ' || line.at(10) != ' ' )
		{
			std::cout << "Error: bad format.\n";
			continue;
		}
		date = line.substr(0, 10);
		if ( !isValidDate( date ) )
		{
			std::cout << "Error: bad input => " << date << std::endl;;
			continue;
		}
		value = line.substr( 13 );
		std::stringstream	tmp_ss( value );
		double			val_d;
		tmp_ss >> val_d;
		if ( tmp_ss.fail() || val_d > INT_MAX || val_d < 0 )
		{
			if ( tmp_ss.fail() )
				std::cout << "Error whilst parsing line.";
			else if ( val_d > INT_MAX )
				std::cout << "Error: too large a number.";
			else
				std::cout << "Error: negative number.";
			std::cout << std::endl;
			continue;
		}
		
		std::cout << date << " => " << value << " = " << exchange( map, date, val_d) << std::endl;
	}
}

BitcoinExchange::BitcoinExchange( void ){}

BitcoinExchange::~BitcoinExchange( void ){}

BitcoinExchange::BitcoinExchange( const std::string& db_fn )
{
	parserDB( db_fn, this->database );
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other )
{
	this->database = other.database;
}

BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& other )
{
	this->database = other.database;
	return ( *this );
}

void	BitcoinExchange::execute_file( const std::string& fn )
{
	inputExecutor(  fn, this->database );
}

const char*	BitcoinExchange::BadFileNameException::what( void ) const throw()
{
	return ( "Error: could not open file" );
}

BitcoinExchange::BadFormatException::~BadFormatException() throw(){}

BitcoinExchange::BadFormatException::BadFormatException( const char* err )
{
	std::string e = "Error: ";
	std::string err_s = err;
	e += err;
	_err = e.c_str();
}

const char*	BitcoinExchange::BadFormatException::what( void ) const throw()
{
	return ( _err.c_str() );
}
