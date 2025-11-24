/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:43:18 by vcaratti          #+#    #+#             */
/*   Updated: 2025/10/27 12:53:46 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <stdlib.h>
#include <time.h>

class RobotomyRequestForm : public AForm
{
private:
	std::string		_target;
	static const int	_req_sign_rrf = 72;
	static const int	_req_exec_rrf = 45;

public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( const RobotomyRequestForm& other );
	~RobotomyRequestForm( void );

	RobotomyRequestForm&	operator=( const RobotomyRequestForm& other );

	std::string	getTarget( void ) const;

	void	execute( Bureaucrat const & executor ) const;	
};

#endif
