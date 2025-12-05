/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:18:46 by vcaratti          #+#    #+#             */
/*   Updated: 2025/11/24 12:44:31 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.hpp"
#include "predicates.hpp"

void	handleChar( std::string& str, std::ostream& stream )
{
	char	c = str[0];
	int	i = c;
	float	f = c;
	double	d = c;

	stream <<	"char: " << c << std::endl <<
			"int: " << i << std::endl <<
			"float: " << f << "f" << std::endl <<
			"double: " << d << std::endl ;
}

void	handleInt( std::string& str, std::ostream& stream )
{
	int	i = std::atoi( str.c_str() );
	float	f = i;
	double	d = i;
	char	c = static_cast<char>(i);

	if ( isDisplayable(c) )
		stream << "char: " << c << std::endl;
	else
		stream << "char: Non displayable" << std::endl;
	stream <<	"int: " << i << std::endl <<
			"float: " << f << "f" << std::endl <<
			"double: " << d << std::endl ;
}

void	handleFloat( std::string& str, std::ostream& stream )
{
	float	f = static_cast<float>(std::atof(str.c_str()));
	double	d = f;
	int	i = static_cast<int>(f);
	char	c = static_cast<char>(f);
	
	if ( isDisplayable(c) )
		stream << "char: " << c << std::endl;
	else
		stream << "char: Non displayable" << std::endl;
	stream <<	"int: " << i << std::endl <<
			"float: "  << f << "f" << std::endl <<
			"double: " << d << std::endl ;
}

void	handleDouble( std::string& str, std::ostream& stream )
{
	double	d = std::atof(str.c_str());
	float	f = static_cast<float>(d);
	int	i = static_cast<int>(d);
	char	c = static_cast<char>(d);
	
	if ( isDisplayable(c) )
		stream << "char: " << c << std::endl;
	else
		stream << "char: Non displayable" << std::endl;
	stream <<	"int: " << i << std::endl <<
			"float: " << f << "f" << std::endl <<
			"double: " << d << std::endl ;
}

void	handlePseudo( std::string& str, std::ostream& stream )
{
	double	d = std::atof( str.c_str() );
	float	f = static_cast<float>(d);

	stream <<	"char: impossible" << std::endl <<
			"int: impossible" << std::endl <<
			"float: " << f << "f" << std::endl <<
			"double: " << d << std::endl ;	
}

void	handleError( std::string& str, std::ostream& stream )
{
	stream<< "Input \""<< str <<"\" is not valid." << std::endl;
}
