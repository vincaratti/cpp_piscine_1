/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:43:18 by vcaratti          #+#    #+#             */
/*   Updated: 2025/10/27 12:54:51 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string		_target;
	static const int	_req_sign_scf = 145;
	static const int	_req_exec_scf = 137;

public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( const ShrubberyCreationForm& other );
	~ShrubberyCreationForm( void );

	ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& other );

	std::string	getTarget( void ) const;

	void	execute( Bureaucrat const & executor ) const;	
};

#endif
