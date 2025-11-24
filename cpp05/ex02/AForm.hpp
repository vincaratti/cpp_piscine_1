/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:43:18 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/26 13:38:17 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool			_signed;
	const int		_req_sign;
	const int		_req_exec;
public:
	AForm( void );
	AForm( std::string name, int req_sign, int req_exec );
	AForm( const AForm& other );
	virtual ~AForm( void );

	AForm&	operator=( const AForm& other );

	std::string	getName( void ) const;
	bool		getSigned( void ) const;
	int		getReqSign( void ) const;
	int		getReqExec( void ) const;

	void	beSigned( Bureaucrat& bureaucrat );
	virtual void	execute( Bureaucrat const & executor ) const = 0;
	
	void	checkExec( Bureaucrat const & executor ) const;

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class UnsignedFormException : public std::exception
	{
		virtual const char* what() const throw();
	};

};

std::ostream&	operator<<( std::ostream& output, const AForm& form );

#endif
