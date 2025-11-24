/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:43:18 by vcaratti          #+#    #+#             */
/*   Updated: 2025/06/24 14:49:56 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
#define __FORM_HPP__

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool			_signed;
	const int		_req_sign;
	const int		_req_exec;
public:
	Form( void );
	Form( std::string name, int req_sign, int req_exec );
	Form( const Form& other );
	~Form( void );

	Form&	operator=( const Form& other );

	std::string	getName( void ) const;
	bool		getSigned( void ) const;
	int		getReqSign( void ) const;
	int		getReqExec( void ) const;

	void	beSigned( Bureaucrat& bureaucrat );
	
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream&	operator<<( std::ostream& output, const Form& form );

#endif
