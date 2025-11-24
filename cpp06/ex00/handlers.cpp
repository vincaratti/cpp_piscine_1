/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:18:46 by vcaratti          #+#    #+#             */
/*   Updated: 2025/11/21 11:19:16 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.hpp"

void	handleChar( std::string& str )
{
	char	c = str[0];
	int	i = (int)c;
	float	f = i;
	double	d = i;

	std::cout <<	"char: " << c << std::endl <<
			"int: " << i << std::endl <<
			"float: " << f << "f" << std::endl <<
			"double: " << d << std::endl ;
}

void	handleInt( std::string& str )
{
	double	d = std::atof(str.c_str());
	float	f = d;
	int	i = d;
	
	if ( i > 32 && i < 126 )
		std::cout << "char: " << (char)i << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout <<	"int: " << i << std::endl <<
			"float: " << f << "f" << std::endl <<
			"double: " << d << std::endl ;
}

void	handleFloat( std::string& str )
{
	double	d = std::atof(str.c_str());
	float	f = d;
	int	i = d;
	
	if ( i > 32 && i < 126 )
		std::cout << "char: " << (char)i << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout <<	"int: " << i << std::endl <<
			"float: "  << f << "f" << std::endl <<
			"double: " << d << std::endl ;
}

void	handleDouble( std::string& str )
{
	double	d = std::atof(str.c_str());
	float	f = d;
	int	i = d;
	
	if ( i > 32 && i < 126 )
		std::cout << "char: " << (char)i << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout <<	"int: " << i << std::endl <<
			"float: " << f << "f" << std::endl <<
			"double: " << d << std::endl ;
}

void	handlePseudo( std::string& str )
{
	std::cout <<	"char: impossible" << std::endl <<
			"int: impossible" << std::endl <<
			"float: " << str << "f" << std::endl <<
			"double: " << str << std::endl ;	
}

void	handleError( std::string& str )
{
	std::cout<<"Input does not make sense: " << str << std::endl;
}
