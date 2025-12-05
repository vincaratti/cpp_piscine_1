/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntegerNotFoundException.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:28:46 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/05 10:34:28 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

class IntegerNotFoundException : public std::exception
{
public:
	virtual const char* what() const throw();
};
