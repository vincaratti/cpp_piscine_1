/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:15:59 by vcaratti          #+#    #+#             */
/*   Updated: 2025/11/21 11:23:36 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "includes.hpp"

bool	isPseudo( const std::string& str );
bool	isInt( const std::string& str );
bool	isDouble( const std::string& str );
bool	isFloat( const std::string& str );
bool	isChar( const std::string& str );
