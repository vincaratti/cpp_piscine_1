/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:43:18 by vcaratti          #+#    #+#             */
/*   Updated: 2025/10/27 12:56:10 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ):
				AForm( "ShrubberyCreationForm", _req_sign_scf, _req_exec_scf ),
				_target( "Average Joe's house" )
				{}
ShrubberyCreationForm::ShrubberyCreationForm( std::string target ):
				AForm( "ShrubberyCreationForm", _req_sign_scf, _req_exec_scf ),
				_target( target )
				{}
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ):
				AForm( "ShrubberyCreationForm", _req_sign_scf, _req_exec_scf ),
				_target( other.getTarget() )
				{}

ShrubberyCreationForm::~ShrubberyCreationForm( void ){}


ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other )
{
	_target = other.getTarget();
	return ( *this );
}

std::string ShrubberyCreationForm::getTarget( void ) const
{
	return ( this->_target );
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	this->checkExec( executor );
	std::string	filename = this->_target + "_shrubbery";
	std::ofstream	outf(filename.c_str());
	outf <<	"******************sky**********************---sun*\n";
	outf <<	"********************************************-/||**\n";
	outf <<	"***bird**,**********************************/**|**\n";
	outf <<	"********>D>*************             *************\n";
	outf <<	"*********'**************   nothing   *************\n";
	outf <<	"************************             *************\n";
	outf <<	"**************************************************\n";
	outf <<	"******{}********************************__-___****\n";
	outf <<	"*****{##}***tree***********************{#==###}***\n";
	outf <<	"****{_##_}****************************(#=##==##)**\n";
	outf <<	"******||********************shrubbery*(##=##==#)**\n";
	outf <<	"******||******************************(=###=###)**\n";
	outf.close();
}
