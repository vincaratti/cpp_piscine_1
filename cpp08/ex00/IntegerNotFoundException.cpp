/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntegerNotFoundException.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:28:46 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/05 10:32:58 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IntegerNotFoundException.hpp"

const char*	IntegerNotFoundException::what() const throw()
	{ return ( "Integer not found." ); }
