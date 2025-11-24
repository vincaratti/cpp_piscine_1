/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:19:37 by vcaratti          #+#    #+#             */
/*   Updated: 2025/11/21 11:23:11 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "includes.hpp"

void	handleChar( std::string& str );
void	handleInt( std::string& str );
void	handleFloat( std::string& str );
void	handleDouble( std::string& str );
void	handlePseudo( std::string& str );
void	handleError( std::string& str );
